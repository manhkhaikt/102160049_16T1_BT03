#pragma once
#include"PhongKS.h"
#include<iostream>
#include"Date.h"
#include<string>
#include<sstream>
#include <iomanip>

using namespace std;

class PhongVIP :public PhongKS
{
public:
	double donGia;
	double phuThu = 1.0 / 10;
public:
	PhongVIP();
	double giaPhong(int, string);
	friend istream & operator>>(istream&, PhongVIP&);
	~PhongVIP();
};

