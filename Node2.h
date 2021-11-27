#pragma once
#include "Sach.h"
#include "MuonSach.h"
class Node2
{
public:
	Sach book;
	MuonSach ms;
	Node2* next;
	Node2* nextofMS;
	Node2();
	Node2(Sach book);
	Node2(MuonSach ms);
	~Node2();
};

