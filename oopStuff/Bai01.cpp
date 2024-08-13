#include <iostream>
#include<string>
#include<string.h>
#define ll long long
using namespace std;

ll SumofSalary=0;
class Employees {
protected: 
    string Name;
    string Dob;
    ll Salary;
public:
    Employees(string Name = "", string Dob = "", ll Salary = 0) {
        this->Name = Name;
        this->Dob = Dob;
        this->Salary = Salary;
    }
    virtual void Input() {
        cout << "Nhap ten nhan vien: \n";
        cin.ignore();
        getline(cin, Name);
        cout << "Nhap ngay thang nam sinh: \n";
        getline(cin, Dob);
    }
    virtual void Ouput() {
        cout << "Ten nhan vien: \n";
        cout << Name << '\n';
        cout << "Ngay sinh: \n";
        cout << Dob << '\n';
        cout << "Luong: \n";
        cout << Salary << '\n';
    }
    virtual ~Employees() {

    }
};
class ProductionStaff : public Employees {
protected: 
    ll MinSalary;
    ll Products;
public:
    ProductionStaff(string Name="", string Dob="", ll Salary=0, ll MinSalary=0, ll Products=0) : Employees(Name, Dob, Salary) {
        this->MinSalary = MinSalary;
        this->Products = Products;
    }
    void Input() {
        Employees::Input();
        cout << "Nhap luong co ban: \n";
        cin >> MinSalary;
        cout << "Nhap so luong san pham: \n";
        cin >> Products;
        Salary = MinSalary + Products * 5000;
        SumofSalary += Salary;
    }
    void Ouput() {
        cout << "Nhan vien san xuat \n";
        Employees::Ouput();
        cout << "Luong co ban: \n";
        cout << MinSalary << '\n';
        cout << "So san pham: ";
        cout << Products << '\n';
    }
};
class Officer :public Employees {
protected:
    int WorkingDays;
public:
    Officer(string Name = "", string Dob = "",ll Salary=0, int WorkingDays = 0) :Employees(Name, Dob, Salary) {
        this->WorkingDays = WorkingDays;
    }
    void Input() {
        Employees::Input();
        cout << "Nhap so ngay lam viec: ";
        cin >> WorkingDays;
        Salary = WorkingDays * 100000;
        SumofSalary += Salary;
    }
    void Output() {
        cout << "Nhan vien van phong\n";
        Employees::Ouput();
        cout << "So ngay lam viec la: \n";
        cout << WorkingDays;
    }
};
class Managing {
private:
    int n;
    Employees** a;
public:
    Managing(int n=0) {
        this->n = n;
        a = new Employees * [n];
    }
    ~Managing() {
        for (int i = 0; i < n; i++) {
            delete a[i];
        }
        delete []a;
    }
    void Input() {
        cout << "Nhap so luong nhan vien: \n";
        cin >> n;
        cout << "Nhap thong tin nhan vien: \t 1: Nhan vien san xuat \t 2: Nhan vien van phong ";
        int choose = 0;
        for (int i = 0; i < n; i++) {
            cin >> choose;
            switch (choose) {
            case 1:
                a[i] = new ProductionStaff();
                a[i]->Input();
                break;
            case 2:
                a[i] = new Officer();
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
        cout << "Danh sach nhan vien: \n";
        for (int i = 0; i < n; i++) {
            a[i]->Ouput();
        }
    }
};
int main()
{
    Managing Company;
    Company.Input();
    Company.Output();
    return 0;
}

