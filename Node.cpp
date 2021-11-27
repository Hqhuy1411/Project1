#include "Node.h"
Node::Node() {
	this->p = NULL;
	this->nextofDG = NULL;
	
}
Node::Node(DocGia* x) {
	this->p = x;
	this->nextofDG = NULL;
}
Node::Node(Node &x){
	this->p=x.p;
	this->nextofDG =x.nextofDG;
}
Node::~Node()
{
	
//	if (this->next != NULL) delete this->next;
	//	if (this ->nextSV != NULL ) delete this ->nextSV;
}
