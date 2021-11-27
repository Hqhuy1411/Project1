#include "MuonSach.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


MuonSach::MuonSach() {
	this->tenSach = "";
	this->tacGia = "";
	this->ngayMuon = "";
	this->ngayTra = "";
}
MuonSach::MuonSach(string ten, string tg, string nm, string nt)
{
	this->tenSach = ten;
	this->tacGia = tg;
	this->ngayMuon = nm;
	this->ngayTra =nt;
}
MuonSach::MuonSach(MuonSach& x) {
	this->tenSach = x.tenSach;
	this->tacGia = x.tacGia;
	this->ngayMuon = x.ngayMuon;
	this->ngayTra = x.ngayTra;
}
void MuonSach::Nhap() {
	cin.ignore();
	cout << "Nhap ten Sach :";  fflush(stdin); getline(cin, this->tenSach);
	cout << "Nhap Tac Gia :";  fflush(stdin); getline(cin, this->tacGia);
	cout << "Nhap ngay muon :"; fflush(stdin); getline(cin, this->ngayMuon);
	cout << "Nhap ngay tra :";  fflush(stdin); getline(cin, this->ngayTra);

}
void MuonSach::Xuat() {
	cout << " Ho va Ten :	" << tenSach << endl;
	cout << " Tac Gia:	" << tacGia << endl;
	cout << " Ngay Muon :" << ngayMuon << endl;
	cout << " Ngay Tre :" << ngayTra << endl;
}
void MuonSach::XuatSach(){
	cout << " Ngay Muon :" << ngayMuon << endl;
	cout << " Ngay Tre :" << ngayTra << endl;
}	
void MuonSach::DocFile(ifstream& in) {
	getline(in, this->tenSach);
	getline(in, this->tacGia);
	fflush(stdin);
	getline(in, this->ngayMuon);
	fflush(stdin);
	getline(in, this->ngayTra);
}
void MuonSach::GhiFile(ofstream& os) {
	os << "\n";
	os << this->tenSach << endl;
	os << this->tacGia << endl;
	os << this->ngayMuon << endl; 
	os << ngayTra << endl;
}
istream& operator >> (istream& is, MuonSach& x) {
	cin.ignore();
	cout << "Nhap ten Sach :";  fflush(stdin); getline(is, x.tenSach);
	cout << "Nhap Tac Gia :";  fflush(stdin);  getline(is, x.tacGia);
	cout << "Nhap ngay muon :"; fflush(stdin); getline(is, x.ngayMuon);
	cout << "Nhap ngay tra :";  fflush(stdin); getline(is, x.ngayTra);
	return is;
}
//ostream& operator <<(ostream& os, const MuonSach&x) {
//	os << "\n";
//	os << "Hello"; os << x.tenSach << endl;
//	cout << "Hello"; os << x.tacGia << endl;
//	cout << "Hello"; os << x.ngayMuon << endl;
//	cout << "Hello"; os << x.ngayTra << endl;
//	return os;
//}
string MuonSach::getTenSach() {
	return this->tenSach;
}
string MuonSach::getTacGia() {
	return this->tacGia;
}