#include<bits/stdc++.h>
using namespace std;

class NhanVien {
protected:
    int id;
    string HoTen;
    int tuoi;
    string sdt;
    string email;
    double LuongCanBan;

public:
    NhanVien(string ht = "", string em = "", string sdt="", int id=0, int t = 0, long lcb = 0) : HoTen(ht), email(em), sdt(sdt), id(id), tuoi(t), LuongCanBan(lcb) {}
    virtual ~NhanVien() {}
    virtual void Nhap() {
        cout << "Nhap thong tin nhan vien: " << endl;
        cin.ignore();
        cout<<"Ma nhan vien: ";
        cin>> id;
        cout << "HoTen: ";
        getline(cin, HoTen);
        cout << endl;
        cout << "Tuoi: ";
        cin >> tuoi;
        cout << endl;
        cout<<"Email :";
        cin>>email;
        cout<<endl;
        cout<<"SDT :";
        cout<<endl;
        cin.ignore();
        cout << "LuongCoBan: ";
        cin >> LuongCanBan;
        cout << endl;
    }

    virtual void Xuat() {
        cout << "--------------Thong tin Nhan Vien:----------------- " << endl
             << "Ma nhan vien :"<<id<<endl
             << "Ho ten: " << HoTen << endl
             << "Tuoi: " << tuoi << endl
             << "Email: "<<email<<endl
             << "Luong: " << LuongCanBan << endl;
    }

    virtual int TinhLuong() {
        return LuongCanBan;
    }

    string getHoTen() { return HoTen; }
};

class Laptrinhvien : public NhanVien {
private:
    int overtime;

public:
    Laptrinhvien(string ht = "", string em = "", string sdt="", int id=0, int t = 0, long lcb = 0, int ot= 0) : NhanVien(ht, em, sdt, id, t, lcb), overtime(ot) {}
    ~Laptrinhvien() {}

    void Nhap() {
        NhanVien::Nhap();
        cout << "So gio lam them: ";
        cin >> overtime;
    }

    void Xuat() {
        cout << "Lap trinh vien, "
             <<"Ma nhan vien: "<<id<< ", Ho ten: " << HoTen << ", Tuoi: " << tuoi <<", SDT: "<<sdt<<", Email: "<<email<< ", Luong: " << LuongCanBan << endl;
    }

    int TinhLuong() {
        return LuongCanBan + overtime * 200000;
    }
};

class Kiemchungvien : public NhanVien {
protected:
    int soloi;

public:
    NhanVienSanXuat(string ht = "", string em = "", string sdt="", int id=0, int t = 0, long lcb = 0, int sl=0) : NhanVien(ht, em, sdt, id, t, lcb, soloi(sl) {}

    void Nhap() {
        NhanVien::Nhap();
        cout<<"So loi duoc phat hien: ";
        cin>>soloi;
    }

    void Xuat() {
        cout << "Lap trinh vien, "
             <<"Ma nhan vien: "<<id<< ", Ho ten: " << HoTen << ", Tuoi: " << tuoi <<", SDT: "<<sdt<<", Email: "<<email<< ", Luong: " << LuongCanBan << endl;
    }

    int TinhLuong() {
        return LuongCanBan + soloi * 50000;
    }
};
class DSach {
    int n;
    int size;
    NhanVien** arr;

public:
    DSach()
    {
        n=0;
        arr = NULL;
    }
    ~DSach()
    {
        for (int i = 0; i < n; ++i) {
            delete arr[i];
        }
        delete[] arr;
    }

    void Nhap() {
        cout << "Nhap so luong nhan vien trong cong ty ABC: ";
        cin >> n;
        int temp = 0;
        arr = new NhanVien* [n];
        for (int i = 0; i < n; i++)
        {
            cout << "Nhap loai nhan vien (1.Lap trinh vien, 2.Kiem chung vien): ";
            cin >> temp;
            switch (temp)
            {
                case 1:
                    arr[i] = new Laptrinhvien();
                    break;
                case 2:
                    arr[i] = new Kiemchungvien();
                    break;
                default:
                    cout << "Loai nhan vien khong hop le. Vui long nhap lai." << endl;
                    i--;
                    continue;
            }
            arr[i]->Nhap();
        }
    }

    void XuatDS() {
        cout << "DS nhan vien la: " << endl;
        for (int i = 0; i < n; i++) {
            arr[i]->Xuat();
            cout << "Luong: " << arr[i]->TinhLuong() << endl;
            cout << endl;
        }
    }

    int TongLuong() {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i]->TinhLuong();
        }
        return sum;
    }

    double LuongTB() {
        return (double)TongLuong() / n;
    }

    void XuatNVLuongThap() {
        double luongTB = LuongTB();
        cout << "Danh sach nhan vien co luong thap hon luong trung binh: " << endl;
        for (int i = 0; i < n; i++) {
            if (arr[i]->TinhLuong() < luongTB) {
                arr[i]->Xuat();
                cout << "Luong: " << arr[i]->TinhLuong() << endl;
                cout << endl;
            }
        }
    }

    void XuatNVLuongCaoNhat() {
        int maxLuong = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i]->TinhLuong() > maxLuong) {
                maxLuong = arr[i]->TinhLuong();
                index = i;
            }
        }
        cout << "Nhan vien co luong cao nhat: " << endl;
        arr[index]->Xuat();
        cout << "Luong: " << maxLuong << endl;
    }

    void XuatNVLuongThapNhat() {
        int minLuong = arr[0]->TinhLuong();
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i]->TinhLuong() < minLuong) {
                minLuong = arr[i]->TinhLuong();
                index = i;
            }
        }
        cout << "Nhan vien co luong thap nhat: " << endl;
        arr[index]->Xuat();
        cout << "Luong: " << minLuong << endl;
    }

    void XuatLaptrinhvienLuongCaoNhat() {
        int maxLuong = 0;
        int index = 0;
        for (int i = 0; i < n; i++) {
            if (dynamic_cast<Laptrinhvien*>(arr[i])!= nullptr && arr[i]->TinhLuong() > maxLuong) {
                maxLuong = arr[i]->TinhLuong();
                index = i;
            }
        }
        cout << "Lap trinh vien co luong cao nhat: " << endl;
        arr[index]->Xuat();
        cout << "Luong: " << maxLuong << endl;
    }

    void XuatKiemchungvienLuongThapNhat() {
        int minLuong = arr[0]->TinhLuong();
        int index = 0;
        for (int i = 1; i < n; i++) {
            if (dynamic_cast<Kiemchungvien*>(arr[i])!= nullptr && arr[i]->TinhLuong() > maxLuong) {
                maxLuong = arr[i]->TinhLuong();
                index = i;
            }
        }
    }
}

int main() {
    DSach a;
    a.Nhap();
    a.XuatDS();
    a.XuatKiemchungvienLuongThapNhat();
    a.XuatLaptrinhvienLuongCaoNhat();
    a.XuatNVLuongCaoNhat();
    a.XuatNVLuongThapNhat();
    a.XuatNVLuongThap();
    return 0;
}

