#include "Sach.h"
#include<iostream>
#include<iomanip>
using namespace std;
Sach::Sach()
{
	this->maSach = "";
	this->tenSach = "";
	this->tacGia = "";
	this->TGXB = "";
	this->trangthai = "";

}
Sach::Sach(string MS, string TS, string TG, string tgxb, string trangthai) {
	this->maSach = MS;
	this->tenSach = TS;
	this->tacGia = TG;
	this->TGXB = tgxb;
	this->trangthai = trangthai;
}
Sach::Sach(const  Sach& p) {
	this->maSach = p.maSach;
	this->tenSach = p.tenSach;
	this->TGXB = p.TGXB;
	this->tacGia = p.tacGia;
	this->trangthai = p.trangthai;
}
string Sach::getTGXB()
{
	return this->TGXB;
}
void Sach::Input()
{
	cin.ignore();
	cout << "\nNhap ma Sach: ";
	getline(cin, maSach);
	fflush(stdin);
	cout << "\nNhap ten Sach: ";
	getline(cin, tenSach);
	fflush(stdin);
	cout << "\nNhap ten TacGia:  :";
	fflush(stdin);
	getline(cin, tacGia);
	cout << "\nThoi gian xuat ban: ";  fflush(stdin);
	getline(cin, TGXB);
	cout << "\nTrang thai cua sach:  ";
	fflush(stdin);
	getline(cin, trangthai);

}
void Sach::setTacGia(string tg) {
	this->tacGia = tg;
}
string Sach::getTacGia() {
	return this->tacGia;
}
void Sach::setTenSach(string tensach) {
	this->tenSach = tensach;

}
string Sach::getTenSach() {
	return this->tenSach;
}
string Sach::getTrangThai() {
	return this->trangthai;
}
string Sach::getMaSach()
{
	return this->maSach;
}
void Sach::setTrangThai(string trangthai) {
	this->trangthai = trangthai;
}

void Sach::Output()
{
	/*cout<<"\n Ma Sach: " <<maSach<<endl;
	cout<<"\n Ho va Ten :	" << tenSach <<endl;
	cout<<"\n Tac Gia:	"<< tacGia <<endl;
	cout<<"\n Thoi Gian Xuat Ban :" << TGXB << endl;
	cout <<"\n Trang Thai :" << trangthai << endl;*/
	cout << setw(10)<< maSach << setw(15) << tenSach << setw(15) << tacGia << setw(15) << TGXB << setw(15) << trangthai << endl;
}
void Sach::ghiFile(ofstream& os) {
	os << this->maSach << endl;
	os << this->tenSach << endl;
	os << this->tacGia << endl;
	os << this->TGXB << endl;
	os << this->trangthai << endl;
}
void Sach::get(ifstream& in) {
	getline(in, this->maSach);
	getline(in, this->tenSach);
	getline(in, this->tacGia);
	getline(in, this->TGXB);
	getline(in, this->trangthai);
}

ostream& operator<<(ostream& os,const Sach& x)
{
	os <<"\n Ma Sach: " <<x.maSach<<endl;
	os <<"\n Ho va Ten :	" << x.tenSach <<endl;
	os <<"\n Tac Gia:	"<< x.tacGia <<endl;
	os <<"\n Thoi Gian Xuat Ban :" << x.TGXB << endl;
	os <<"\n Trang Thai :" << x.trangthai << endl;
	return os;
}
istream& operator >>(istream& is, Sach& x) {
	cin.ignore();
	cout << "\nNhap ma Sach: ";
	getline(is, x.maSach);
	fflush(stdin);
	cout << "\nNhap ten Sach: ";
	getline(is, x.tenSach);
	fflush(stdin);
	cout << "\nNhap ten TacGia:  :";
	fflush(stdin);
	getline(is, x.tacGia);
	cout << "\nThoi gian xuat ban: ";  fflush(stdin);
	getline(is, x.TGXB);
	cout << "\nTrang thai cua sach:  ";
	fflush(stdin);
	getline(is, x.trangthai);
	return is;
}