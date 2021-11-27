#include "Node2.h"
Node2::Node2() {
	
	this->next = NULL;
	this->nextofMS = NULL;

}
Node2::Node2(Sach book) {
	this->book = book;
	next = NULL;
}
Node2::Node2(MuonSach ms) {
	this->ms = ms;
	nextofMS = NULL;
}

Node2::~Node2()
{

	//	if (this->next != NULL) delete this->next;
		//	if (this ->nextSV != NULL ) delete this ->nextSV;
}
