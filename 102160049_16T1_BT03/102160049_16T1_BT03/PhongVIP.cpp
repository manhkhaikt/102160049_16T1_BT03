#include "PhongVIP.h"

inline int string_to_int(string s)
{
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

PhongVIP::PhongVIP()
{
	this->loai;
}

double PhongVIP::giaPhong(int sNguoi, string mPhong)
{
	int a = string_to_int(mPhong);
	if (a > 10001 && a < 19999)
	{
		this->donGia = 700000.0 * sNguoi;
	}
	if (a > 20001 && a < 29999)
	{
		this->donGia = 650000.0 * sNguoi;
	}
	if (a > 30001 && a < 39999)
	{
		this->donGia = 600000.0 * sNguoi;
	}
	if (a > 40001 && a < 49999)
	{
		this->donGia = 550000.0 * sNguoi;
	}
	if (a > 50001 && a < 59999)
	{
		this->donGia = 500000.0 * sNguoi;
	}
	return  this->donGia + this->phuThu*this->donGia;

}

istream & operator>>(istream &i, PhongVIP &p)
{
	int a = 0;
	cin.ignore(1);
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

PhongVIP::~PhongVIP()
{
}
