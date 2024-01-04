#include"Head.h"
void xuatSanPham(SANPHAM a)
{
	cout  << a.masp;
	cout << setw(30) << a.tensp;
	cout << setw(30) << a.gia;
	cout << setw(30) << a.soluong << endl;
}
void xuatdsSanPham(DANHSACH ds)
{
	cout << "Ma SP" << setw(30) << "Ten SP" << setw(30) << "Don Gia" << setw(30) << "Ton Kho\n";
	for (int i = 0; i < ds.n; i++)
	{
		xuatSanPham(ds.data[i]);
	}
}

void ThemSanPham(SANPHAM& a, DANHSACH& b)
{
	cin.ignore();
	cout << "\nNhap ma san pham: ";
	cin.getline(a.masp, 10);
	chuanhoama(a);
	if (timma(b, a.masp) == 2)
		return;
	else
	{
		while (timma(b, a.masp) == 0)
		{
			cout << "\nNhap ma san pham: ";
			cin.getline(a.masp, 10);
			chuanhoama(a);
		}
		cout << "\nNhap ten san pham: ";
		cin.getline(a.tensp, 10);
		chuanhoaten(a);
		if (timten(b, a.tensp) == 2)
			return;
		else
		{
			while (timten(b, a.tensp) == 0)
			{
				cout << "\nNhap ten san pham: ";
				cin.getline(a.tensp, 20);
				chuanhoaten(a);
			}
			cout << "\nNhap gia san pham(0 thoat): "; cin >> a.gia;
			if (a.gia == 0)
				return;
			else
			{
				while (a.gia < 0)
				{
					cout << "\nNhap gia san pham(0 thoat): "; cin >> a.gia;
				}
				cout << "\nNhap so luong san pham(0 thoat): "; cin >> a.soluong;
				if (a.soluong == 0)
					return;
				while (a.soluong < 0)
				{
					cout << "\nNhap gia san pham(0 thoat): "; cin >> a.soluong;
				}
			}
		}
		b.data[b.n] = a;
		b.n++;
	}
	cout << "Them san pham moi thanh cong!\n";
}
void chuoiVietHoaDauDong(char* str)
{
	// Viết hoa ký tự đầu mỗi từ
	for (int i = 0; i < strlen(str); i++)
	{
		if (i == 0 || str[i - 1] == ' ')
		{
			str[i] = toupper(str[i]);
		}
		else
		{
			str[i] = tolower(str[i]);
		}
	}
}

void chuanHoaChuoi(char* str)
{
	int len = strlen(str);
	int i = 0, j = -1;
	while (++j < len && str[j] == ' ');
		if (j == len)
		{
			str[0] = '\0';
		}
		else
		{
			if (j > 0)
			{
				while (str[j])
				{
					str[i++] = str[j++];
				}
				str[i] = '\0';
			}
			i = 0;
			j = -1;

			while (str[++j])
			{
				if (str[j] != ' ')
				{
					str[i++] = str[j];
				}
				else if (str[j + 1] != ' ')
				{
					str[i++] = ' ';
				}
			}
			str[i] = '\0';
		}
}

void chuanhoaten(SANPHAM& a)
{
	chuanHoaChuoi(a.tensp);
	chuoiVietHoaDauDong(a.tensp);
}
void chuanhoama(SANPHAM& a)
{
	chuanHoaChuoi(a.masp);
	chuoiVietHoaDauDong(a.masp);
}

void sapxepSP(DANHSACH& ds)
{
	SANPHAM temp;
	for (int i = 0; i < ds.n - 1; i++)
		for (int j = i + 1; j < ds.n; j++)
			if (ds.data[i].soluong > ds.data[j].soluong)
			{
				temp = ds.data[i];
				ds.data[i] = ds.data[j];
				ds.data[j] = temp;
			}
	xuatdsSanPham(ds);
}
//ghi san pham vo file
void ghifile(const char* tenfile, DANHSACH& a)
{
	FILE* f = fopen(tenfile, "wt");
	fprintf_s(f, "%d", a.n);
	for (int i = 0; i < a.n; i++)
	{
		fprintf_s(f, "\n%s %s %d %d", a.data[i].masp, a.data[i].tensp,
			a.data[i].gia, a.data[i].soluong);
	}
	fclose(f);
}
void docfile(const char* tenfile, DANHSACH& a)
{
	FILE* f;
	fopen_s(&f, tenfile, "rt");
	if (f == NULL)
		return;
	fscanf_s(f, "%d", &a.n);
	for (int i = 0; i < a.n; i++)
	{
		fscanf(f, "\n%s\n %s \n%d \n%d", &a.data[i].masp, &a.data[i].tensp, 
			&a.data[i].gia, &a.data[i].soluong);
	}
	fclose(f);
}
void xoaSPTheoViTri(DANHSACH& ds, int vitri)
{
	for (int i = vitri + 1; i < ds.n; i++)
		ds.data[i - 1] = ds.data[i];//dời các phần tử sau vitri xóa lên trước 1 đơn vị 
	ds.n--; // sau xóa -1 phần tử 
}
void xoaSPTheoMa(DANHSACH& ds, const char* maSP)
{
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.data[i].masp, maSP) == 0)
		{
			xoaSPTheoViTri(ds, i);
			cout << "Da xoa san pham co ma " << maSP << " khoi danh sach!\n";
			return;
		}
	}
	cout << "Khong tim thay san pham co ma " << maSP << " trong danh sach!\n";
}
void sapxepSPtheoten(DANHSACH& ds)
{
	SANPHAM temp;
	for (int i = 0; i < ds.n - 1; i++)
		for (int j = i + 1; j < ds.n; j++)
			if (strcmp(ds.data[i].tensp, ds.data[j].tensp) > 0)
			{
				temp = ds.data[i];
				ds.data[i] = ds.data[j];
				ds.data[j] = temp;
			}
	xuatdsSanPham(ds);
}
void suatenSP(DANHSACH& ds)
{
	SANPHAM a;
	do
	{
		cin.ignore();
		cout << "\nNhap ma san pham can sua ten(enter de thoat!): ";
		cin.getline(a.masp, 10);
		chuanhoama(a);
		if (a.masp == " ")
			return;
		else
		{
			for (int i = 0;i < ds.n;i++)
			{
				if (strcmp(a.masp, ds.data[i].masp) == 0)
				{
					cout << "\nNhap ten moi: ";
					cin.getline(a.tensp, 20);
					chuanhoaten(a);
					if ( a.tensp == "")
						return;
					else
					{
						while (strcmp(a.tensp,ds.data[i].tensp) == 0)
						{
							cout << "\nTen san pham da ton tai(Nhap lai): ";
							cin.getline(a.tensp, 20);
							chuanhoaten(a);	
						}
						strcpy(ds.data[i].tensp, a.tensp);
						ghifile("sanpham.txt", ds);
					}
				}
				
			}
		}
		
	} while (timma(ds, a.masp) != 2);
}
void suaGiaSP(DANHSACH& ds)
{
	SANPHAM a;
	do
	{
		cin.ignore();
		cout << "\nNhap ma san pham can sua gia(enter de thoat!): ";
		cin.getline(a.masp, 10);
		chuanhoama(a);
		if (a.masp == " ")
			return;
		else
		{
			for (int i = 0;i < ds.n;i++)
			{
				if (strcmp(a.masp, ds.data[i].masp) == 0)
				{
					cout << "\nNhap gia moi(nhap 0 thoat): ";
					cin >> a.gia;
					if (a.gia == 0)
						return;
					while (a.gia < 0)
					{
						cout << "\nNhap lai gia: ";
						cin >> a.gia;
					}
					ds.data[i].gia = a.gia;
					ghifile("sanpham.txt", ds);
				}
				
			}
		}
	} while (timma(ds, a.masp) != 2);
}
void suaSLSP(DANHSACH& ds)
{
	SANPHAM a;
	do
	{
		cin.ignore();
		cout << "\nNhap ma san pham can sua so luong(enter de thoat!): ";
		cin.getline(a.masp, 10);
		chuanhoama(a);
		if (a.masp == " ")
			return;
		else
		{
			for (int i = 0;i < ds.n;i++)
			{
				if (strcmp(a.masp, ds.data[i].masp) == 0)
				{
					cout << "\nNhap lai so luong(0 thoat): ";
					cin >> a.soluong;
					if (a.soluong == 0)
						return;
					while (a.soluong < 0)
					{
						cout << "\nNhap lai so luong: ";
						cin >> a.soluong;
					}
					ds.data[i].soluong = a.soluong;
					ghifile("sanpham.txt", ds);
				}
				

			}
		}
	} while (timma(ds, a.masp) != 2);
}

int timma(DANHSACH& a, char ma[])
{
	
	for (int i = 0;i < a.n;i++)
	{
		if (strcmp(ma, a.data[i].masp) == 0)
			return 0;
		if (strcmp(ma, "") == 0)
		{
			ma = NULL;
			return 2;
		}
	}
	return -1;
}
int timten(DANHSACH& a, char ten[])
{

	for (int i = 0;i < a.n;i++)
	{
		if (strcmp(ten, a.data[i].tensp) == 0)
			return 0;
		if (strcmp(ten, "") == 0)
		{
			ten = NULL;
			return 2;
		}

	}
	return -1;
}
//QUẢN LÝ ĐƠN HÀNG

//GHI TÊN KHÁCH HÀNG VÀ NGÀY MUA
void thongtindonhang(donhang& dh)
{
	cout << "Nhap ten khach hang: ";
	cin.getline(dh.tenKh, 20);
	
}
void danhSachMua(DANHSACH& ds)
{
	SANPHAM* b = new SANPHAM();
	DONHANG dh;
	DANHSACH a;
	int m = 0;	
	while (true)
	{
		cin.ignore();
		cout << "\nNhap ma san pham can mua: ";cin.getline(b->masp, 10);
		if (timma(ds, b->masp) == 2)
			break;
		else
		{
			for (int i = 0;i < ds.n;i++)
				if (strcmp(b->masp, ds.data[i].masp)==0)
				{
					cout << "\nNhap so luong: ";
						cin >> b->soluong;
						if (b->soluong<0||b->soluong > ds.data[i].soluong)
						{
							cout << "\nSo luong nhap khong dung. Vui long nhap lai.\n";
						}
						else
						{
							a.data[m] = ds.data[i];
							a.data[m].soluong = b->soluong;
							ds.data[i].soluong -= b->soluong;
							ghifile("sanpham.txt", ds);
							m++;
							break;
						}
				}
		}
	}
	if (m != 0)
	{
		thongtindonhang(dh);
		ghithongtinkh(dh);
		ghidon("donhang.txt",a, m);
		Danhsachdon("danhsachdon.txt", a, m);
		
	}
	else
		return;
}
void timSPtheoma(DANHSACH& a)
{
	SANPHAM b;
	cin.ignore();
	cout << "\nNhap ten san pham can tim: ";
	cin.getline(b.masp, 10);
	for (int i = 0;i < a.n;i++)
	{
		if (strcmp(b.masp, a.data[i].masp) == 0)
		{
			cout << "Ma SP\tTen SP\tDon Gia\tTon Kho " << endl;
			cout << a.data[i].masp << "\t" << a.data[i].tensp << "\t" << a.data[i].gia << "\t" << a.data[i].soluong;
		}

	}
}

void ghidon(const char* file, DANHSACH& a, int& m)
{
	FILE* f = fopen(file, "wt");
	fprintf_s(f, "%d", m);
	for (int i = 0; i < m; i++)
	{
		fprintf_s(f, "\n%s %s %d %d", a.data[i].masp, a.data[i].tensp,
			a.data[i].gia, a.data[i].soluong);
	}
	fclose(f);
}
void Danhsachdon(const char* file, DANHSACH& a, int& m)
{
	FILE* f = fopen(file, "a+");
	fprintf_s(f, "%d", m);
	for (int i = 0; i < m; i++)
	{
		fprintf_s(f, "\n%s %s %d %d", a.data[i].masp, a.data[i].tensp,
			a.data[i].gia, a.data[i].soluong);
	}
	fclose(f);
}
void xuatdsdon()
{
	FILE* f = fopen("danhsachdon.txt", "rt");
	if (f == NULL)
		return;
	char tam[1000];
	while (!feof(f))
	{
		fgets(tam, 100, f);
		printf("%s", tam);
	}
	fclose(f);
}
void ghithongtinkh( DONHANG& dh)
{
	float gia = 0.0;
	FILE* f = fopen("thongtin.txt", "wt");
	fprintf_s(f, "Ngay mua:%d/%d/%d, khach hang: %s", dh.t->tm_mday, dh.t->tm_mon + 1,
		dh.t->tm_year + 1900, dh.tenKh);
	fclose(f);
}
void docthongtinkh(const char* file,DONHANG dh)
{
	FILE* f = fopen(file,"rt");
	if (f == NULL)
		return;
	char tam[100];
	while (!feof(f))
	{
		fgets(tam, 100, f);
		printf("%s", tam);
	}
	fclose(f);
}
void tongtien(DANHSACH ds)
{
	float sum = 0;
	for (int i = 0;i < ds.n;i++)
	{
		sum +=float(ds.data[i].gia) * ds.data[i].soluong;
	}
	cout << "\nTong tien: " << sum;
}
void xuatdsSanPhamMua(DANHSACH ds)
{
	cout << "Ma SP" << setw(30) << "Ten SP" << setw(30) << "Don Gia" << setw(30) << "So Luong\n";
	for (int i = 0; i < ds.n; i++)
	{
		xuatSanPham(ds.data[i]);
	}
}
void ghidontrong()
{
	FILE* f = fopen("thongtin.txt", "wt");
	fprintf_s(f, "%s", " ");
	fclose(f);
}
//-------------------ADMIN--------------------
void themAdmin(ADMIN& ad, DSADMIN& ds)
{
	cin.ignore();
	cout << "\nNhap tai khoan:";
	cin.getline(ad.taikhoan, 20);
	if (kttaikhoan(ds,ad.taikhoan) == 2)
		return;
	else
	{
		while (kttaikhoan(ds,ad.taikhoan) == 0)
		{
			cout << "\nNhap lai tai khoan: ";
			cin.getline(ad.taikhoan, 20);
		}
		cout << "\nNhap mat khau: ";
		cin.getline(ad.matkhau, 20);
		if (strcmp(ad.matkhau, "") == 0)
			return;
		ds.data[ds.n] = ad;
		ds.n++;
		cout << "\nThem thanh cong!\n";
	}
	ghiAdmin("admin.txt", ds);
}
int kttaikhoan(DSADMIN ds,char tk[])
{
	for (int i = 0;i < ds.n;i++)
	{
		if (strcmp(ds.data[i].taikhoan, tk) == 0)
			return 0;
		if (strcmp(tk, " ") == 0)
			return 2;
	}
	return -1;
}
void xoaAdminVitri(DSADMIN& ds, int vitri)
{
	for (int i = vitri + 1; i < ds.n; i++)
		ds.data[i - 1] = ds.data[i];//dời các phần tử sau vitri xóa lên trước 1 đơn vị 
	ds.n--; // sau xóa -1 phần tử 
}
void xoaAdTheoTK(DSADMIN& ds)
{
	char tk[20];
	cin.ignore();
	cout << "\nNhap tai khoan can xoa: ";
	cin.getline(tk, 20);
	for (int i = 0; i < ds.n; i++)
	{
		if (strcmp(ds.data[i].taikhoan, tk) == 0)
		{
			xoaAdminVitri(ds, i);
			cout << "Da xoa admin co tai khoan " << tk << " khoi danh sach!\n";
			return;
		}
	}
	cout << "Khong tim thay admin co tai khoan " << tk << " trong danh sach!\n";
}
void ghiAdmin(const char* tenfile, DSADMIN& ds)
{
	FILE* f = fopen(tenfile, "wt");
	fprintf_s(f, "%d", ds.n);
	for (int i = 0; i < ds.n; i++)
	{
		fprintf_s(f, "\n%s %s", ds.data[i].taikhoan,ds.data[i].matkhau);
	}
	fclose(f);
}
void docfileAD(const char* tenfile, DSADMIN &ds)
{
	FILE* f;
	fopen_s(&f, tenfile, "rt");
	if (f == NULL)
		return;
	fscanf_s(f, "%d", &ds.n);
	for (int i = 0; i < ds.n; i++)
	{
		fscanf(f, "\n%s %s", &ds.data[i].taikhoan, &ds.data[i].matkhau);
	}
	fclose(f);
}
bool kiemtratk(char tk[], char mk[])
{
	DSADMIN a;
	docfileAD("admin.txt", a);
	for (int i = 0;i < a.n;i++)
	{
		if (strcmp(tk, a.data[i].taikhoan) == 0 && strcmp(mk, a.data[i].matkhau) == 0)
			return true;
	}
	return false;
}

// menu lua chon
void menu()
{
	//admin
	ADMIN ad;
	DSADMIN dsad;
	//san pham
	DANHSACH dssp;
	DANHSACH a;
	SANPHAM sp;
	//donnhang
	DONHANG dh,b;
	//doc file
	docfileAD("admin.txt", dsad);
	docfile("sanpham.txt", dssp);
	docfile("donhang.txt", a);
	//-----------------------
	char tk[20];
	char mk[20];
	char masp[10];
	char chon [2];
	int menu1 = 0;
	int menu2 = 0;
	//----------------------
	do
	{
		cout << "1.ADMIN\n";
		cout << "2.Nguoi Dung\n";
		cout << "3.Thoat Chuong Trinh";
		
		cout << "\nChon yeu cau: ";
		cin.getline(chon,3);
		if (strcmp(chon,"1")==0)
		{
			cout << "\nNhap Tai Khoan: ";
			cin.getline(tk, 20);
			cout << "\nNhap mat khau: ";
			cin.getline(mk, 20);
			if (kiemtratk(tk, mk) == true)
			{
				do
				{
					cout << "----------------MENU-------------";
					cout << "\n1.Them admin";
					cout << "\n2.Xoa admin";
					cout << "\n3.Xem danh sach san pham";
					cout << "\n4.Them san pham";
					cout << "\n5.Sua ten san pham";
					cout << "\n6.Sua gia san pham";
					cout << "\n7.Sua so luong san pham";
					cout << "\n8.Xoa san pham";					
					cout << "\n9.Quay lai trang chu:";
					cout << "\n10.Thoat !";
					cout << "\nNhap lua chon:";
					cin >> menu1;
					switch (menu1)
					{
					case 1:
					{
						themAdmin(ad, dsad);
						
						break;
					}
					case 2:
					{
						xoaAdTheoTK(dsad);
						ghiAdmin("admin.txt", dsad);
						break;
					}
					case 3:
					{
						xuatdsSanPham(dssp);
						break;
					}
					case 4:
					{
						ThemSanPham(sp, dssp);
						sapxepSPtheoten(dssp);
						ghifile("sanpham.txt", dssp);
						break;
					}
					case 5:
					{
						suatenSP(dssp);
						ghifile("sanpham.txt", dssp);
						break;
					}
					case 6:
					{
						suaGiaSP(dssp);
						ghifile("sanpham.txt", dssp);
						break;
					}
					case 7:
					{
						suaSLSP(dssp);
						ghifile("sanpham.txt", dssp);
						break;
					}
					case 8:
					{
						cin.ignore();
						cout << "\nNhap ma san pham can xoa:";
						cin.getline(masp, 10);
						xoaSPTheoMa(dssp, masp);
						ghifile("sanpham.txt", dssp);
						break;
					}				
					case 9:
						menu();
						break;
					case 10:
						cout << "Chuong trinh ket thuc.\n";
						return;
					default:
						cout << "Lua chon khong hop le. Vui long thu lai!.\n";
					}
				} while (true);
			}

		}
		else if (strcmp(chon, "2") == 0)
		{
			do
			{
				cout << "\n------------ MENU ------------\n";
				cout << "1. Xem Danh Sach San Pham\n";
				cout << "2.Tim san pham theo ma:\n";
				cout << "3. Mua hang\n";
				cout << "4.Xem don hang\n";
				cout << "5.Huy don \n";
				cout << "6.Danh sach don hang\n";
				cout << "7.Thoat !";
				cout << "\nNhap lua chon:";
				cin >> menu2;
				switch (menu2)
				{
				case 1:
				{
					xuatdsSanPham(dssp);
					break;
				}
				case 2:
				{
					timSPtheoma(dssp);
					break;
				}
				case 3:
				{
					danhSachMua(dssp);
					break;
				}
				case 4:
				{
					docthongtinkh("thongtin.txt",dh);
					cout << endl;
					docfile("donhang.txt", a);
					xuatdsSanPhamMua(a);
					//cout << endl;
					tongtien(a);
					break;
				}
				case 5:
				{
					int m = 0;
					for (int i = 0;i < a.n;i++)
						for (int j = 0;j < dssp.n;j++)
						{
							if (strcmp(a.data[i].masp, dssp.data[j].masp) == 0)
							{
								dssp.data[j].soluong += a.data[i].soluong;
								ghifile("sanpham.txt", dssp);
							}
						}
					cout << "\nHuy don thanh cong\n";
					cin.ignore();
					ghidon("donhang.txt", a, m);
					ghidontrong();
					break;
				}
				case 6:
				{
					xuatdsdon();
					break;
				}
				case 7:
				{
					cout << "Chuong trinh ket thuc.";
					return;
				}
				default:
					cout << "Lua chon khong hop le. Vui long thu lai!.\n";
				}
			} while (true);
		}
		else if(strcmp(chon, "3") == 0)
			break;
		else
		{
			cout << "khong dung";
			break;
		}
	} while (kiemtratk(tk, mk) == false);
}