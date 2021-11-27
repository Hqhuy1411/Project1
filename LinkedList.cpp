#include "LinkedList.h"
#include <iomanip>
LinkedList::LinkedList() {
	this->size = 0;
	this->head = NULL;
	this->tail = NULL;
}
LinkedList::~LinkedList() {
	while (this->head != NULL) {
		Node* currentNode = this->head;
		this->head = this->head->nextofDG;
		currentNode->nextofDG = NULL;
		delete currentNode;
	}
}
int LinkedList::getSize() {
	return this->size;
}
void LinkedList::printList() {
	cout << "Linked List " << endl;
	cout << "Size: " << this->size << endl;
	cout << "Danh Sach Doc Gia!!" << endl;
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		currentNode->p->Xuat();
		currentNode = currentNode->nextofDG;
		cout << "---------------------" << endl;
	}
}
void LinkedList::printHS() {
	cout << "Ma doc gia" << setw(15) << "Ho va ten" << setw(7) << "Lop" << setw(10) << "Ngay sinh" << setw(10) << "Truong" << setw(10) << "SDT" << endl;
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->p->getKT() == false) {
			currentNode->p->Xuat();
		}
		currentNode = currentNode->nextofDG;

	}
}
void LinkedList::printSV() {
	cout << "Ma doc gia" << setw(15) << "Ho va ten" << setw(7) << "Lop" << setw(10) << "Ngay sinh" << setw(10) << "Khoa" << setw(10) << "CMND" << setw(10) << "SDT" << endl;
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->p->getKT() == true) {
			currentNode->p->Xuat();
		}
		currentNode = currentNode->nextofDG;
		
	}
}
void LinkedList::printList(ofstream& os) {
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		fflush(stdin);
		currentNode->p->GhiFile(os);
		currentNode = currentNode->nextofDG;
	}
}
void LinkedList::insertTail(Node x) {
	Node* node = &x;
	if (head == NULL) {
		head = node;
		tail = node;
	}
	else {
		tail->nextofDG = node;
		tail = node;
	}
	size++;
}
void LinkedList::insertHead(DocGia* x){
	Node * node = new Node(x);
	if (head == NULL) {
		head = node;
		tail = node;
	}
	else {
		node->nextofDG = head;
		head = node;
	}
	size++;
}
//void LinkedList::insertNode(Node* node, int position) {
//	if (this->head == NULL || position < 1) {
//		// Them truoc
//		node->nextofDG = this->head; 
//		this->head = node; 
//		if (this->tail == NULL) {
//			this->tail = node;
//		}
//		this->size++;
//		return;
//	}
//
//	if (position >= this->size) {
//		// Them vao sau
//		this->tail->nextofDG = node;
//		this->tail = node;
//		this->size++;
//		return;
//	}
//
//	Node* preNode = NULL;
//	Node* currentNode = this->head;
//	int pos = 0;
//	while (pos < position) {
//		pos++; 
//		preNode = currentNode;
//		currentNode = currentNode->nextofDG;
//	}
//	node->nextofDG = currentNode;
//	preNode->nextofDG = node;
//	this->size++;
//}
void LinkedList::deleteNode(string IdDocGia) {
	if (this->head == NULL) return;

	Node* preNode = NULL;
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->p->getID() == IdDocGia) {
			if (preNode == NULL) {
				// delete front
				this->head = this->head->nextofDG;
				if (this->head == NULL) {
					this->tail = NULL;
				}
			}
			else if (this->tail == currentNode) {
				// delete last
				if (preNode != NULL) {
					preNode->nextofDG = NULL;
				}
				this->tail = preNode;
			}
			else {
				// delete in the middle
				preNode->nextofDG = currentNode->nextofDG;
			}
			currentNode->nextofDG = NULL;
			delete currentNode;
			this->size--;
			return;
		}
		preNode = currentNode;
		currentNode = currentNode->nextofDG;
	}
}
Node* LinkedList::searchNode(string IdDocGia) {
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->p->getID() == IdDocGia) {
			return currentNode;
		}
		currentNode = currentNode->nextofDG;
	}
	cout << "Khong tim thay id DocGia (" << IdDocGia << ")" << endl;
	return NULL;
}
Node* LinkedList::Login(string tk, string mk) {
	Node* currentNode = this->head;
	while (currentNode != NULL) {
		if (currentNode->p->getMK()._Equal(mk) && currentNode->p->getTK()._Equal(tk)) {
			return currentNode;
		}
		currentNode = currentNode->nextofDG;
	}
	return NULL;
}