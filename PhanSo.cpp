#include<iostream>
using namespace std;

using ll = long long;
//Uoc chung lon nhat
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}
void prinLine(int n) {
	for (int i = 0; i < n; i++)
		cout << "-";
}
class PhanSo {
private:
	ll tu, mau;
public:
	PhanSo(ll tu, ll mau);
	friend ostream& operator << (ostream&, PhanSo);
	friend istream& operator >> (istream&, PhanSo&);
	friend PhanSo operator + (PhanSo, PhanSo);
	friend PhanSo operator - (PhanSo, PhanSo);
	friend PhanSo operator * (PhanSo, PhanSo);
	friend PhanSo operator / (PhanSo, PhanSo);
	void rutGon();
};

PhanSo::PhanSo(ll tu = 1, ll mau = 1) {
	this->tu = tu;
	this->mau = mau;
}

ostream& operator << (ostream& out, PhanSo a) {
	out << a.tu << "/" << a.mau << endl;
	return out;
}

istream& operator >> (istream& in, PhanSo& a) {
	in >> a.tu >> a.mau;
	return in;
}

PhanSo operator + (PhanSo a, PhanSo b) {
	PhanSo tong;
	ll mc = lcm(a.mau, b.mau);
	tong.tu = mc / a.mau * a.tu + mc / b.mau * b.tu;
	tong.mau = mc;
	ll g = gcd(tong.tu, tong.mau);
	tong.tu /= g; tong.mau /= g;
	return tong;
}

PhanSo operator - (PhanSo a, PhanSo b) {
	PhanSo hieu;
	ll mc = lcm(a.mau, b.mau);
	hieu.tu = mc / a.mau * a.tu - mc / b.mau * b.tu;
	hieu.mau = mc;
	ll g = gcd(hieu.tu, hieu.mau);
	hieu.tu /= g; hieu.mau /= g;
	return hieu;
}

PhanSo operator * (PhanSo a, PhanSo b) {
	PhanSo tich;
	tich.tu = a.tu * b.tu;
	tich.mau = a.mau * b.mau;
	ll g = gcd(tich.tu, tich.mau);
	tich.tu /= g; tich.mau /= g;
	return tich;
}

PhanSo operator / (PhanSo a, PhanSo b) {
	PhanSo thuong;
	thuong.tu = a.tu * b.mau;
	thuong.mau = a.mau * b.tu;
	ll g = gcd(thuong.tu, thuong.mau);
	thuong.tu /= g; thuong.mau /= g;
	return thuong;
}

void PhanSo::rutGon() {
	ll g = gcd(tu, mau);
	tu /= g;
	mau /= g;
}

int main() {
	PhanSo p, q;
	int x;
	cout << "1. Rut gon phan so" << endl;
	cout << "2. Cong 2 phan so" << endl;
	cout << "3. Tru 2 phan so" << endl;
	cout << "4. Nhan 2 phan so" << endl;
	cout << "5. Chia 2 phan so" << endl;
	cout << "Nhap lua chon: "; cin >> x;
	switch (x)
	{
	case 1: {
		cout << "Nhap phan so va tu so: ";
		cin >> p;
		p.rutGon();
		cout << "\nKet Qua: ";
		cout << p;
	}
		  break;
	case 2: {
		cout << "Nhap phan so va tu so: ";
		cin >> p >> q;
		cout << "\nKet Qua: ";
		cout << p + q;
	}
		  break;
	case 3: {
		cout << "Nhap phan so va tu so: ";
		cin >> p >> q;
		cout << "\nKet Qua: ";
		cout << p - q;
	}
		  break;
	case 4: {
		cout << "Nhap phan so va tu so: ";
		cin >> p >> q;
		cout << "\nKet Qua: ";
		cout << p * q;
	}
		  break;
	case 5: {
		cout << "Nhap phan so va tu so: ";
		cin >> p >> q;
		cout << "\nKet Qua: ";
		cout << p / q;
	}
		  break;
	default:
		break;
	}
	
	return 0;
}