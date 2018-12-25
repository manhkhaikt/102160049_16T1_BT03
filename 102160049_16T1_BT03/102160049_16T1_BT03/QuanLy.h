#pragma once
#include"PhongKS.h"
#include"PhongBT.h"
#include"PhongVIP.h"


struct NODE {
	PhongKS *data;
	NODE *next;
};

class QuanLy
{
public:
	NODE *front, *rear;
	int count;
	bool loai;
public:
	QuanLy();
	QuanLy(bool);
	void init(QuanLy &);
	bool isEmpty(QuanLy &);
	NODE *makeNode(PhongKS*);
	void push(QuanLy &, PhongKS*);
	void pop(QuanLy &);
	PhongKS qFront(QuanLy &);
	void nhap(QuanLy &);
	void xuat(QuanLy &);
	void timKiem(QuanLy&, string);
	void xoa(QuanLy &, string);
	void chinhSua(QuanLy &, string);
	~QuanLy();
};

