#include <iostream>

using namespace std;

class NhanVien {
private:
    string name_Nhan_Vien;
    double Luong_Co_Ban;
    double He_So_Luong;
public:
    static constexpr double LUONG_MAX= 500000000;

    NhanVien(string name_Nhan_Vien,double Luong_Co_ban,double He_So_Luong){
        this->name_Nhan_Vien = name_Nhan_Vien;
        this->Luong_Co_Ban = Luong_Co_ban;
        this->He_So_Luong = He_So_Luong;
    };

    string getName() {
        return name_Nhan_Vien;
    }
    double getLuong() {
        return Luong_Co_Ban;
    }
    double getHe_So() {
        return He_So_Luong;
    }

    void setName(string name_Nhan_Vien) {
        if (this->name_Nhan_Vien.empty()) {
            cout << "ten khong duoc de trong"<<endl;
        }
        this->name_Nhan_Vien = name_Nhan_Vien;
    }

    void setLuong(double Luong_Co_ban) {
        if (Luong_Co_ban < 0 ) {
            cout << "Luong co ban khong the am" << endl;
        }
        this->Luong_Co_Ban = Luong_Co_ban;
    }

    void setHe_So_Luong(double He_So_Luong) {
        if (He_So_Luong <= 0  ) {
            cout << "he so khong the am" << endl;
        }
        this->He_So_Luong = He_So_Luong;
    }

    double Luong_Nhan_Duoc() {
        return He_So_Luong*Luong_Co_Ban;
    }

    void InThongTin() {
        cout << fixed << setprecision(0);
        cout << "\n+--------------------------------------+\n"
             << "|      THONG TIN NHAN VIEN             |\n"
             << "+--------------------------------------+\n";
        cout << "| Ten : " << name_Nhan_Vien << "               |" <<  endl;
        cout << "| Luong : " << getLuong() << "VND                  |" <<  endl;
        cout <<  "| He so luong: " << He_So_Luong << "                       |" <<  endl;
        cout << "| Luong nhan duoc cuoi cung la:"  << Luong_Nhan_Duoc() << "|" << endl;
        cout << "+--------------------------------------+\n"  << endl;
    }

    bool tangLuong(double delta) {
        double LuongMoi = (Luong_Co_Ban + delta)*He_So_Luong;
        if (LuongMoi>LUONG_MAX) {
            cout << "[!] Luong moi (" << LuongMoi
                 << ") vuot LUONG_MAX. Khong tang!\n";
            return false;
        }
        else {
            Luong_Co_Ban += delta;
            cout << "[OK] Tang luong thanh cong! Luong moi: "
                 << Luong_Nhan_Duoc() << " VND\n";
            return true;
        }
    }
};

int main() {
    NhanVien nv1("Nguyen Hoang Hai",20000000,4.0);
    nv1.InThongTin();

    nv1.tangLuong(20000);
    nv1.tangLuong(800000000);
}
