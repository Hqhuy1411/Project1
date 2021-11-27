#pragma once
#include "DocGia.h"
//#include "Ds_Muon.h"
#include<iostream>
using namespace	std;
class Sinhvien : public DocGia
{
private:
	string khoa;
	string SDT;
	string CMND;
public:
	Sinhvien();
	Sinhvien(string lop, string dob, string hoTen, string Id, string account, string password, string khoa, string SDT, string CMND);
	Sinhvien(Sinhvien& y);
	~Sinhvien();
	void Nhap();
	void Xuat();
	void DocFile(ifstream& in);
	void GhiFile(ofstream& os);
	friend ostream& operator<<(ostream&, const Sinhvien&);
};