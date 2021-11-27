#include "Sinhvien.h"
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
Sinhvien::Sinhvien() :DocGia() {

	this->khoa = "";
	this->SDT = "";
	this->CMND = "";
}
Sinhvien::Sinhvien(string lop, string dob, string hoTen, string Id, string account, string password, string khoa, string SDT, string CMND)
	:DocGia(lop, dob, hoTen, Id, account, password) {
	this->khoa = khoa;
	this->SDT = SDT;
	this->CMND = CMND;
}
Sinhvien::Sinhvien(Sinhvien& y) : DocGia(y) {

	this->khoa = khoa;
	this->SDT = SDT;
	this->CMND = CMND;
}
Sinhvien::~Sinhvien() {
}
void Sinhvien::Nhap() {
	DocGia::Nhap();
	cin.ignore();
	cout << "\n Nhap khoa :"; cin >> khoa;
	cout << "\n Nhap CMND :"; cin >> CMND;
	cout << "\n Nhap SDT :"; cin >> SDT;
}
void Sinhvien::Xuat() {
	DocGia::Xuat();
	cout << setw(10) << this->khoa << setw(10) << this->CMND << setw(10) << this->SDT << endl;
}
void Sinhvien::DocFile(ifstream& in) {

	DocGia::DocFile(in); fflush(stdin);
	getline(in, this->khoa); fflush(stdin);
	getline(in, this->CMND); fflush(stdin);
	getline(in, this->SDT);
}
void Sinhvien::GhiFile(ofstream& os) {
	DocGia::GhiFile(os);
	os << this->khoa << endl;
	os << this->CMND << endl;
	os << this->SDT << endl;
	if (DocGia::ds.getSize() != 0) {
		DocGia::ds.display(os);
	}

}
ostream& operator<<(ostream& os, const Sinhvien& x) {
	os << x.khoa << endl;
	os << x.CMND << endl;
	os << x.SDT << endl;
	return os;
}