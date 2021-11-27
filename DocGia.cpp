#include "DocGia.h"
#include<iostream>
#include <string>
#include <iomanip>
using namespace std;
DocGia::DocGia() {
	this->lop = "";
	this->dob = "";
	this->hoTen = "";
	this->Id = "";
	this->account = "";
	this->password = "";
}
DocGia::DocGia(string lop, string dob, string hoTen, string Id, string account, string password)
{
	this->lop = lop;
	this->dob = dob;
	this->hoTen = hoTen;
	this->Id = Id;
	this->account = account;
	this->password = password;
}
DocGia::DocGia(DocGia& x) {
	this->lop = x.lop;
	this->dob = x.dob;
	this->hoTen = x.hoTen;
	this->Id = x.Id;
	this->account = x.account;
	this->password = x.password;
}

DocGia::~DocGia()
{

}
void DocGia::setHoTen(string hoTen) {
	this->hoTen = hoTen;
}
string DocGia::getHoTen() {
	return hoTen;
}
void DocGia::setID(string Id) {
	this->Id = Id;
}
string DocGia::getID() {
	return Id;
}
void DocGia::setTK(string account) {
	this->account = account;
}
string DocGia::getTK() {
	return account;
}
void DocGia::setMK(string password) {
	this->password = password;
}
string DocGia::getMK() {
	return password;
}
void DocGia::setDs(Ds_Muon &p){
	this->ds = p;
}
Ds_Muon DocGia::getDs() {
	return this->ds;
}
void DocGia::setKT(bool kt)
{
	this->KT = kt;
}

bool DocGia::getKT()
{
	return this->KT;
}

void  DocGia::Nhap() {
	//	cin.ignore();
	fflush(stdin);
	cout << "\n nhap ID :"; cin >> Id;
	cout << "\n nhap ho va ten :"; cin >> hoTen;
	cout << "\n nhap lop :"; cin >> lop;
	cout << "\n nhap ngay thang nam sinh :"; cin >> dob;
	cout << "\n nhap tai khoan :"; cin >> account;
	cout << "\n nhap mat khau :"; cin >> password;
}
void DocGia::Xuat() {
	cout << setw(10) << this->Id << setw(15) << this->hoTen << setw(7) << this->lop << setw(10) << this->dob;
	//ds.display();
}
void  DocGia::DocFile(ifstream& in) {
	getline(in, this->Id);
	getline(in, this->hoTen);
	getline(in, this->lop);
	getline(in, this->dob);
	getline(in, this->account);
	getline(in, this->password);

}
void  DocGia::GhiFile(ofstream& os) {
	os << "\n" <<this->Id << endl;
	os << this->hoTen << endl;
	os << this->lop << endl;
	os << this->dob << endl;
	os << this->account << endl;
	os << this->password << endl;
}
ostream& operator<<(ostream& os , const DocGia& x) {
	os << "\n" << x.Id << endl;
	os << x.hoTen << endl;
	os << x.lop << endl;
	os << x.dob << endl;
	os << x.account << endl;
	os << x.password << endl;
	return os;
}