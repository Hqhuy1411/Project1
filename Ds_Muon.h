#pragma once
#include "Node2.h"
#include "Ds_Sach.h"
using namespace std;
class Ds_Muon 
{
private:
	Node2* head;
	Node2* tail;
	int size;
public :
	Ds_Muon();
	Ds_Muon(Ds_Muon& x);
	const Ds_Muon& operator = (const Ds_Muon& x);
	~Ds_Muon();
	int getSize();
	void Insert(MuonSach p);
	void Remove(string name);
	void display();
	void displaySach(Ds_Sach& x);
	void display(ofstream& out);
	
};

