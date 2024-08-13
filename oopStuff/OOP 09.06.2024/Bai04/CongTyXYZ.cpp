#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#define ll long long
using namespace std;

ifstream file;
ofstream File;
class Costumer {
protected:
	string Name;
	int nOrder;
	ll Price;
	ll VAT;
	ll Total;
public:
	Costumer(string Name = "", int nOrder = 0, ll Price = 0, ll VAT = 0) {
		this->Name = Name;
		this->nOrder = nOrder;
		this->Price = Price;
		this->VAT = VAT;
		this->Total = 0;
	}
	~Costumer(){}
	virtual void Input();
	virtual void Output();
	ll getTotal() {
		return Total;
	}
	void setTotal(ll temp) {
		Total=temp;
	}
};
class ACostumer:public Costumer {
public:
	ACostumer(string Name="", int nOrder = 0, ll Price = 0, ll VAT = 0) :Costumer(Name, nOrder, Price, VAT) {
		this->Name = Name;
		this->nOrder = nOrder;
		this->Price = Price;
		this->VAT = VAT;
	}
	~ACostumer() {}
	void Input();
	void Output();
};
class BCostumer :public Costumer {
protected:
	double Loyality;
public:
	BCostumer(string Name = "", int nOrder = 0, ll Price = 0, ll VAT = 0, int Loyality = 0) :Costumer(Name, nOrder, Price, VAT) {
		this->Loyality = Loyality;
	}
	void Input();
	void Output();
};
class CCostumer :public Costumer {
public:
	CCostumer(string Name="", int nOrder = 0, ll Price = 0, ll VAT = 0) :Costumer(Name, nOrder, Price, VAT) {
	}
	void Input();
	void Output();
};
class List {
private:
	int x,y,z;
	Costumer** a;
public:
	List(int x = 0,int y=0,int z=0) {
		this->x = x;
		this->y = y;
		this->z = z;
		a = new Costumer * [x+y+z];
	}
	~List() {
		for (int i = 0; i < x + y + z; i++) {
			delete a[i];
		}
		delete[] a;
	}
	void Input();
	void Output();
};
void Costumer::Input() {
	//Ten khach hoang
	getline(file, Name);
	//So luong don hang
	file >> nOrder;
	//Don gia hang
	file >> Price;
	file.ignore();
};
void Costumer::Output() {
	File << Name << '\n';
	File << Total << '\n';
}
void ACostumer::Input() {
	Costumer::Input();
	VAT = 0.1 * (Price * nOrder);
	Total = (Price * nOrder) + VAT;
}
void ACostumer::Output() {
	Costumer::Output();
}
void BCostumer::Input() {
	Costumer::Input();
	file >> Loyality;
	Loyality = max(Loyality * 0.05, 0.5);
	VAT = 0.1 * (nOrder * Price);
	Total = (nOrder * Price) * (1 - Loyality) + VAT;
	file.ignore();
}
void BCostumer::Output() {
	Costumer::Output();	
}
void CCostumer::Input() {
	Costumer::Input();
	VAT = 0.1 * (Price * nOrder);
	Total = (Price * nOrder)*0.5 + VAT;
}
void CCostumer::Output() {
	Costumer::Output();
}
void List::Input() {
	file.open("XYZ.INP.txt");
	if (!file.is_open()) {
		cout << "Cant open file";
		return;
	}
	file >> x >> y >> z;
	file.ignore();
	for (int i = 0; i < x; i++) {
		a[i] = new ACostumer();
		a[i]->Input();
	}
	for (int i = x; i < (x + y); i++) {
		a[i] = new BCostumer();
		a[i]->Input();
	}
	for (int i = (x + y); i < (x + y + z); i++) {
		a[i] = new CCostumer();
		a[i]->Input();
	}
	file.close();
}
void List::Output() {
	ll SumofToTal=0;
	File.open("XYZ.OUT.txt");
	for (int i = 0; i < x + y + z; i++) {
		a[i]->Output();
		SumofToTal += a[i]->getTotal();
	}
	File << "Tong so tien cong ty thu duoc: \n" << SumofToTal;
	File.close();
}
int main() {
	List a;
	a.Input();	
	a.Output();
}