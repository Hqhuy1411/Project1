#pragma once
#include "HocSinh.h"
#include "SinhVien.h"
#include "DocGia.h"
class Node
{
public:
	
	DocGia* p;
	Node* nextofDG;	
	Node();	
	Sinhvien sv;
	Node(DocGia* x);
	Node(Node& x);
	~Node();
};

