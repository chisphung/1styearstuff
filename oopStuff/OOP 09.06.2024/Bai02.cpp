#include<iostream>
#include<string>
#define ll long long
using namespace std;

class Employees {
protected:
	string ID;
	string Name;
	int Age;
	string Number;
	string Email;
	ll MinSalary;
	ll TotalSalary;
	bool Dev; // Dev: true, Tester: false
public:
	Employees(string ID="", string Name="", int Age=0, string Number="", string Email="", int MinSalary=0) {
		this->ID = ID;
		this->Name = Name;
		this->Age = Age;
		this->Number = Number;
		this->Email = Email;
		this->MinSalary = MinSalary;
	}
	virtual void Input() {
		cout << "Nhap ma so nhan vien: \n";
		cin.ignore();
		cin >> ID;
		cout << "Nhap ten nhan vien: \n";
		cin.ignore();
		getline(cin, Name);
		cout << "Nhap tuoi nhan vien: \n";
		cin >> Age;
		cout << "Nhap SDT nhan vien: \n";
		cin.ignore();
		cin >> Number;
		cout << "Nhap Email nhan vien: \n";
		cin >> Email;
		cout << "Nhap luong nhan vien: \n";
		cin >> MinSalary;
	}
	virtual void Output() {
		cout << ID << '\t';
		cout << Name << '\t';
		cout << Age << '\t';
		cout << Number << '\t';
		cout << Email << '\t';
		cout << MinSalary << '\t';
	}
	ll getTotalSalary() {
		return this->TotalSalary;
	}
	void setDev(bool a) {
		a = this->Dev;
	}
	bool getDev() {
		return Dev;
	}
	bool operator < (Employees a) {
		return TotalSalary < a.TotalSalary;
	}

};
class Devs :public Employees {
protected:
	int OT;
public:
	Devs(string ID="", string Name="", int Age=0, string Number="", string Email="", ll MinSalary=0, int OT=0) :Employees(ID, Name, Age, Number, Email, MinSalary) {
		this->OT = OT;
	}
	void Input() {
		Employees::Input();
		cout << "Nhap so gio OT: \n";
		cin >> OT;
		TotalSalary = MinSalary + OT * 200000;
	}
	void Output() {
		Employees::Output();
		cout << OT << '\n';
	}


};
class Tester :public Employees {
protected:
	int Bugs;
public:
	Tester(string ID="", string Name="", int Age=0, string Number="", string Email="", ll MinSalary=0, int Bugs=0) :Employees(ID, Name, Age, Number, Email, MinSalary) {
		this->Bugs = Bugs;
	}
	void Input() {
		Employees::Input();
		cout << "Nhap so Bug: \n";
		cin >> Bugs;
		TotalSalary = MinSalary + Bugs * 50000;
	}
	void Output() {
		Employees::Output();
		cout << Bugs << '\n';
	}
};
class List {
private:
	int n;
	Employees** a;
public:
	List(int n = 0) {
		this->n = n;
		a = new Employees * [n];
	}
	~List() {
		for (int i = 0; i < n; i++) {
			delete a[i];
		}
		delete[]a;
	}
	void Input() {
		cout << "Nhap so luong nhan vien: \n";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Moi ban chon : \t 1: Dev \t 2: Tester";
			int choose;
			cin >> choose;
			switch (choose) {
			case 1:
				a[i] = new Devs();
				a[i]->Input();
				break;

			case 2:
				a[i] = new Tester();
				a[i]->Input();
				break;
			default:
				a[i] = new Employees();
				a[i]->Input();
				break;
			}
		}
	}
	void Output() {
		cout << "**DANH SACH NHAN VIEN **\n";
		for (int i = 0; i < n; i++) {
			a[i]->Output();
			cout << '\n';
		}
	}
	void LowerAvg() {
		float Avg=0.0;
		ll TotalSal=0;
		for (int i = 0; i < n; i++) {
			TotalSal += a[i]->getTotalSalary();
		}
		Avg = TotalSal / n;
		cout << "Luong trung binh cua cong ty la: " << Avg << '\n';
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() < Avg) {
				a[i]->Output();
			}
		}
	}
	void LowestSalary() {
		ll lowest = a[0]->getTotalSalary();
		for (int i = 1; i < n; i++) {
			if (a[i]->getTotalSalary() < lowest) {
				lowest = a[i]->getTotalSalary();
			}
		}
		cout << "Nhan vien co luong thap nhat:\n";
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() == lowest) {
				a[i]->Output();
			}
		}
	}
	void HighestSalary() {
		ll highest = 0;
		for (int i = 1; i < n; i++) {
			if (a[i]->getTotalSalary() > highest) {
				highest = a[i]->getTotalSalary();
			}
		}
		cout << "Nhan vien co luong cao nhat: \n";
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() == highest) {
				a[i]->Output();
			}
		}
	}
	void HighestDevsal() {
		ll highest = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() > highest && a[i]->getDev() == true) {
				highest = a[i]->getTotalSalary();
			}
		}
		cout << "Lap trinh vien co luong cao nhat la: \n";
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() == highest && a[i]->getDev()==true) {
				a[i]->Output();
			}
		}
	}
	void TesterLowestSal() {
		ll lowest;
		for (int i = 0; i < n; i++) {
			if (a[i]->getDev()==true) {
				lowest = a[i]->getTotalSalary();
				break;
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() < lowest && a[i]->getDev() == true) {
				lowest = a[i]->getTotalSalary();
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i]->getTotalSalary() == lowest) {
				a[i]->Output();
			}
		}
	}

};

int main() {
	List a;
	a.Input();
	a.Output();
	a.LowerAvg();
	a.LowestSalary();
	a.HighestSalary();
	a.TesterLowestSal();
	a.HighestDevsal();

	return 0;
}