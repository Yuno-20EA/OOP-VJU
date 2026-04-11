#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

// Custom Exceptions
class GiaKhongHopLe : public runtime_error {
public:
    GiaKhongHopLe(const string& msg) : runtime_error(msg) {}
};

class MaHangTrungLap : public runtime_error {
public:
    MaHangTrungLap(const string& msg) : runtime_error(msg) {}
};

// Abstract Base Class
class HangHoa {
protected: // dung protected de lop con  truy cap duoc con ben ngoai thi khong
    string Ma_hang;
    string ten_hang;
    string nha_sx;
    double gia;

public:
    HangHoa(string Ma_hang, string ten_hang, string nha_sx, double gia)
        : Ma_hang(Ma_hang), ten_hang(ten_hang), nha_sx(nha_sx) {
        setGia(gia);
    }

    string getMaHang() const { return Ma_hang; }
    string getTenHang() const { return ten_hang; }

    void setGia(double gia) {
        if (gia < 0) {
            throw GiaKhongHopLe("Gia khong the am. Vui long nhap lai!!");
        }
        this->gia = gia;
    }

    double getGia() const { return gia; }

    // phuong thuc ao
    virtual string loai_hang() const = 0;
    virtual void display() const = 0;

// Overload toan tu
    bool operator==(const HangHoa& other) const {
        return this->Ma_hang == other.Ma_hang;
    }

    bool operator<(const HangHoa& other) const {
        return this->gia < other.gia;
    }

    virtual ~HangHoa() = default;
};

// Subclasses
class HangDienMay : public HangHoa {
    double thoi_gian_bao_hanh, dien_ap, cong_suat;
public:
    HangDienMay(string ma, string ten, string nsx, double g, double tgbh, double da, double cs)
        : HangHoa(ma, ten, nsx, g), thoi_gian_bao_hanh(tgbh), dien_ap(da), cong_suat(cs) {}

    string loai_hang() const override { return "Dien may"; }
    void display() const override {
        cout << "[" << loai_hang() << "] " << Ma_hang << " | " << ten_hang << " | " << gia << " VND" << endl;
    }
};

class HangSanhSu : public HangHoa {
    string loai_nguyenlieu;
public:
    HangSanhSu(string ma, string ten, string nsx, double g, string nl)
        : HangHoa(ma, ten, nsx, g), loai_nguyenlieu(nl) {}

    string loai_hang() const override { return "Sanh su"; }
    void display() const override {
        cout << "[" << loai_hang() << "] " << Ma_hang << " | " << ten_hang << " | " << gia << " VND" << endl;
    }
};

class HangThucPham : public HangHoa {
    string ngaysx,ngayhh;
public:
    HangThucPham(string ma,string ten,string nsx,double g,string ngaysx,string ngayhh) :HangHoa(ma,ten,nsx,g) , ngaysx(ngaysx),ngayhh(ngayhh){}

    string loai_hang() const override{return "Thuc Pham";};
    void display() const override {
        cout << "[" << loai_hang() << "] " << Ma_hang << " | " << ten_hang << " | " << gia << " VND" << endl;
    }
};

//  context manager (RAII)
class QuanLiKho {
private:
    vector<HangHoa*> ds;
    string file_name;

public:
    QuanLiKho(string file_name) : file_name(file_name) {
        cout << "Bat dau phien lam viec. Mo file: " << file_name << endl;
    }

    void addingHangHoa(HangHoa* hangHoa) {
        for (auto item : ds) {
            // so sanh noi dung qua toan tu == da overloading
            if (*item == *hangHoa) {
                delete hangHoa; // giai phong bo nho
                throw MaHangTrungLap("Ma hang " + hangHoa->getMaHang() + " da ton tai!");
            }
        }
        ds.push_back(hangHoa);
    }

    void display() {
        // sap xep dua tren nhung toan tu da duoc overloading
        sort(ds.begin(), ds.end(), [](HangHoa* a, HangHoa* b) {
            return *a < *b;
        });
        for (auto hangHoa : ds) {
            hangHoa->display();
        }
    }

    ~QuanLiKho() {
        ofstream f(file_name);
        if (f.is_open()) {
            for (auto h : ds) f << h->getMaHang() << "," << h->getTenHang() << endl;
            f.close();
            cout << "--- Da luu " << ds.size() << " mat hang vao " << file_name << " ---" << endl;
        }
        for (auto h : ds) delete h; // thu hoi no nho
    }
};

int main() {
    try {
        QuanLiKho kho("kho_hang.txt");

        // Lưu ý: thứ tự tham số phải khớp với Constructor
        kho.addingHangHoa(new HangDienMay("DM01", "Tu lanh", "Samsung", 5000, 12, 220, 100));
        kho.addingHangHoa(new HangSanhSu("SS02", "Bat su", "Bat Trang", 2000, "Su trang"));
        kho.addingHangHoa(new HangThucPham("TP36","rau ma dau xanh","tiem me gau",100,"31/3/2026","8/4/2026"));

        cout << "\nDanh sach hang hoa (da sap xep theo gia):" << endl;
        kho.display();

    } catch (const exception& e) {
        cerr << "\nLOI: " << e.what() << endl;
    }
}