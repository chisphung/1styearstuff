#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class GiaSuc {
protected:
    int soLuong;
    string tiengKeu;
    int luongSua;
    int luongCon;
public:
    virtual void Input() {
        cout << "Nhap so luong: ";
        cin >> soLuong;
    }
    virtual void keu() = 0;
    virtual void sinhCon() = 0;
    virtual void choSua() = 0;
    void Output() {
        cout << "Tieng keu: " << tiengKeu << '\n';
        cout << "Luong con sau sinh: " << luongCon << '\n';
        cout << "Luong sua: " << luongSua << '\n';
    }
    int getSoLuong() {
        return soLuong;
    }
    int getLuongSua() {
        return luongSua;
    }
    int getLuongCon() {
        return luongCon;
    }
};

class Bo : public GiaSuc {
public:
    void Input()  {
        GiaSuc::Input();
    }
    void keu()  {
        tiengKeu = "Um Bo";
    }
    void sinhCon()  {
        luongCon = rand() % 5 + 1;
    }
    void choSua()  {
        luongSua = rand() % 21;
    }
};

class Cuu : public GiaSuc {
public:
    void Input()  {
        GiaSuc::Input();
    }
    void keu()  {
        tiengKeu = "Be Be";
    }
    void sinhCon()  {
        luongCon = rand() % 3 + 1;
    }
    void choSua()  {
        luongSua = rand() % 6;
    }
};

class De : public GiaSuc {
public:
    void Input()  {
        GiaSuc::Input();
    }
    void keu()  {
        tiengKeu = "E E";
    }
    void sinhCon()  {
        luongCon = rand() % 4 + 1;
    }
    void choSua()  {
        luongSua = rand() % 11;
    }
};

struct Node {
    GiaSuc* data;
    Node* next;
    Node(GiaSuc* x) : data(x), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    void Add(GiaSuc* x) {
        Node* newNode = new Node(x);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void Input() {
        GiaSuc* bo = new Bo();
        bo->Input();
        bo->keu();
        bo->sinhCon();
        bo->choSua();
        Add(bo);

        GiaSuc* de = new De();
        de->Input();
        de->keu();
        de->sinhCon();
        de->choSua();
        Add(de);

        GiaSuc* cuu = new Cuu();
        cuu->Input();
        cuu->keu();
        cuu->sinhCon();
        cuu->choSua();
        Add(cuu);
    }

    void Output() {
        Node* temp = head;
        while (temp != nullptr) {
            temp->data->Output();
            temp = temp->next;
        }
    }

    int TongSoLuong() {
        int total = 0;
        Node* temp = head;
        while (temp != nullptr) {
            total += temp->data->getSoLuong();
            temp = temp->next;
        }
        return total;
    }

    int TongLuongSua() {
        int total = 0;
        Node* temp = head;
        while (temp != nullptr) {
            total += temp->data->getLuongSua();
            temp = temp->next;
        }
        return total;
    }
};

int main() {
    srand(time(0));

    LinkedList danhSach;
    danhSach.Input();

    cout << "Thong ke gia suc: " << endl;
    danhSach.Output();

    cout << "Tong so luong gia suc: " << danhSach.TongSoLuong() << endl;
    cout << "Tong luong sua: " << danhSach.TongLuongSua() << endl;

    return 0;
}
