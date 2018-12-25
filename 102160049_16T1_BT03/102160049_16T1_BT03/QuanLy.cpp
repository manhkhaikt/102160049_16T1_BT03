#include"QuanLy.h"

inline int string_to_int(string s)
{
	stringstream ss(s);
	int x;
	ss >> x;
	return x;
}


QuanLy::QuanLy()
{
}

QuanLy::QuanLy(bool loai)
{
	this->loai = loai;
}


void QuanLy::init(QuanLy &q)
{
	q.front = NULL;
	q.rear = NULL;
	q.count = 0;
}

bool QuanLy::isEmpty(QuanLy & q)
{
	if (q.count == 0) {
		return 1;
	}
	else return 0;
}

NODE * QuanLy::makeNode(PhongKS *p)
{
	NODE *q = (NODE*)malloc(sizeof(NODE));
	q->next = NULL;
	q->data = p;
	return q;
}

void QuanLy::push(QuanLy &q, PhongKS *p)
{
	NODE* a = makeNode(p);
	if (isEmpty(q)) {
		q.front = q.rear = a;
	}
	else {
		q.rear->next = a;
		q.rear = a;
	}
	q.count++;
}

void QuanLy::pop(QuanLy &q)
{
	if (!isEmpty(q)) {
		PhongKS p = *q.front->data;
		if (q.count == 1) {
			init(q);
		}
		else {
			q.front = q.front->next;
			q.count--;
		}
	}
}

PhongKS QuanLy::qFront(QuanLy &q)
{
	return *q.front->data;
}

void QuanLy::nhap(QuanLy &q)
{
	int i = 0;
	int x = 1;
	bool loai;
	PhongKS *p = new PhongKS;
	do {
		i++;
		cout << "Nhap phong thu: " << i << endl;
		cout << "Nhap loai phong(1 Phong thuong, 0 Phong VIP): ";
		cin >> loai;
		if (loai) {
			PhongBT *m = new PhongBT();
			cin >> *m;
			p = dynamic_cast<PhongKS*>(m);
			if (x != 0) q.push(q, p);
		}
		else {
			PhongVIP *n = new PhongVIP();
			cin >> *n;
			p = dynamic_cast<PhongKS*>(n);
			if (x != 0) q.push(q, p);
		}

		cout << "chon 0 de dung lai, chon 1 de tiep tuc nhap phong: ";
		cin >> x;
		cout << "--------------!--------------" << endl;

	} while (x != 0);
	cout << "--------------!--------------" << endl;
}

void QuanLy::xuat(QuanLy &q)
{
	NODE *a = q.front;
	while (a != NULL)
	{
		if (a->data->loai)
		{
			cout << "Loai Phong: Thuong" << endl;
		}
		else {
			cout << "Loai Phong: VIP" << endl;
		}
		cout << *a->data << endl;
		a = a->next;
	}
}

void QuanLy::timKiem(QuanLy &q, string mPhong)
{
	string temp = q.front->data->mPhong;
	int count = 0;
	while (q.front->data->mPhong != mPhong)
	{
		push(q, q.front->data);
		pop(q);
		if (q.front->data->mPhong == temp)
		{
			count = 1;
			break;
		}
	}
	if (count == 0) {
		cout << *q.front->data << endl;
	}
	else if (count == 1)
	{
		cout << "Khong tim thay phong" << endl;
		cout << "--------------!--------------" << endl;
	}
}

void QuanLy::xoa(QuanLy &q, string mPhong)
{
	string temp = q.front->data->mPhong;
	int count = 0;
	while (q.front->data->mPhong != mPhong)
	{
		push(q, q.front->data);
		pop(q);
		if (q.front->data->mPhong == temp)
		{
			count = 1;
			break;
		}
	}
	if (count == 0) {
		pop(q);
	}
	else if (count == 1)
	{
		cout << "khong tim thay phong can xoa" << endl;
		cout << "--------------!--------------" << endl;
	}
}

void QuanLy::chinhSua(QuanLy &q,string mPhong)
{
	q.timKiem(q,mPhong);
	string a;
	int b;
	bool c;
	Date d;
	Date e;
	double f;
	int z = 0;

	cin.ignore(1);
	do {
		cout << "Ma Phong moi: ";
		getline(cin, a);

		z = string_to_int(a);
	} while (z < 10001 || z > 59999);

	do {
		cout << "So nguoi thoi da:";
		cin >> b;
	} while (b < 1 || b>4);

	cout << "Tinh trang phong: ";
	cin >> c;
	if (c == false) {
		cout << "Ngay nhan phong: " << endl;
		cin >> d;

		cout << "Ngay tra phong: " << endl;
		cin >> e;

	}
	cout << "--------------!--------------" << endl;

	do
	{
		cin >> f;
	} while (f < 0);
	q.front->data->update(a, b, c, d, e, f);

}

QuanLy::~QuanLy()
{
}
