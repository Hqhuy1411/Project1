//#pragma once
//#include <string>
//#include <fstream>
//using namespace std;
//class Sach
//{
//private:
//	string maSach;
//	string tenSach;
//	string tacGia;
//	string TGXB;
//	string trangthai;
//
//public :
//	Sach();
//	void Nhap();
//	string getMaSach();
//	void ghiFile(ofstream& os);
//	void get(ifstream& in);
//	void display();
//
//};
//
#pragma once
#include <string>
#include <fstream>
using namespace std;
class Sach
{

private:
	
protected:
	string tenSach;
	string tacGia;
	string maSach;
	string TGXB;
	string trangthai;
public:
	Sach();
	Sach(string MS, string TS, string TG, string tgxb, string trangthai);
	Sach(const  Sach &p);
	void setTacGia(string tg);
	string getTacGia();
	void setTenSach(string tensach);
	void setTrangThai(string trangthai);
	string getTenSach();
	string getTrangThai();
	string getMaSach();
	string getTGXB();
	void Input();
	void Output();
	void ghiFile(ofstream& os);
	void get(ifstream& in);
	friend ostream& operator <<(ostream&,const Sach&);
	friend istream& operator >>(istream&, Sach&);
};


