#pragma once
#include "Node2.h"
class Ds_Sach
{
private :
	Node2* head;	
	Node2* tail;
	int size;
public:
	Ds_Sach();
	Ds_Sach(Ds_Sach& x);
	const Ds_Sach& operator = (const Ds_Sach& x);
	~Ds_Sach();
	int getSize();
	void Insert(Sach p);
	void InsertLast(Sach p);
	void RemoveHead();
	void RemoveLast();
	void RemovebyName(string name);
	void RemovebyTG(string TG);
	void display();
	void display(ofstream& out);
	Sach Search(string TenSach);
	void Update(string tenSach,string tacgia);
	void Update(string tenSach);
	void BooksofTG(string TG);
	string CheckMuon(string TS, string TG);
};

