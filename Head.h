#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<time.h>
#include<iomanip>
using namespace std;

struct sanpham
{
	char masp[10];
	char tensp[20];
	int gia;
	int soluong;
};
typedef sanpham SANPHAM;
struct danhsach
{
	SANPHAM data[100];
	int n=0;
};
typedef danhsach DANHSACH;
struct donhang
{
	char tenKh[20];
	time_t time_now = time(NULL);
	tm* t = localtime(&time_now);
}; typedef donhang DONHANG;
//ADMIN
struct admin
{
	char taikhoan[20];
	char matkhau[20];
};
typedef admin ADMIN;
struct dsadmin
{
	ADMIN data[100];
	int n=0;
};
typedef dsadmin DSADMIN;
//admin
void themAdmin(ADMIN& ad, DSADMIN& ds);
void xoaAdminVitri(DSADMIN& ds, int vitri);
void xoaAdTheoTK(DSADMIN& ds);
void ghiAdmin(const char* tenfile, DSADMIN& ds);
void docfileAD(const char* tenfile, DSADMIN& ds);
int kttaikhoan(DSADMIN ds, char tk[]);
//sanpham
void xuatdsSanPham(DANHSACH ds);
void Danhsachdon(const char* file, DANHSACH& a, int& m);
void xuatdsdon();
void sapxepSP(DANHSACH& ds);
void xoaSPTheoViTri(DANHSACH& ds, int vitri);
void xoaSPTheoMa(DANHSACH& ds, const char* maSP);
void suatenSP(DANHSACH& ds);
void suaGiaSP(DANHSACH& ds);
void suaSLSP(DANHSACH& ds);
void ghifile(const char* tenfile, DANHSACH& a);
void docfile(const char* tenfile, DANHSACH& a);
void sapxepSPtheoten(DANHSACH& ds);
int timma(DANHSACH& a, char ma[]);
int timten(DANHSACH& a, char ten[]);
void timSPtheoma(DANHSACH& a);
void chuanhoaten(SANPHAM& a);
void chuanhoama(SANPHAM& a);
void chuanHoaChuoi(char* str);
void chuoiVietHoaDauDong(char* str);
//Don Hang
void thongtindonhang(donhang& dh);
void danhSachMua(DANHSACH& ds);
void ghidon(const char* file, DANHSACH& ds, int& m);
void ghithongtinkh(DONHANG& dh);
void docthongtinkh(const char* file, DONHANG dh);
void tongtien(DANHSACH ds);
void ghidontrong();
void xuatdsSanPhamMua(DANHSACH ds);
//dang nhap
bool kiemtratk(char tk[], char mk[]);
void menu();
