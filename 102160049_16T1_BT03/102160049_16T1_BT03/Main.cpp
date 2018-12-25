#include<iostream>

#include"QuanLy.h"


using namespace std;
int main() {

	QuanLy q;
	q.init(q);
	cout << "Nhap du lieu cac phong: " << endl;
	q.nhap(q);
	int a = 0;
	string mPhong;
	do
	{
		cout << "--------------!---------------" << endl;
		cout << "1. In ra cac phong" << endl;
		cout << "2. Tim phong" << endl;
		cout << "3. Them phong" << endl;
		cout << "4. Xoa phong" << endl;
		cout << "5. Chinh sua du lieu phong" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "--------------!---------------" << endl;
		cout << "Chon yeu cau thuc hien" << endl;
		cin >> a;
		if (a == 0) break;
		switch (a)
		{
		case 1:
			q.xuat(q);
			break;
		case 2:
			cout << "Nhap ma phong can tim: ";
			cin >> mPhong;
			q.timKiem(q, mPhong);
			break;

		case 3:
			q.nhap(q);
			break;

		case 4:
			cout << "Nhap ma phong muon xoa " << endl;
			cin >> mPhong;
			q.xoa(q, mPhong);
			break;

		case 5:
			cout << "Nhap ma phong can sua du lieu:" << endl;
			cin >> mPhong;
			q.chinhSua(q,mPhong);
			break;
		case 0:
			break;

		default:
			break;
		}
	} while (a != 0);

	system("pause");
	return 0;
}