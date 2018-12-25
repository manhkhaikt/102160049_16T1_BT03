#include "PhongBT.h"
#include"QuanLy.h"


inline int string_to_int(string s)
{
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}



PhongBT::PhongBT()
{
	this->loai = 1;
}


double PhongBT::giaPhong(int sNguoi, string mPhong)
{
	int a = string_to_int(mPhong);
	double gia = 0.0;
	if (a > 10001 && a < 19999)
	{
		gia = 500000.0 * sNguoi;
	}
	if (a > 20001 && a < 29999)
	{
		gia = 450000.0 * sNguoi;
	}
	if (a > 30001 && a < 39999)
	{
		gia = 400000.0 * sNguoi;
	}
	if (a > 40001 && a < 49999)
	{
		gia = 350000.0 * sNguoi;
	}
	if (a > 50001 && a < 59999)
	{
		gia = 300000.0 * sNguoi;
	}
	return gia;
}

istream & operator>>(istream &i, PhongBT &p)
{
	int a = 0;
	cin.ignore(1);
	int count = 0;
	do {
		cout << "Ma Phong: ";
		getline(i, p.mPhong);
		a = string_to_int(p.mPhong);

	} while (a < 10001 || a > 59999 || a == 20000 || a == 30000 || a == 40000 || a == 50000);

	do {
		cout << "So nguoi toi da: ";
		i >> p.sNguoi;
	} while (p.sNguoi < 1 || p.sNguoi > 4);

	cout << "Tinh trang phong (1 hoac 0): ";
	i >> p.tTrang;

	if (p.tTrang == false) {
		cout << "Ngay nhan phong: " << endl;
		cin >> p.nNhan;
		cout << "Ngay tra phong: " << endl;
		cin >> p.nTra;

	}
	p.gia = p.giaPhong(p.sNguoi, p.mPhong);


	cout << "--------------!--------------" << endl;
	return i;
}


PhongBT::~PhongBT()
{
}
