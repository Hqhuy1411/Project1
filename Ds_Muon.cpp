#include "Ds_Muon.h"
#include <iostream>
using namespace std;
Ds_Muon::Ds_Muon() {
	this->head = NULL;
	this->tail = NULL;
	size = 0;
}
Ds_Muon::Ds_Muon(Ds_Muon& x) {

    Node2* temp = x.head;
    Node2* newNode = nullptr;

    while (temp != nullptr)
    {
        newNode = new Node2();
        newNode->ms = temp->ms;
        newNode->nextofMS = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        temp = temp->nextofMS;
    }
}
const Ds_Muon &Ds_Muon::operator = (const Ds_Muon& x) {
    if (this != &x) {
        size = x.size;
        delete[] head;
        delete[] tail;
        Node2* temp = x.head;
        Node2* newNode = nullptr;

        while (temp != nullptr)
        {
            newNode = new Node2();
            newNode->ms = temp->ms;
            newNode->nextofMS = nullptr;

            if (head == nullptr)
            {
                head = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            temp = temp->nextofMS;
        }
    }
    return *this;
}
Ds_Muon::~Ds_Muon() {
    Node2* current;
    while (head != NULL) {
        current = head->nextofMS;
        delete head;
        head = current;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}
int Ds_Muon::getSize() {
    return this->size;
}
void Ds_Muon::Insert(MuonSach p) {
    Node2* node = new Node2(p);
    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->nextofMS = node;
        tail = node;
    }
    size++;
    fflush(stdin);
}
void Ds_Muon::Remove(string name) {

}
void Ds_Muon::display() {
    Node2* current = head;
    while (current != NULL) {
        current->ms.Xuat();
        current = current->nextofMS;
        cout << "------------------------------" << endl;
    }
}
void Ds_Muon::display(ofstream& out) {
    Node2* current = head;
    while (current != NULL) {
        current->ms.GhiFile(out);
        current = current->nextofMS;
    }
}
void Ds_Muon::displaySach(Ds_Sach& x) {
    Node2* current = head;
    Ds_Sach list = x;
    while (current != NULL) {
        Sach x = list.Search(current->ms.getTenSach());
        x.Output();
        current->ms.XuatSach();
        current = current->nextofMS;
        cout << "------------------------------" << endl;
    }
}