// 4.	Tạo một danh sách các đối tượng, mỗi đối tượng thuộc một trong 
// các loại: sinh viên, học sinh, công nhân, nghệ sĩ, ca sĩ.
//  Viết chương trình cho phép nhập danh sách kể trên, in thông tin của từng đối tượng trong danh sách.

#include <iostream>
#include <string>
using namespace std;

class cDoiTuong
{
protected:
    string hoTen;
    string ngaySinh;
    string queQuan;

public:
    cDoiTuong(string ht = "", string ns = "", string qq = "") : hoTen(ht), ngaySinh(ns), queQuan(qq) {}
    virtual void Nhap()
    {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoTen);
        cout << "Nhap ngay sinh: ";
        cin >> ngaySinh;
        cout << "Nhap que quan: ";
        cin.ignore();
        getline(cin, queQuan);
    }
    virtual void Xuat()
    {
        cout << hoTen << "\t" << ngaySinh << "\t" << queQuan << "\t";
    }
    virtual ~cDoiTuong() {}
};

class cSinhVien : public cDoiTuong
{
protected:
    string maSV;
    int tongSoTC;
    float diemTB;

public:
    cSinhVien(string ma = "", int tc = 0, float dtb = 0) : maSV(ma), tongSoTC(tc), diemTB(dtb) {}
    void Nhap()
    {
        cDoiTuong::Nhap();
        cout << "Nhap ma sinh vien: ";
        cin.ignore();
        getline(cin, maSV);
        cout << "Nhap tong so tin chi: ";
        cin >> tongSoTC;
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }
    void Xuat()
    {
        cDoiTuong::Xuat();
        cout << maSV << "\t" << tongSoTC << "\t" << diemTB << "\t";
    }
    ~cSinhVien() {}
};

class cHocSinh: public cDoiTuong
{
protected:
    string maHS;
    string lop;
    float diemTB;

public:
    cHocSinh(string ma = "", string l = "", float dtb = 0) : maHS(ma), lop(l), diemTB(dtb) {}
    void Nhap()
    {
        cDoiTuong::Nhap();
        cout << "Nhap ma hoc sinh: ";
        cin.ignore();
        getline(cin, maHS);
        cout << "Nhap lop: ";
        getline(cin, lop);
        cout << "Nhap diem trung binh: ";
        cin >> diemTB;
    }
    void Xuat()
    {
        cDoiTuong::Xuat();
        cout << maHS << "\t" << lop << "\t" << diemTB << "\t";
    }
    ~cHocSinh() {}
};

class cCongNhan: public cDoiTuong
{
protected:
    string maCN;
    int soSP;

public:
    cCongNhan(string ma = "", int sp = 0) : maCN(ma), soSP(sp) {}
    void Nhap()
    {
        cDoiTuong::Nhap();
        cout << "Nhap ma cong nhan: ";
        cin.ignore();
        getline(cin, maCN);
        cout << "Nhap so san pham: ";
        cin >> soSP;
    }
    void Xuat()
    {
        cDoiTuong::Xuat();
        cout << maCN << "\t" << soSP << "\t";
    }
    ~cCongNhan() {}
};

class cNgheSi: public cDoiTuong
{
protected:
    string maNS;
    string nghe;

public:
    cNgheSi(string ma = "", string n = "") : maNS(ma), nghe(n) {}
    void Nhap()
    {
        cDoiTuong::Nhap();
        cout << "Nhap ma nghe si: ";
        cin.ignore();
        getline(cin, maNS);
        cout << "Nhap nghe: ";
        getline(cin, nghe);
    }
    void Xuat()
    {
        cDoiTuong::Xuat();
        cout << maNS << "\t" << nghe << "\t";
    }
    ~cNgheSi() {}
};

class cCaSi: public cDoiTuong
{
protected:
    string maCS;
    string Soalbum;

public:
    cCaSi(string ma = "", string sa = "") : maCS(ma), Soalbum(sa) {}
    void Nhap()
    {
        cDoiTuong::Nhap();
        cout << "Nhap ma ca si: ";
        cin.ignore();
        getline(cin, maCS);
        cout << "Nhap so album: ";
        getline(cin, Soalbum);
    }
    void Xuat()
    {
        cDoiTuong::Xuat();
        cout << maCS << "\t" << Soalbum << "\t";
    }
    ~cCaSi() {}
};

class cDSDT
{
    cDoiTuong **a;
    int n;

public:
    cDSDT()
    {
        a = NULL;
        n = 0;
    }
    void Nhap()
    {
        cout << "Nhap so doi tuong: ";
        cin >> n;
        a = new cDoiTuong *[n];
        for (int i = 0; i < n; i++)
        {
            int loai;
            cout << "Nhap loai doi tuong (1. Sinh vien, 2. Hoc sinh, 3. Cong nhan, 4. Nghe si, 5. Ca si): ";
            cin >> loai;
            switch (loai)
            {
            case 1:
                a[i] = new cSinhVien();
                break;
            case 2:
                a[i] = new cHocSinh();
                break;
            case 3:
                a[i] = new cCongNhan();
                break;
            case 4:
                a[i] = new cNgheSi();
                break;
            case 5:
                a[i] = new cCaSi();
                break;
            default:
                break;
            }
            a[i]->Nhap();
        }
    }
 void Xuat()
{
    for (int i = 0; i < n; i++)
    {
        a[i]->Xuat();
        cout << endl;
    }
}
~cDSDT()
{
    for (int i = 0; i < n; i++)
    {
        delete a[i];
    }
    delete[] a;
}
};

int main()
{
    cDSDT ds;
    ds.Nhap();
    ds.Xuat();
    return 0;
}