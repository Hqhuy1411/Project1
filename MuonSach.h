#pragma once
#include <string>
#include "Sach.h"
#include<fstream>
using namespace std;
class MuonSach 
{
private :
	string tenSach;
	string tacGia;
	string ngayMuon;
	string ngayTra;
public:
	MuonSach();
	MuonSach(string ten, string tg, string nm, string nt);
	MuonSach(MuonSach& x);
	void Nhap();
	friend istream& operator >> (istream&, MuonSach&);
	friend ostream& operator <<(ostream&,const MuonSach&);
	string getTenSach();
	string getTacGia();
	void Xuat();
	void XuatSach();
	void DocFile(ifstream& in);
	void GhiFile(ofstream& os);
};

