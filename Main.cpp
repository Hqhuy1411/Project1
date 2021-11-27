#include <iostream>
#include <fstream>
#include <string>
#include "Sach.h"
#include "LinkedList.h"
#include "Ds_Sach.h"

using namespace std;
int main() {
	int i, dt, chon;
	ifstream is("Sach.txt", ios::in | ios::out);
	ofstream os("Sach.txt ", ios::app);
	ifstream iss("Data.txt", ios::in | ios::out);
	ofstream oss("Data.txt ", ios::app);
	DocGia* x = NULL;
	LinkedList ll;
	Ds_Sach list;
	while (is.eof() == false) {
		Sach x;
		x.get(is);
		list.Insert(x);
	}
	while (iss.eof() == false) {
		char c;
		iss >> c;
		iss.seekg(-1, 1);
		if (c == 'H')
		{
			x = new HocSinh();
			x->DocFile(iss);
			x->setKT(false);
			ll.insertHead(x);

		}
		else if (c == 'S')
		{
			x = new Sinhvien();
			x->DocFile(iss);
			x->setKT(true);
			ll.insertHead(x);

		}
		if ((c != 'H' && c != 'S') && iss.eof() == false) {
			MuonSach y;
			y.DocFile(iss);
			x->ds.Insert(y);
		}
	}
	//list.display();
	cout << "1.Nguoi dung la Giao Vien " << endl;
	cout << "2.Nguoi dung la Doc Gia" << endl;
	cout << "Nhap :"; cin >> i;
	if (i == 1) {
		cout << "1.Sach !!" << endl;
		cout << "2.Doc Gia !!" << endl;
		cout << "Nhap"; cin >> dt;
		while (1) {
			if (dt == 1) {
				while (1) {
					cout << "1.Hien thi tat ca cac sach !!" << endl;
					cout << "2.Them sach " << endl;
					cout << "3.Xoa sach" << endl;
					cout << "4.Tim sach " << endl;
					cout << "5.Tim Tac gia" << endl;
					cout << "6.Sua Sach" << endl;
					cout << "0.Thoat" << endl;
					cout << "Nhap: "; cin >> chon;
					switch (chon)
					{
					case 1: {
						system("cls");
						cout << "Danh sach Sach hien co !!" << endl;
						list.display();
						break;
					}
					case 2: {
						int a;
						while (1) {
							cout << "1.Them cuoi danh sach !" << endl;
							cout << "2.Them dau danh sach !" << endl;
							cout << "0.Thoat !" << endl;
							cout << "Nhap : "; cin >> a;
							switch (a)
							{
							case 1: {
								system("cls");
								cout << "Them sach :" << endl;
								Sach x;
								cin >> x;
								x.ghiFile(os);
								list.Insert(x);
								cout << "Them thanh cong !!" << endl;
								break;
							}
							case 2: {
								system("cls");
								cout << "Them sach :" << endl;
								Sach x;
								cin >> x;
								list.InsertLast(x);
								ofstream os1("Sach.txt ", ios::out | ios::trunc);
								os1 << "";
								list.display(os);
								cout << "Them thanh cong !!" << endl;
								break;
							}
							default:
								break;
							}
							if (a == 0)
								break;
						}
						break;
					}
					case 3: {
						int a;
						while (1) {
							cout << "1.Xoa dau danh sach !" << endl;
							cout << "2.Xoa cuoi danh sach !" << endl;
							cout << "3.Xoa theo ten sach !" << endl;
							cout << "4.Xoa theo ten tac gia" << endl;
							cout << "0.Thoat !" << endl;
							cout << "Nhap : "; cin >> a;
							switch (a)
							{
							case 1: {
								list.RemoveHead();
								ofstream os1("Sach.txt ", ios::out | ios::trunc);
								os1 << "";
								list.display(os);
								cout << "Xoa thanh cong !" << endl;
								break;
							}
							case 2: {
								list.RemoveLast();
								ofstream os1("Sach.txt ", ios::out | ios::trunc);
								os1 << "";
								list.display(os);
								cout << "Xoa thanh cong !" << endl;
								break;
							}
							case 3: {
								cin.ignore();
								string ten;
								cout << " Nhap ten can xoa ";  getline(cin, ten);
								if (list.Search(ten).getTacGia()._Equal("")) {
									cout << "Khong tim thay sach !!" << endl;
								}
								else {
									list.RemovebyName(ten);
									ofstream os1("Sach.txt ", ios::out | ios::trunc);
									os1 << "";
									list.display(os);
									cout << "Xoa thanh cong !" << endl;
								}

								break;
							}
							case 4: {
								cin.ignore();
								string ten;
								cout << " Nhap ten can xoa ";  getline(cin, ten);
								list.RemovebyTG(ten);
								cout << "Xoa thanh cong" << endl;
								break;
							}
								  if (a == 0)
									  break;
							}

						}
						break;
					}
					case 4: {
						string abc;
						cout << "Nhap ten sach can timk kiem :"; cin.ignore(); getline(cin, abc);
						Sach x = list.Search(abc);
						cout << x;
						break;
					}
					case 5: {
						string abc1;
						cout << "Nhap ten tac gia can timk kiem";  cin.ignore(); getline(cin, abc1);
						list.BooksofTG(abc1);
						break;
					}
					case 6: {
						cin.ignore();
						int a;
						string sach;
						cout << "Nhap ten sach can sua :";
						getline(cin, sach);
						if (list.Search(sach).getTacGia()._Equal("")) {
							cout << "Khong tim thay sach !!" << endl;
						}
						else {
							while (1) {
								cout << "1.Sua ten tac gia !" << endl;
								cout << "2.Sua trang thai cua sach !" << endl;
								cout << "0.Thoat" << endl;
								cout << "Nhap : "; cin >> a;
								switch (a)
								{
								case 1: {
									cin.ignore();
									string tacgia;
									cout << "Nhap ten tac gia moi :"; getline(cin, tacgia);
									list.Update(sach, tacgia);
									ofstream os1("Sach.txt ", ios::out | ios::trunc);
									os1 << "";
									list.display(os);
									cout << "Cap nhat thanh cong !!" << endl;
									break;
								}
								case 2: {
									cin.ignore();
									list.Update(sach);
									ofstream os1("Sach.txt ", ios::out | ios::trunc);
									os1 << "";
									list.display(os);
									cout << "Cap nhat thanh cong !!" << endl;
									break;
								}

									  if (a == 0)
										  break;
								}
								break;
							}
							break;
						}
						break;
					}
					case 0:
						return 0;
					}
				}
			}
			if (dt == 2) {
				while (1) {
					cout << "------------------------ooooooooo------------------------" << endl;
					cout << "1. Hien thi danh sach " << endl << "2.Them doc gia " << endl << "3.Xoa doc gia " << endl << "4.Tim kiem " << endl << "5.Ket thuc" << endl;
					int chon, stop = 1;
					cout << "Vui long lua chon : "; cin >> chon;
					switch (chon) {
					case 1: {
						//ll.printList();
						cout << "\n\t\t\t Danh Sach Sinh Vien " << endl;
						ll.printSV();
						cout << "\n\t\t\t Danh Sach Hoc Sinh " << endl;
						ll.printHS();
						break;
					}
					case 2: {
						int k;
						cout << "1.Nhap thong tin Hoc Sinh" << endl;
						cout << "2.Nhap thong tin Sinh Vien" << endl;
						cout << "Nhap :"; cin >> k;
						if (k == 1) {
							x = new HocSinh();
							cout << "Nhap thong tin" << endl;
							x->Nhap();
							x->setKT(false);
							oss << "\n";
							x->GhiFile(oss);
							ll.insertHead(x);

						}
						else {
							x = new Sinhvien();
							cout << "Nhap thong tin" << endl;
							x->Nhap();
							x->setKT(true);
							oss << "\n";
							x->GhiFile(oss);
							ll.insertHead(x);
						}
						break;
					}
					case 3: {
						string iddocgia1;
						cout << "Nhap id doc gia can` xoa' "; cin >> iddocgia1;
						Node* tim = ll.searchNode(iddocgia1);
						if (tim != NULL) {
							ll.deleteNode(iddocgia1);
							ofstream os1("Data.txt ", ios::out | ios::trunc);
							os1 << "";
							ll.printList(oss);
							cout << "Xoa thanh cong " << endl;
						}
						else {
							cout << "Doc gia hien tai khong co trong danh sach!!" << endl;
						}
					break;
					}
					case 4: {
						string iddocgia2;
						cout << "NHap id doc gia can` tim` "; cin >> iddocgia2;
						Node* tim = ll.searchNode(iddocgia2);
						if (tim != NULL) {
							cout << "Danh sach hien co !!" << endl;
							if (tim->p->getKT() == true) {
								cout << "Thong tim cua cua sinh vien can tim kiem" << endl;
								tim->p->Xuat();
							}
							else {
								cout << "Thong tim cua cua hoc sinh can tim kiem" << endl;
								tim->p->Xuat();
							}
						}
						else {
							cout << "Doc gia hien tai khong co trong danh sach!!" << endl;
						}
						break;
					}
					case 5: {
						return 0;
					}
					}
				}
			}
			if (dt == 0) {
				cout << "Ket thuc chuong trinh !!" << endl;
				break;
			}
		}		
	}
	else{
		string tk, mk;
		cout << "Nhap tai khoan :"; cin >> tk;
		cout << "Nhap mat khau :"; cin >> mk;
		Node* user = ll.Login(tk, mk);
		if (user == NULL) {
			cout << "Khong tim thay nguoi dung " << endl;
		}
		else {
			while (1) {
				int k;
				cout << "1.Xem thong tin ca nhan !!" << endl;
				cout << "2.Muon sach " << endl;
				cout << "3.Xem sach da muon !!" << endl;
				cout << "Nhap ... : "; cin >> k;
				switch (k)
				{
				case 1: user->p->Xuat(); break;
				case 2: {
					MuonSach y;	cin >> y;
					//oss << y;
					string check = list.CheckMuon(y.getTenSach(), y.getTacGia());
					if (check._Equal("")) {
						cout << "Ten Sach or Tac Gia khong hop le !!" << endl;
					}
					else {
						cout << check << endl;
						user->p->ds.Insert(y);
						ofstream os1("Data.txt ", ios::out | ios::trunc);
						os1 << "";
						ll.printList(oss);
					}
					break;
				}
				case 3: {
					if (user->p->ds.getSize() != 0) {
						char l;
						user->p->ds.display();
						cout << "Nhap phim 'c' de xem thong tin cua sach !!" << endl;
						cin >> l;
						if (l == 'c') {
							user->p->ds.displaySach(list);
						}
					}
					else {
						cout << "Doc gia tung muon sach nao !!" << endl;
					}
					break;
				}
				}
			}
		}
	}
	iss.close();
	is.close();
	return 0;

}