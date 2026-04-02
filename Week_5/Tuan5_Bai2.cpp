#include <iostream>
#include <string>

using namespace std;

const double Luong_ban_dau = 5000000;

class NhanVien {
private:
    string name;
    int nam_sinh;
    string gender;
    string address;
    double He_so_luong;
    double Luong_max;
public:
    NhanVien(string name, int nam_sinh, string gender, string address, double He_so_luong, double Luong_max) {
        this->name = name;
        this->nam_sinh = nam_sinh;
        this->gender = gender;
        this->address = address;
        this->He_so_luong = He_so_luong;
        this->Luong_max = Luong_max;
    }
    void setName(string name) {
        this->name = name;
    }
    void setNamsinh(int nam_sinh) {
        this->nam_sinh = nam_sinh;
    }
    void setGender(string gender) {
        this->gender = gender;
    }
    void setAddress(string address) {
        this->address = address;
    }
    void setHe_so_luong(double He_so_luong) {
        this->He_so_luong = He_so_luong;
    }
    void setLuong_max(double Luong_max) {
        this->Luong_max = Luong_max;
    }
    string getName() const { // Thêm const ở đây
        return this->name;
    }
    int getNamsinh() const { // Thêm const ở đây
        return this->nam_sinh;
    }
    string getGender() const { // Thêm const ở đây
        return this->gender;
    }
    string getAddress() const { // Thêm const ở đây
        return this->address;
    }
    double getHe_so_luong() const { // Thêm const để hàm tinhLuong() gọi được
        return this->He_so_luong;
    }
    double getLuong_max() const { // Bổ sung hàm này vì code dưới có dùng
        return this->Luong_max;
    }
    virtual double tinhLuong() const {
        double luong = Luong_ban_dau * He_so_luong;
        if (luong > Luong_max) {
            return Luong_max;
        }
        return luong;
    }
    virtual void display() {
        cout << "name: " << this->name << endl;
        cout << "nam_sinh: " << this->nam_sinh << endl;
        cout << "gender: " << this->gender << endl;
        cout << "address: " << this->address << endl;
        cout << "Luong: " << (long long)tinhLuong() << " VND" << endl;
    }
    virtual ~NhanVien() = default;
};

class CongTacVien : public NhanVien {
private:
    string thoi_han_hop_dong;
    int phu_cap;
public:
    CongTacVien(string name, int nam_sinh, string gender, string address, double He_so_luong, double Luong_max, string thoi_han_hop_dong, int phu_cap)
        : NhanVien(name, nam_sinh, gender, address, He_so_luong, Luong_max) {
        this->thoi_han_hop_dong = thoi_han_hop_dong;
        this->phu_cap = phu_cap;
    }
    void setThoiHan(string thoi_han_hop_dong) {
        this->thoi_han_hop_dong = thoi_han_hop_dong;
    }
    void setPhuCap(int phu_cap) {
        this->phu_cap = phu_cap;
    }
    string getThoiHan() const {
        return this->thoi_han_hop_dong;
    }
    int getPhuCap() const {
        return this->phu_cap;
    }
    double tinhLuong() const override {
        double luong = (Luong_ban_dau * getHe_so_luong()) + phu_cap;
        if (luong > getLuong_max()) {
            return getLuong_max();
        }
        return luong;
    }
    void display() override {
        NhanVien::display();
        cout << "Thoi han hop dong la: " << this->thoi_han_hop_dong << endl;
        cout << "phu_cap: " << this->phu_cap << endl;
    }
};

class NhanVienChinhThuc : public NhanVien {
private:
    string vi_tri;
public:
    NhanVienChinhThuc(string name, int nam_sinh, string gender, string address, double He_so_luong, double Luong_max, string vi_tri)
        : NhanVien(name, nam_sinh, gender, address, He_so_luong, Luong_max) {
        this->vi_tri = vi_tri;
    }
    void setVi_tri(string vi_tri) {
        this->vi_tri = vi_tri;
    }
    string getVi_tri() const {
        return this->vi_tri;
    }
    void display() override {
        NhanVien::display();
        cout << "vi tri: " << this->vi_tri << endl;
    }
};

class TruongPhong : public NhanVien {
private:
    string ngay_tiep_quan;
    int khoan_phu_cap;
public:
    TruongPhong(string name, int nam_sinh, string gender, string address, double He_so_luong, double Luong_max, string ngay_tiep_quan, int khoan_phu_cap)
        : NhanVien(name, nam_sinh, gender, address, He_so_luong, Luong_max) {
        this->ngay_tiep_quan = ngay_tiep_quan;
        this->khoan_phu_cap = khoan_phu_cap;
    }
    void setNgay_tiep_quan(string ngay_tiep_quan) {
        this->ngay_tiep_quan = ngay_tiep_quan;
    }
    string getNgay_tiep_quan() const {
        return this->ngay_tiep_quan;
    }
    void setKhoanPhuCap(int khoan_phu_cap) {
        this->khoan_phu_cap = khoan_phu_cap;
    }
    int getKhoanPhuCap() const {
        return this->khoan_phu_cap;
    }
    double tinhLuong() const override {
        double luong = (Luong_ban_dau * getHe_so_luong()) + khoan_phu_cap;
        if (luong > getLuong_max()) {
            return getLuong_max();
        }
        return luong;
    }
    void display() override {
        NhanVien::display();
        cout << "Ngay tiep quan: " << this->ngay_tiep_quan << endl;
        cout << "khoan phu cap: " << this->khoan_phu_cap << endl;
    }
};

int main() {
    cout << "---------------Bang Quan Li Nhan Vien---------------" << endl;

    CongTacVien ctv1("Dong Quoc Trong", 2007, "Nam", "Thanh Hoa", 0.8, 5000000, "28/03/2027", 200000);
    ctv1.display();

    cout << "______________________________________________________" << endl;

    NhanVienChinhThuc nv1("Tran Duc Anh Minh", 2007, "gay", "Nam Dinh", 1.5, 10000000, "bao ve nha xe");
    nv1.display();

    cout << "______________________________________________________" << endl;

    TruongPhong tp1("Nguyen Hoang Hai", 2007, "Nam", "Hai Duong", 5.0, 50000000, "31/3/2026", 5000000);
    tp1.display();

    return 0;
}