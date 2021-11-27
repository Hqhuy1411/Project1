#pragma once
#include "DocGia.h"
#include <fstream>
#include<iostream>
using namespace	std;
class HocSinh : public DocGia
{
	string truong;
	string SDT;
public:
	HocSinh();
	HocSinh(string lop, string dob, string hoTen, string Id, string account, string password, string truong, string SDT);
	HocSinh(HocSinh& z);
	~HocSinh();
	void Nhap();
	void Xuat();
	void DocFile(ifstream& in);
	void GhiFile(ofstream& os);
};