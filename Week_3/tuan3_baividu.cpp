#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Point {
private:
    int x, y;
public:
    Point() {
        this->x = 0;
        this->y = 0;
    }
    Point(int x) {
        this->x = x;
        this->y = 0;
    }
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    Point doiXung() const {
        return Point(-x, -y);
    }
    double Khoang_Cach_Den_0() const {
        return sqrt(pow(x, 2) + pow(y, 2));
    }
    double Khoang_Cach_Den_Diem_Bat_Ky(const Point& other) const {
        int dx = this->x - other.x;
        int dy = this->y - other.y;
        return sqrt(pow(dx, 2) + pow(dy, 2));
    }
};

class SieuNhan {
private:
    string name;
    string vu_khi;
    string mau_sac;
public:
    SieuNhan(string name, string vu_khi, string mau_sac) {
        this->name = name;
        this->vu_khi = vu_khi;
        this->mau_sac = mau_sac;
    }
    void display() {
        cout << "sieu_nhan:  " << name << "\nvu khi la:   " << vu_khi << "\nmau sac: " << mau_sac << endl;
    }
};

class List_SieuNhan {
public:
    string name, vu_khi;
    string mau_sac;
    int Chi_So_Suc_Manh;

    List_SieuNhan(string name, string vu_khi, string mau_sac, int Chi_So_Suc_Manh) {
        this->name = name;
        this->vu_khi = vu_khi;
        this->mau_sac = mau_sac;
        this->Chi_So_Suc_Manh = Chi_So_Suc_Manh;
    }
    void display() {
        cout << "[ " << name << " ]" << "||" << " Vu khi: " << vu_khi << "||" << " mau: " << mau_sac << "||" << " Chi so suc manh cua anh ay la: " << Chi_So_Suc_Manh << endl;
    }
};

int main() {
    Point A(3, 4);
    cout << "Diem A: "; A.display();

    int Xb, Yb;
    cout << "Nhap Xb: "; cin >> Xb;
    cout << "Nhap Yb: "; cin >> Yb;
    Point B(Xb, Yb);
    cout << "Diem B: "; B.display();

    Point C = B.doiXung();
    cout << "Diem C: "; C.display();

    cout << fixed << setprecision(4);
    cout << "d(B, O) = " << B.Khoang_Cach_Den_0() << endl;
    cout << "d(A, B) = " << A.Khoang_Cach_Den_Diem_Bat_Ky(B) << endl;
    cout << "_____________________________________" << endl;

    SieuNhan s1("sieu nhan xanh", "kiem", "xanh");
    s1.display();
    SieuNhan s2("sieu nhan vang", "sung", "vang");
    s2.display();
    cout << "_____________________________________" << endl;

    List_SieuNhan sn1("Captain Marvelous", "Kiem", "mau do", 999);
    sn1.display();
    List_SieuNhan sn2("Joe Gibken", "nanh vuot", "mau vang", 994);
    sn2.display();

}