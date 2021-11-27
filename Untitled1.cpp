//#include<iostream>
//#include <fstream>
//#include "Sach.h"
//#include "HocSinh.h"
//#include "MuonSach.h"
//#include <vector>
//
//using namespace std;
//vector<HocSinh> ds_hs;
//vector<Sach> ds_sach;
//ofstream os("Sach.txt", ios::out);
//ifstream is("Data.txt", ios::in);
//void GhiFile(ofstream& os, vector<Sach>& ds_sach);
//void DocFile(ifstream& is, vector<HocSinh>& ds_hs);
//void Display();
//void ThuVien() {
//	char luachon;
//	/*Sach y;
//	y.Nhap();*/
//	while (1)
//	{
//		system("cls");
//		cout << "\n\n\t\t---------------------THU VIEN -----------";
//		cout << "\n\t1.SACH";
//		cout << "\n\t2.DOC GIA";
//		cout << "\n\t3.THOAT !!";
//		cout << "\n\n\t\t-------------------------END---------------";
//		cout << "\nChon!! 		";
//		cin >> luachon;
//		fflush(stdin);
//		if (luachon == '1')
//		{
//			fflush(stdin);
//			Sach x;
//			cout << "\n\tNhap thon tin sach can them !" << endl;
//			x.Nhap();
//			x.ghiFile(os);
//			ds_sach.push_back(x);
//		}
//		if (luachon == '2')
//		{
//			HocSinh x;
//			cout << "\n\tGhi danh sach nguoi lon";
//			x.get(is);
//			ds_hs.push_back(x);
//		}
//		if (luachon != '1' && luachon != '2')
//		{
//			break;
//		}
//	}
//}
//int main() {
//	/*ifstream is("Data.txt", ios::in);
//	DocFile(is, ds_hs);
//	cout << "\nDu lieu da doc thanh cong !" << endl;
//	Display();*/
////	ofstream os("Sach.txt", ios::out);
////	Sach a;
//	//a.Nhap();
//	//GhiFile(os, ds_sach);
//	////a.display();
//	//for (int i = 0; i < ds_sach.size(); i++) {
//	//	ds_sach[i].display();
//	//}
//	ThuVien();
//	return 0;
//}
//void GhiFile(ofstream& os, vector<Sach>& ds_sach) {
//	int i = 1, k;
//	while (i == 1) {
//		Sach x;
//		x.Nhap();
////os<<  x.getTenSach();
//		ds_sach.push_back(x);
//		cin >> k;
//		if (k != 1) {
//			fflush(stdin);
//			break;
//		}
//			
//	}
//}
//void DocFile(ifstream& is, vector<HocSinh>& ds_hs) {
//	while (is.eof() == false) {
//		HocSinh x;
//		x.get(is);
//		
//		int n;
//		is >> n;
//		string temp;
//		getline(is, temp);
//		for (int i = 0; i < n; i++) {
//			MuonSach y;
//			y.get(is);
//			x.ds_muonsach.push_back(y);
//		}
//		ds_hs.push_back(x);
//	}
//}
//void Display() {
//	for (int i = 0; i < ds_hs.size(); i++) {
//		ds_hs[i].display();
//		
//	}
//}
