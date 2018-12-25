#include "Date.h"



Date::Date()
{
}

Date::Date(int ngay, int thang, int name)
{
	this->ngay = ngay;
	this->thang = thang;
	this->nam = nam;
}


Date::~Date()
{
}

istream & operator>>(istream & i, Date & p)
{

	do
	{
		cout << "Nam: ";
		i >> p.nam;

	} while (p.nam < 1990 || p.nam > 2018);
	do
	{
		cout << "Thang: ";

		i >> p.thang; cout;

	} while (p.thang < 0 || p.thang > 12);
	do {
		cout << "Ngay:";
		i >> p.ngay; cout;

	} while (p.ngay > 31 || p.ngay < 0);
	return i;
}

ostream & operator<<(ostream & o, Date & p)
{
	o << "Nam/Thang/Ngay: " << p.nam << "/" << p.thang << "/" << p.ngay;
	return o;
}
