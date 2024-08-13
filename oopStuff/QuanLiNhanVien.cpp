// NguoiDaHinh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#define ll long long
using namespace std;
class Employees {

protected:
	string Name;
	string Dob;
	ll MinSalary;
	ll Salary;
public:
	Employees(){ }
	Employees(string Name, string Dob, ll MinSalary) {
		this->Name = Name;
		this->Dob = Dob;
		this->MinSalary = MinSalary;
	}
	virtual ~Employees() { }
	virtual void Output()  {
		cout << "Ho ten: " << Name << '\n';
		cout << "Ngay sinh: " << Dob << '\n';
		cout << "Luong co ban: " << MinSalary << '\n';
	}
	virtual void Input(){
		cin.ignore();
		cout << "Nhap ho ten nhan vien: \n";
		getline(cin, Name);
		cout << "Nhap ngay thang nam sinh: \n";
		getline(cin, Dob);
		cout << "Nhap luong co ban: \n";
		cin >> MinSalary;
		//cout < "Luong: " << Salary;
	}
	ll getSalary() {
		return Salary;
	}
	string getName() {
		return Name;
	}
};
class Officers : public Employees {
protected:
	int WorkDays;
	int Grant;
public:
	Officers(){ }
	Officers(string Name, string Dob, ll MinSalary, int WorkDays, int Grant) : Employees(Name, Dob, MinSalary) {
		this->WorkDays = WorkDays;
		this->Grant = Grant;
	}
	~Officers(){}
	void Input() {
		Employees::Input();
		cout << "Nhap so ngay lam viec: \n";
		cin >> WorkDays;
		cout << "Nhap tien tro cap: \n";
		cin >> Grant;
		Salary = MinSalary + WorkDays * 200000 + Grant;
	}
	void Output() {
		cout << "Nhan vien van phong \n";
		Employees::Output();
		cout << "So ngay lam viec: " << WorkDays << '\n';
		cout << "Tro cap: " << Grant << '\n';
		cout << "Luong : " << Salary << '\n';
	}
	string getName() {
		return Name;
	}

};
class ProductionStaffs :public Employees {
protected:
	int Products;
public:
	ProductionStaffs(){ }
	ProductionStaffs(string Name, string Dob, ll MinSalary, int Products) : Employees(Name, Dob, MinSalary) {
		this->Products = Products;
	}
	void Input() {
		Employees::Input();
		cout << "Nhap so san pham: ";
		cin >> Products;
		Salary = MinSalary + Products * 2000;
	}
	void Output() {
		cout << "Nhap vien san xuat \n";
		Employees::Output();
		cout << "So san pham : " << Products << '\n';
		cout << "Luong : " << Salary << '\n';


	}
	string getName() {
		return Name;
	}
};
class Managers : public Employees {
protected: 
	double Coefficient;
	ll Bonus;
public:
	Managers(){ }
	Managers(string Name, string Dob, ll MinSalary, double Coefficient, ll Bonus) : Employees(Name, Dob, MinSalary) {
		this->Coefficient = Coefficient;
		this->Bonus = Bonus;
	}
	void Input() {
		Employees::Input();
		cout << "Nhap he so chuc vu: \n";
		cin >> Coefficient;
		cout << "Nhap tien thuong: \n";
		cin >> Bonus;
		Salary = MinSalary * Coefficient + Bonus;
	}
	void Output() {
		cout << "Quan ly \n";
		Employees::Output();
		cout << "He so chuc vu: " << Coefficient << '\n';
		cout << "Tien thuong: " << Bonus << '\n';
		cout << "Luong : " << Salary << '\n';
	}
	string getName() {
		return Name;
	}
};
class ListEmployees
{
private:
	Employees** List;
	int n;
	ll SumSalary=0;
public:
	ListEmployees(int n = 0)
	{
		this->n = n;
		List = new Employees * [n];
	}
	~ListEmployees()
	{
		delete[n]List;

	}
	void Input()
	{
		int Choose;
		for (int i = 0; i < n; i++)
		{
			cout << "\n Moi ban chon:  1: Nhan vien van phong, 2: Nhan vien san xuat, 3: Nhan vien quan ly ";
			cin >> Choose;
			switch (Choose)
			{
			case 1: List[i] = new Officers();
				List[i]->Input();
				SumSalary+=List[i]->getSalary();
				break;
			case 2: List[i] = new ProductionStaffs();
				List[i]->Input();
				SumSalary += List[i]->getSalary();
				break;
				SumSalary+=List[i]->getSalary();
			case 3: List[i] = new Managers();
				List[i]->Input();
				SumSalary += List[i]->getSalary();
				break;
			default: List[i] = new Employees();
				List[i]->Input(); 
				SumSalary += List[i]->getSalary();
				break;
			}

		}
	}
	void Output()
	{
		for (int i = 0; i < n; i++)
		{
			List[i]->Output();
			cout << "\n";

		}
	}
	void findEmplyees() {
		string Name;
		cin.ignore();
		getline(cin, Name);
		for (int i = 0;i < n;i++) {
			if (List[i]->getName() == Name) {
				List[i]->Output();
				cout << '\n';
			}
		}
	}
	ll getSumSalary() {
		return SumSalary;
	}
};
int main() {

	int n;
	cout << "\n Nhap so nhan vien can luu tru: "; cin >> n;
	ListEmployees a(n);
	a.Input();
	a.Output();
	cout << "Tong luong cong ty: " << a.getSumSalary() << '\n';
	cout << "Tim nhan vien: \n";
	a.findEmplyees();

}

