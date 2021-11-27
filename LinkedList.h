#pragma once
#include<iostream>
#include "Node.h"
class LinkedList
{
	int size;
	Node* head;
	Node* tail;
public:
	LinkedList();
	~LinkedList();

	int  getSize();
	void insertTail(Node x);
	void insertHead(DocGia  *x);
	void printList();
	void printSV();
	void printHS();
	void printList(ofstream & os);
	//		void insertNode(Node *node,int position); 
	void deleteNode(string IdDocGia);
	Node* searchNode(string IdDocGia);
	Node* Login(string tk,string mk);
	//		Node* searchNode(string IdDG);
};
