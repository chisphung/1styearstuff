#include<iostream>
#include<string>
#define ll long long;
using namespace std;

class HangHoa {
private:
	string tenSP;
	int soLuong;
	long long donGia;
public:
	HangHoa(string tenSP = "", int soLuong = 0, long long donGia = 0) {
		this->tenSP = tenSP;
		this->soLuong = soLuong;
		this->donGia = donGia;
	}
	~HangHoa(){}
	void Input() {
		cout << "Nhap ten san pham: \n";
		cin.ignore();
		getline(cin, tenSP);
		cout << "Nhap so luong: \n";
		cin >> soLuong;
		cout << "Nhap don gia: \n";
		cin >> donGia;
	}
	void Output() {
		cout << "Ten san pham: " << tenSP << '\n';
		cout << "So luong: " << soLuong << '\n';
		cout << "Don gia: " << donGia << '\n';
	}
	long long getdonGia() {
		return donGia;
	}
	void setDonGia(long long n) {
		n = donGia;
	}
	int  getsSoLuong() {
		return soLuong;
	}
	void setSoLuong(int n) {
		soLuong = n;
	}
};
long long tongChiPhiHD = 0;
class HoaDon {
private:
	int soHoaDon;
	string ngayHoaDon;
	HangHoa** ListHangHoa;
	long long tongTien;
	int nHangHoa;
public:
	HoaDon(int soHoaDon = 0, string ngayHoaDon = "", long long tongTien = 0,int nHangHoa=0) {
		this->soHoaDon = soHoaDon;
		this->ngayHoaDon = ngayHoaDon;
		this->tongTien = tongTien;
		this->nHangHoa = nHangHoa;
		ListHangHoa = new HangHoa * [nHangHoa];
	}
	~HoaDon() {
		for (int i = 0; i < nHangHoa; i++) {
			delete ListHangHoa[i];
		}
		delete[]ListHangHoa;
	}
	void Input() {
		cout << "Nhap so hoa don: \n";
		cin >> soHoaDon;
		cout << "Nhap ngay hoa don: \n";
		cin.ignore();
		getline(cin, ngayHoaDon);
		cout << "Nhap so luong hang hoa: \n";
		cin >> nHangHoa;
		for (int i = 0; i < nHangHoa; i++) {
			ListHangHoa[i] = new HangHoa();
			ListHangHoa[i]->Input();
			tongTien += (ListHangHoa[i]->getdonGia() * ListHangHoa[i]->getsSoLuong());
		}
	}
	void Output() {
		for (int i = 0; i < nHangHoa; i++) {
			cout << "Hoa don thu " << i + 1 << ": \n";
			cout << "So hoa don: " << soHoaDon << '\n';
			cout << "Ngay hoa don: " << ngayHoaDon << '\n';
			ListHangHoa[i]->Output();
			cout << "Tong hoa don: " << tongTien << '\n';
		}
		cout << "_________________________\n";
		cout << "Tong chi phi hoa don nay la: " << tongChiPhiHD << '\n';
	}
	long long getTongTien() {
		return tongTien;
	}
};
class ListHoaDon {
private:
	int n;
	HoaDon** a;
public:
	ListHoaDon(int n = 0) {
		this->n = n;
		a = new HoaDon * [n];
	}
	~ListHoaDon() {
		for (int i = 0; i < n; i++) {
			delete a[i];
		}
		delete[]a;
	}
	void Input() {
		cout << "Nhap so luong hoa don: \n";
		cin >> n;
		for (int i = 0; i < n; i++) {
			a[i] = new HoaDon();
			a[i]->Input();
			tongChiPhiHD += a[i]->getTongTien();
		}
	}
	void Output() {
		for (int i = 0; i < n; i++) {
			a[i]->Output();
			cout << "______________________________________\n";
			cout << "Tong so tien cong ty phai thanh toan cho hoa don la: " << tongChiPhiHD << '\n';
		}
	}
};
long long tongChiPhiLuongNV = 0;
class NhanVien {
protected:
	string HoTen;
	string DiaChi;
	string SoDienThoai;
	long long Luong;
	int LoaiNhanVien; //1: thang 2: gio 3:hoa hong
public:
	NhanVien(string HoTen = "", string DiaChi = "", string SoDienThoai = "") {
		this->HoTen = HoTen;
		this->DiaChi = DiaChi;
		this->SoDienThoai = SoDienThoai;
	}
	~NhanVien(){}
	virtual void Input() {
		cout << "Nhap ten nhan vien: \n";
		cin.ignore();
		getline(cin, HoTen);
		cout << "Nhap dia chi nhan vien: \n";
		getline(cin, DiaChi);
		cout << "Nhap so dien thoai nhan vien: \n";
		cin >> SoDienThoai;
	}
	virtual void Output() {
		cout << "Ten nhan vien: " << HoTen << '\n';
		cout << "Dia chi: " << DiaChi << '\n';
		cout << "So dien thoai: " << SoDienThoai << '\n';
	}
	long long getLuong() {
		return Luong;
	}
};
class NVtheoGio:public NhanVien {
private:
	int nGioLV;
	long long luongPerHrs;
public:
	NVtheoGio(int nGioLV = 0, long long luongPerHrs = 0) {
		this->nGioLV = nGioLV;
		this->luongPerHrs = luongPerHrs;
	}
	~NVtheoGio(){}
	void Input() {
		NhanVien::Input();
		cout << "nhap so gio lam viec trong thang: \n";
		cin >> nGioLV;
		cout << "Nhap luong theo gio: \n";
		cin >> luongPerHrs;
		Luong = nGioLV * luongPerHrs;
	}
	void Output() {
		NhanVien::Output();
		cout << "So gio lam viec trong thang: " << nGioLV << '\n';
		cout << "Luong tinh theo gio: \n" << luongPerHrs << '\n';
		cout << "Tong luong: " << Luong << '\n';
	}
};
class NVtheoThang :public NhanVien {
public:
	NVtheoThang() {};
	~NVtheoThang(){}
	void Input() {
		NhanVien::Input();
		cout << "Nhap luong trong thang cua nhan vien: \n";
		cin >> Luong;
	}
	void Output() {
		NhanVien::Output();
		cout << "Tong luong: " << Luong << '\n';
	}
};
class NVtheoHH :public NhanVien {
private:
	long long tongDThu;
	double tyLeHoaHong;
public:
	NVtheoHH(long long tongDThu = 0,int tyLeHoaHong = 0) {
		this->tongDThu = tongDThu;
		this->tyLeHoaHong = tyLeHoaHong;
	}
	void Input() {
		NhanVien::Input();
		cout << "Nhap tong doanh thu: \n";
		cin >> tongDThu;
		cout << "Nhap ty le hoa hong: \n";
		cin >> tyLeHoaHong;
		Luong = tongDThu * tyLeHoaHong/100 ;
	}
	void Output() {
		NhanVien::Output();
		cout << "Tong doanh thu: " << tongDThu << '\n';
		cout << "Ty le hoa hong: " << tyLeHoaHong << "% \n";
		cout << "Tong luong: " << Luong << '\n';
	}
};
class ListNhanVien {
private:
	int n;
	NhanVien** a;
public:
	ListNhanVien(int n=0) {
		this->n = n;
		a = new NhanVien * [n];
	}
	void Input() {
		cout << "Nhap so luong nhan vien: \n";
		cin >> n;
		for (int i = 0; i < n; i++) {
			int choose;
			cout << "Chon 1: Nhan vien linh luong theo thang \t 2: Nhan vien linh luong theo gio \t 3: Nhan vien linh luong theo hoa hong";
			cin >> choose;
			switch (choose) {
			case 1:
				a[i] = new NVtheoThang();
				a[i]->Input();
				tongChiPhiLuongNV += a[i]->getLuong();
				break;
			case 2:
				a[i] = new NVtheoGio();
				a[i]->Input();
				tongChiPhiLuongNV += a[i]->getLuong();
				break;
			case 3:
				a[i] = new NVtheoHH();
				a[i]->Input();
				tongChiPhiLuongNV += a[i]->getLuong();
				break;
			default:
				a[i] = new NhanVien();
				a[i]->Input();
				tongChiPhiLuongNV += a[i]->getLuong();
				break;
			}
		}
	}
	void Output() {
		cout << "***DANH SACH NHAN VIEN***\n";
		for (int i = 0; i < n; i++) {
			a[i]->Output();
		}
		cout << "______________________________";
		cout << "Tong chi phi cong ty tra cho nhan vien la: " << tongChiPhiLuongNV << '\n';
	}
};
int main() {
	ListHoaDon a;
	a.Input();
	a.Output();
	ListNhanVien b;
	b.Input();
	b.Output();
	return 0;
}