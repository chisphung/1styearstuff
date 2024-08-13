#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#define ll long long
using namespace std;

class Students {
protected:
	int ID;
	string Name;
	string Address;
	int Credits;
	double Ovr;
	bool Graduated;
	bool Uni; // SV Daihoc: true, SV Caodang: false
public:
	Students(int ID=0, string Name="", string Address="", int Credits=0, double Ovr=0.0) {
		this->ID = ID;
		this->Name = Name; 
		this->Address = Address;
		this->Credits = Credits;
		this->Ovr = Ovr;
	}
	virtual ~Students() {

	}
	virtual void Input() {
		cout << "Nhap MSSV: \n";
		cin >> ID;
		cout << "Nhap ten sinh vien \n";
		cin.ignore();
		getline(cin,Name);
		cout << "Nhap dia chi sinh vien \n";
		getline(cin, Address);
		cout << "Nhap so tin chi: \n";
		cin >> Credits;
		cout << "Nhap diem trung binh: \n";
		cin >> Ovr;
	}
	virtual void Output() {
		cout << "MSSV: " << ID << '\n';
		cout << "Ten sinh vien: " << Name << '\n';
		cout << "Dia chi: " << Address << '\n';
		cout << "So tin chỉ: " << Credits << '\n';
		cout << "Diem trung binh: " << Ovr << '\n';
	}
	bool setUni(bool a) {
		Uni = a;
	}
	double getOvr() {
		return this->Ovr();
	}
	bool GetGra() {
		return Graduated;
	}
	bool getUni() {
		return Uni;
	}
	friend bool operator <(Students  &a, Students  &b) {
		return a.Ovr < b.Ovr;
	}
};
class Colle : public Students {
protected:
	double DiemTN;
public:
	Colle(int ID = 0, string Name = "", string Address = "", int Credits = 0, double Ovr = 0.0, double DiemTN=0.0) :Students(ID, Name, Address, Credits, Ovr) {
		this->DiemTN = DiemTN;
	}
	void Input() {
		Students::Input();
		cout << "Nhap diem tot nghiep: \n";
		cin >> DiemTN;
		if (Credits >= 110 && Ovr >= 5.0 && DiemTN >= 5.0) Graduated = true; else Graduated = false;
	}
	void Output() {
		cout << "Sinh vien cao dang\n";
		Students::Output();
		cout << "Diem tot nghiep: " << DiemTN<<'\n';
	}
};
class Uni : public Students {
protected:
	string EssayName;
	double EssayPoint;
public:
	Uni(int ID = 0, string Name = "", string Address = "", int Credits = 0, double Ovr = 0.0, string EssayName = "", double EssayPoint=0.0) :Students(ID, Name, Address, Credits, Ovr) {
		this->EssayName = EssayName;
		this->EssayPoint = EssayPoint;
	}
	void Input() {
		Students::Input();
		cout << "Nhap ten luan van: \n";
		cin.ignore();
		getline(cin, EssayName);
		cout << "Nhap diem luan van:\n";
		cin >> EssayPoint;
		if (Credits >= 145 && Ovr >= 5.0 && EssayPoint >= 5.0)Graduated = true; else Graduated = false;
	}
	void Output() {
		cout << "Sinh vien dai hoc\n";
		Students::Output();
		cout << "Ten luan van: " << EssayName << '\n';
		cout << "Dien luan van: " << EssayPoint << '\n';
	}
};
class Managing {
private:
	int n;
	Students** a;
public:
	Managing(int n = 0) {
		this->n = n;
		a = new Students *[n];
	}
	~Managing() {
		for (int i = 0; i < n; i++) {
			delete a[i];
		}
		delete[]a;
	}
	void Input() {
		cout << "Nhap so luong sinh vien: \n";
		cin >> n;
		int choose = 0;
		for (int i = 0; i < n; i++) {
			cout << "Chon \t 1: Cao Dang \t 2: Dai Hoc\n";
			cin >> choose;
			switch (choose) {
			case 1:
				a[i] = new Colle();
				a[i]->Input();
				a[i]->setUni(false);
				break;
			case 2:
				a[i] = new Uni();
				a[i]->Input();
				a[i]->setUni(true);
				break;
			default:
				a[i] = new Students();
				a[i]->Input();
				break;
			}
		}
	}
	void OutputFull() {
		for (int i = 0; i < n; i++) {
			a[i]->Output();
		}
	}
	void OutputGra() {
		cout << "Sinh vien du dien kien tot nghiep: \n";
		for (int i = 0; i < n; i++) {
			if (a[i]->GetGra() == true) {
				a[i]->Output();
			}
		}
	}
	void OutputUnderGra() {
		cout << "Sinh vien khong du dieu kien tot nghiep: \n";
		for (int i = 0; i < n; i++) {
			if (a[i]->GetGra() == false) {
				a[i]->Output();
			}
		}
		int countUni = 0, countColle = 0;
		for (int i = 0; i < n; i++) {
			if (a[i]->GetGra() == false) {
				if (a[i]->getUni == true) countUni++;
				if (a[i]->getUni == false) countColle++;
			}
		}
		cout << "So luong sinh vien Dai Hoc khong du dieu kien tot nghiep la: " << countUni << '\n';
		cout << "So luong sinh vien Cao Dang khong du dieu kien tot nghiep la: " >> countColle << '\n';
	}
	void HighestOvrUni() {
		sort(a, a + n);
		cout << "Sinh vien Dai Hoc co diem trung binh cao nhat: \n";
		double temp = 0;
		for (int i = n - 1; i <= 0; i--) {
			if (a[i]->getOvr() > temp && a[i]->getUni() == true) {
				temp = a[i]->getOvr();
			}
		}
		for (int i = n - 1; i <= 0; i--) {
			if (a[i]->getOvr() == temp && a[i]->getUni() == true) {
				a[i]->Output();
			}
		}
	}
	void HighestOvrColle() {
		cout << "Sinh vien Cao Dang co diem trung binh cao nhat: \n";
		double temp = 0;
		for (int i = n - 1; i <= 0; i--) {
			if (a[i]->getOvr() > temp && a[i]->getUni() == false) {
				temp = a[i]->getOvr();
			}
		}
		for (int i = n - 1; i <= 0; i--) {
			if (a[i]->getOvr() == temp && a[i]->getUni() == false) {
				a[i]->Output();
			}
		}
	}
};
int main() {
	Managing a;
	a.Input();
	a.OutputFull();
	a.OutputGra();
	a.OutputUnderGra();
	a.HighestOvrUni();
	a.HighestOvrUni();
	a.HighestOvrUni();
}