#pragma once
#include<iostream>

using namespace std;

class Date
{
private:
	int ngay, thang, nam;
public:
	Date();
	Date(int, int, int);
	friend istream& operator>>(istream &, Date &);
	friend ostream& operator<<(ostream &, Date &);
	~Date();
};

