#include "PhongKS.h"




PhongKS::PhongKS()
{}


inline int string_to_int(string s)
{
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}

void PhongKS::update(string mPhong, int sNguoi, bool tTrang, Date nNhan, Date nTra, double gia)
{
	this->mPhong = mPhong;
	this->sNguoi = sNguoi;
	this->tTrang = tTrang;
	this->nNhan = nNhan;
	this->nTra = nTra;
	this->gia = gia;
}


PhongKS::~PhongKS()
{
}


ostream & operator<<(ostream &o, PhongKS &p)
{
	o << "Ma Phong : " << p.mPhong << endl;
	o << "So nguoi toi da: " << p.sNguoi << endl;
	o << "Tinh Trang: ";
	if (p.tTrang == true) o << "Phong trong" << endl;
	else o << "Phong da co nguoi o" << endl;
	if (p.tTrang == false) {
		o << "ngay nhan: "; cout << p.nNhan << endl;
		o << "ngay tra: "; cout << p.nTra << endl;
	}
	else
	{
		o << "Ngay nhan: Null" << endl;
		o << "Ngay Tra: Null" << endl;

	}
	o << "Gia Phong: " << setprecision(9) << p.gia << endl;
	cout << "--------------!--------------" << endl;
	return o;
}

istream & operator>>(istream &i, PhongKS &p)
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
	cout << "--------------!--------------" << endl;
	return i;
}
