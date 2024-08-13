//Em zip file thiếu bài này bên Lab 01 Tuần 5 nên em nộp bên đây ạ :<
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Cattle
{
protected:
    int Quantity;

public:
    Cattle(int sl = 0)
    {
        Quantity = sl;
    }
    virtual void Input() = 0;
    virtual void Child() = 0;
    virtual void Milk() = 0;
    virtual void Sound() = 0;
    virtual void Static() = 0;
    virtual ~Cattle() {}
};

class Cow : public Cattle
{
public:
    Cow(int sl)
    {
        Quantity = sl;
    }
    void Child()
    {
        int sl = rand() % 10 + 1;
        Quantity += sl;
    }
    void Milk()
    {
        int sl = rand() % 20 + 1;
        cout << "Bo cho " << sl << " lit sua" << endl;
    }
    void Sound()
    {
        cout << "Bo keu: mooo" << endl;
    }
    void Input()
    {
        cout << "Nhap so luong bo: ";
        cin >> Quantity;
    }
    void Static()
    {
        cout << "So luong bo: " << Quantity << endl;
    }
};

class Sheep : public Cattle
{
public:
    Sheep(int sl)
    {
        Quantity = sl;
    }
    void Child()
    {
        int sl = rand() % 5 + 1;
        Quantity += sl;
    }
    void Milk()
    {
        int sl = rand() % 5 + 1;
        cout << "Cuu cho " << sl << " lit sua" << endl;
    }
    void Sound()
    {
        cout << "Cuu keu: Baaa " << endl;
    }
    void Input()
    {
        cout << "Nhap so luong cuu: ";
        cin >> Quantity;
    }
    void Static()
    {
        cout << "So luong cuu: " << Quantity << endl;
    }
};

class Goat : public Cattle
{
public:
    Goat(int sl)
    {
        Quantity = sl;
    }
    void Child()
    {
        int sl = rand() % 10 + 1;
        Quantity += sl;
    }
    void Milk()
    {
        int sl = rand() % 10 + 1;
        cout << "De cho " << sl << " lit sua" << endl;
    }
    void Sound()
    {
        cout << "De Sound: Maaaa" << endl;
    }
    void Input()
    {
        cout << "Nhap so luong de: ";
        cin >> Quantity;
    }
    void Static()
    {
        cout << "So luong de: " << Quantity << endl;
    }
};

class Managing
{
private:
    Cattle *a[3];

public:
    Managing()
    {
        a[0] = new Cow(0);
        a[1] = new Sheep(0);
        a[2] = new Goat(0);
    }
    void Input()
    {
        for (int i = 0; i < 3; i++)
        {
            a[i]->Input();
        }
    }
    void Child()
    {
        for (int i = 0; i < 3; i++)
        {
            a[i]->Child();
        }
    }
    void Milk()
    {
        for (int i = 0; i < 3; i++)
        {
            a[i]->Milk();
        }
    }
    void Sound()
    {
        for (int i = 0; i < 3; i++)
        {
            a[i]->Sound();
        }
    }
    void Static()
    {
        for (int i = 0; i < 3; i++)
        {
            a[i]->Static();
        }
    }
    ~Managing()
    {
        for (int i = 0; i < 3; i++)
        {
            delete a[i];
        }
    }
};

int main()
{
    srand(time(NULL));
    Managing ql;
    ql.Input();
    ql.Sound();
    ql.Child();
    ql.Milk();
    ql.Static();
    return 0;
}