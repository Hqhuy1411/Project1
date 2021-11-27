#include "Ds_Sach.h"
#include <iostream>
#include <iomanip>
using  namespace std;
Ds_Sach::Ds_Sach() {
	this->head = NULL;
	this->tail = NULL;
	size = 0;

}
Ds_Sach::Ds_Sach(Ds_Sach& x) {
    this->size = x.size;
    Node2* temp = x.head;
    Node2* newNode = nullptr;

    while (temp != nullptr)
    {
        newNode = new Node2();
        newNode->book = temp->book;
        newNode->next = nullptr;

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
        temp = temp->next;
    }
}
const Ds_Sach& Ds_Sach::operator=(const Ds_Sach& x)
{
    if (this != &x) {
        size = x.size;
        delete[] head;
        delete[] tail;
        Node2* temp = x.head;
        Node2* newNode = nullptr;

        while (temp != nullptr)
        {
            newNode = new Node2();
            newNode->book = temp->book;
            newNode->next = nullptr;

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
            temp = temp->next;
        }
    }
    return *this;
}
Ds_Sach::~Ds_Sach() {
    Node2* current;
    while (head != NULL) {
        current = head->next;
        delete head;
        head = current;
    }
    head = NULL;
    tail = NULL;
    size = 0;
}
int Ds_Sach::getSize() {
    return this->size;
}
void Ds_Sach::Insert(Sach p) {
    Node2* node = new Node2(p);
    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        tail->next = node;
        tail = node;
    }
    size++;

}
void Ds_Sach::InsertLast(Sach p) {
    Node2* node = new Node2(p);
    if (head == NULL) {
        head = node;
        tail = node;
    }
    else {
        node->next = head;
        head = node;
    }
    size++;
}
void Ds_Sach::RemoveHead() {
    if (head != NULL) {
        Node2* current = head;
        head = head->next;
        delete current;
        size--;
    }
}
void Ds_Sach::RemoveLast() {
    Node2* current = head;
    while (current->next->next != NULL)
        current = current->next;
    delete (current->next);
    current->next = NULL;
    size--;
}
void Ds_Sach::RemovebyName(string name) {
    Node2* current = head;
    Node2* prev = NULL;
    if (current != NULL && current->book.getTenSach()._Equal(name))
    {
        head = current->next; 
        delete current;  
        size--;
        return;
    }
    else
    {
        while (current != NULL && !current->book.getTenSach()._Equal(name))
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
            return;

        prev->next = current->next;     
        delete current;
        
    }
}
void Ds_Sach::RemovebyTG(string TG) {
    Node2* current = head;
    Node2* prev = NULL;
    if (current != NULL && current->book.getTacGia()._Equal(TG))
    {
        head = current->next;
        delete current;
        return;
    }
    else
    {
        while (current != NULL && !current->book.getTenSach()._Equal(TG))
        {
            prev = current;
            current = current->next;
        }
        if (current == NULL)
            return;

        prev->next = current->next;
        delete current;
    }
}
void Ds_Sach::display() {
    Node2* current = head;
    cout << setw(10) << "Ma Sach" << setw(15) << "Ten Sach" << setw(15) << "Tac Gia"
        << setw(15) << "Thoi Gian XB" << setw(15) << "Trang Thai" << endl;

    while (current != NULL) {
        current->book.Output();
        current = current->next;
    }
 }
void  Ds_Sach::display(ofstream& out) {
    Node2* current = head;
    while (current != NULL) {
        current->book.ghiFile(out);
        current = current->next;
    }
}


Sach Ds_Sach::Search(string TenSach) {
    Node2* current = head;
    while (current != NULL) {
        if (current->book.getTenSach()._Equal(TenSach)) {
            return current->book;
            break;
        }
        else {
            current = current->next;
        }
    }
    return  Sach();
}
void Ds_Sach::BooksofTG(string TG) {
    Node2* current = head;
    while (current != NULL) {
        if (current->book.getTacGia()._Equal(TG)) {
            current->book.Output();
            current = current->next;
        }
        else {
            current = current->next;
        }
    }
}
string Ds_Sach::CheckMuon(string TS, string TG) {
     Node2* current = head;
    while (current != NULL) {
        if (current->book.getTacGia()._Equal(TG) && current->book.getTenSach()._Equal(TS) && current->book.getTrangThai()._Equal("Con")) {
            return "Muon thanh cong";
            current = current->next;
        }
        else  if (current->book.getTacGia()._Equal(TG) && current->book.getTenSach()._Equal(TS) && current->book.getTrangThai()._Equal("Het")) {
            return  "Sach hien tai da het !!";
            current = current->next;
        }
        else  {
            current = current->next;
        }
    }
    return "";
}
void Ds_Sach::Update(string tensach,string tacgia) {
    Node2* current = head;
    while (current != NULL) {
        if (current->book.getTenSach()._Equal(tensach)) {
            current->book.setTacGia(tacgia);
            current = current->next;
        }
        else {
            current = current->next;
        }
    }
}
void Ds_Sach::Update(string tenSach) {
    Node2* current = head;
    while (current != NULL) {
        if (current->book.getTenSach()._Equal(tenSach)) {
            if (current->book.getTrangThai()._Equal("Con")) {
                current->book.setTrangThai("Het");
            }
            else 
                current->book.setTrangThai("Con");
            current = current->next;
        }
        else {
            current = current->next;
        }
    }
 }