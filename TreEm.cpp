#include "TreEm.h"
#include<iostream>
using namespace std;
void TreEm::get(ifstream& in) {
	DocGia::get(in);
	getline(in, this->tenPH);
	getline(in, this->STDPH);

}
void TreEm::display() {
	DocGia::display();
	cout << this->tenPH << this->STDPH ;
	for (int i = 0; i < ds_muonsach.size(); i++) {
		ds_muonsach[i].Xuat();
	}
}
