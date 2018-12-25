#pragma once
#include"PhongKS.h"
#include<iostream>
#include"Date.h"
#include<string>
#include<sstream>
#include <iomanip>

using namespace std;
class PhongBT :public PhongKS
{
public:
	PhongBT();
	double giaPhong(int, string);
	friend istream & operator>>(istream&, PhongBT&);
	~PhongBT();
};

