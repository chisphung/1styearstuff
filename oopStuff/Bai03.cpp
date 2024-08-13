// Orientation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;

class Citizen {
protected:
	string Name;
	string Dob;
	string Gender;
public:
	Citizen(string Name = "", string Dob = "", string Gender = "") {
		this->Name = Name;
		this->Dob = Dob;
		this->Gender = Gender;
	}
	virtual ~Citizen(){}
	virtual void Input() {
		cout << "Nhap ten: \n";
		cin.ignore();
		getline(cin, Name);
		cout << "Nhap ngay sinh: \n";
		getline(cin, Dob);
		cout << "Nhap gioi tinh: \n";
		getline(cin, Gender);
	}
	virtual void Output() {
		cout << "Ten: " << Name<<'\n';
		cout << "Ngay sinh: " << Dob<<'\n';
		cout << "Gioi tinh: " << Gender << '\n';
	}
};
class Students :public Citizen {
protected:
	ll ID;
	string Uni;
	string Major;
public:
	Students(string Name = "", string Dob = "", string Gender = "", ll ID = 0, string Uni = "",string Major="") : Citizen(Name, Dob, Gender) {
		this->ID = ID;
		this->Uni = Uni;
		this->Major = Major;
	}
	void Input() {
		Citizen::Input();
		cout << "Nhap MSSV: \n";
		cin >> ID;
		cout << "Nhap truong DH: \n";
		cin.ignore();
		getline(cin, Uni);
		cout << "Nhap ten nganh: \n";
		getline(cin, Major);
	}
	void Output() {
		cout << "'\nSinh vien \n";
		Citizen::Output();
		cout << "MSSV: " << ID << '\n';
		cout << "Truong DH: " << Uni << '\n';
		cout << "Nganh: " << Major << '\n';
	}
};
class Pupils :public Citizen {
protected:
	ll ID;
	string School;
	int Grade;
public:
	Pupils(string Name = "", string Dob = "", string Gender = "", ll ID = 0, string School = "",int Grade =0):Citizen(Name,Dob,Gender) {
		this->ID = ID;
		this->School = School;
		this->Grade = Grade;
	}
	void Input() {
		Citizen::Input();
		cout << "Nhap ma hoc sinh: \n";
		cin >> ID;
		cout << "Nhap ten truong: \n";
		cin.ignore();
		getline(cin,School);
		cout << "Nhap khoi: \n";
		cin >> Grade;
	}
	void Output() {
		cout << "\n Hoc sinh\n";
		Citizen::Output();
		cout << "Ma hoc sinh: " << ID << '\n';
		cout << "Truong: " << School << '\n';
		cout << "Khoi: " << Grade << '\n';
	}
};
class Worker : public Citizen {
protected: 
	ll Salary;
	int Exp;
public:
	Worker(string Name = "", string Dob = "", string Gender = "", ll Salary = 0, int Exp = 0) :Citizen(Name, Dob, Gender) {
		this->Salary = Salary;
		this->Exp = Exp;
	}
	void Input() {
		Citizen::Input();
		cout << "Nhap luong: \n";
		cin >> Salary;
		cout << "Nhap so nam kinh nghiem: \n";
		cin >> Exp;
	}
	void Output() {
		cout << "\n Cong nhan\n";
		Citizen::Output();
		cout << "Luong: " << Salary << '\n';
		cout << "Kinh nghiem " << Exp << "nam \n";
	}
	
};
class Artist : public Worker {
protected:
	string Major;
	string PopularWith;
public:
	Artist(string Name = "", string Dob = "", string Gender = "", ll Salary = 0, int Exp = 0, string Major = "", string PopularWith = "") :Worker(Name, Dob, Gender, Salary, Exp) {
		this->Major = Major;
		this->PopularWith = PopularWith;
	}
	void Input() {
		Worker::Input();
		cout << "Nhap ten nganh: \n";
		cin.ignore();
		getline(cin, Major);
		cout << "Nhap cong trinh nghe thuat: \n";
		getline(cin, PopularWith);
	}
	void Output() {
		cout << "\n Nghe si \n";
		Worker::Output();
		cout << "Nganh: " << Major << '\n';
		cout << "Cong trinh nghe thuat: " << PopularWith << '\n';
	}
};
class Singer :public Worker {
protected:
	string Hitsongs;
public:
	Singer(string Name = "", string Dob = "", string Gender = "", ll Salary = 0, int Exp = 0, string Major = "", string Hitsongs = "") :Worker(Name, Dob, Gender, Salary, Exp) {
		this->Hitsongs = Hitsongs;
	}
	void Input() {
		Worker::Input();
		cout << "Nhap bai hat noi tieng: \n";
		cin.ignore();
		getline(cin, Hitsongs);
	}
	void Output() {
		cout << "\n Ca si \n";
		Worker::Output();
		cout << "Noi tieng voi bai hat: " << Hitsongs << '\n';
	}
};
class Managing {
private: 
	int n;
	Citizen** a;
public:
	Managing(int n=0) {
		this->n = n;
		a = new Citizen * [n];
	}
	void Input() {
		cout << "Nhap so luong cong dan: \n";
		cin >> n;
		for (int i = 0; i < n; i++) {
			cout << "Chon \t 1: Sinh vien \t 2: Hoc sinh \t 3: Cong nhan \t 4: Nghe si \t 5: Ca si \n";
			int Choose;
			cin >> Choose;
			switch (Choose) {
			case 1: {
				a[i] = new Students();
				a[i]->Input();
				break;
			}
			case 2: {
				a[i] = new Pupils();
				a[i]->Input();
				break;
			}
			case 3: {
				a[i] = new Worker();
				a[i]->Input();
				break;
			}
			case 4: {
				a[i] = new Artist();
				a[i]->Input();
				break;
			}
			case 5: {
				a[i] = new Singer();
				a[i]->Input();
				break;
			}
			default: {
				a[i] = new Citizen();
				a[i]->Input();
				break;
			}
			}
		}
	}
	void Output() {
		for (int i = 0; i < n; i++) {
			a[i]->Output();
			cout << '\n';
		}
	}
	~Managing() {
		for (int i = 0; i < n; i++) {
			delete a[i];
		}
		delete[]a;
	}
};
int main() {
	Managing a;
	a.Input();
	a.Output();
	return 0;
}

