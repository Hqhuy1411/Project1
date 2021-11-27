#include "HocSinh.h"
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
HocSinh::HocSinh() {
	this->truong = "";
	this->SDT = "";
}
HocSinh::HocSinh(string lop, string dob, string hoTen, string Id, string account, string password, string truong, string SDT)
	:DocGia(lop, dob, hoTen, Id, account, password) {
	this->truong = truong;
	this->SDT = SDT;
}
HocSinh::HocSinh(HocSinh& z) {
	this->truong = z.truong;
	this->SDT = z.SDT;
}
HocSinh::~HocSinh() {

}
void HocSinh::Nhap() {
	DocGia::Nhap();
	cin.ignore();
	cout << "\n Nhap truong : "; cin >> truong;
	cout << "\n Nhap SDT : "; cin >> SDT;
}
void HocSinh::Xuat() {
	DocGia::Xuat();
	cout << setw(10) << this->truong << setw(10) << this->SDT << endl;
}
void HocSinh::DocFile(ifstream& in) {

	DocGia::DocFile(in);
	fflush(stdin);
	getline(in, this->truong);
	fflush(stdin);
	getline(in, this->SDT);
}
void HocSinh::GhiFile(ofstream& os) {
	DocGia::GhiFile(os);
	os << this->truong << endl;
	os << this->SDT << endl;
	if (DocGia::ds.getSize() != 0) {
		DocGia::ds.display(os);
	}
}