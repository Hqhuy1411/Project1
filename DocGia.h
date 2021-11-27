#pragma once
#include<iostream>
#include <fstream>
#include "Ds_Muon.h"
using namespace std;
class DocGia
{
protected:
	string lop;
	string dob;
	string hoTen;
	string Id;
	string account;
	string password;
	bool KT;
public:
	Ds_Muon ds;
	DocGia();
	//	int getID();
	DocGia(string lop, string dob, string hoTen, string Id, string account, string password);
	DocGia(DocGia& x);
	~DocGia();
	void setHoTen(string hoTen);
	string getHoTen();
	void setID(string Id);
	string getID();
	void setTK(string account);
	string getTK();
	void setMK(string password);
	string getMK();
	void setDs(Ds_Muon &p);
	Ds_Muon getDs();
	void setKT(bool kt);
	bool getKT();
	virtual void Nhap();
	virtual	void Xuat();
	virtual	void DocFile(ifstream& in);
	virtual	void GhiFile(ofstream& os);
	friend ostream& operator<<(ostream&, const DocGia&);
};