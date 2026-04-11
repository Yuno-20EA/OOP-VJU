#include <iostream>
#include <numeric>   // su dung gcd
#include <vector>
#include <stdexcept> // thu vien ngoai le
#include <algorithm>
#include <cmath>

using namespace std;

// custom exception (tuy chinh ngoai le)
class MauSoBangKhong : public runtime_error {
public:
    MauSoBangKhong() : runtime_error("Loi logic: Mau so khong duoc bang 0!") {}
};

// tao lop phan so
class PhanSo {
private:
    int tu_so;
    int mau_so;
    // dam bao du lieu luon duoc chuan hoa
    void chuan_hoa() {
        if (mau_so == 0) throw MauSoBangKhong();

        // Toi gian bang UCLN
        int ucln = std::gcd(std::abs(tu_so), std::abs(mau_so));
        tu_so /= ucln;
        mau_so /= ucln;

        // dua dau am len tu so (mau so>0)
        if (mau_so < 0) {
            tu_so = -tu_so;
            mau_so = -mau_so;
        }

        // tu so bang 0 thi dua mau ve 1
        if (tu_so == 0) mau_so = 1;
    }

public:
    // Constructor vs Explicit de tranh ep kieu ngam
    explicit PhanSo(int t = 0, int m = 1) : tu_so(t), mau_so(m) {
        chuan_hoa();
    }

    // Getter
    int getTu() const { return tu_so; }
    int getMau() const { return mau_so; }

    // kiem tra toi gian
    bool is_toi_gian() const {
        return gcd(std::abs(tu_so), abs(mau_so)) == 1;
    }
    // overloading (nap chong cac toan tu)
    // toan tu so hoc
    PhanSo operator+(const PhanSo& other) const {
        return PhanSo(tu_so * other.mau_so + other.tu_so * mau_so, mau_so * other.mau_so);
    }

    PhanSo operator-(const PhanSo& other) const {
        return PhanSo(tu_so * other.mau_so - other.tu_so * mau_so, mau_so * other.mau_so);
    }

    PhanSo operator*(const PhanSo& other) const {
        return PhanSo(tu_so * other.tu_so, mau_so * other.mau_so);
    }

    PhanSo operator/(const PhanSo& other) const {
        if (other.tu_so == 0) throw runtime_error("Loi: Khong the chia cho 0!");
        return PhanSo(tu_so * other.mau_so, mau_so * other.tu_so);
    }

    // toan tu so sanh
    // dung long long tranh tran so khi nhan cheo
    bool operator<(const PhanSo& other) const {
        return (long long)tu_so * other.mau_so < (long long)other.tu_so * mau_so;
    }

    bool operator==(const PhanSo& other) const {
        return tu_so == other.tu_so && mau_so == other.mau_so;
    }

    // dinh nghiax cac toan tu con lai qua dau bang "="  va dau "<"
    bool operator>(const PhanSo& other) const { return other < *this; }
    bool operator<=(const PhanSo& other) const { return !(*this > other); }
    bool operator>=(const PhanSo& other) const { return !(*this < other); }
    bool operator!=(const PhanSo& other) const { return !(*this == other); }

    // toan tu xuat luong(friend func)
    friend ostream& operator<<(ostream& os, const PhanSo& ps) {
        if (ps.mau_so == 1) os << ps.tu_so;
        else os << ps.tu_so << "/" << ps.mau_so;
        return os;
    }
};
int main() {
    try {
        vector<PhanSo> ds_ps = {
            PhanSo(4, 6),   // 2/3
            PhanSo(3, 6),   // 1/2
            PhanSo(-2, -7), // 2/7
            PhanSo(0, 5),   // 0
            PhanSo(-4, 20)  // -1/5
        };

        cout << "--- 1. Day phan so ban dau (da tu dong toi gian) ---" << endl;
        for (const auto& ps : ds_ps) cout << ps << "  ";
        cout << "\n" << endl;

        // YC2: Thuc hien cac phep toan tren
        PhanSo a(1, 2), b(1, 3);
        cout << "cac phep toan cua hai phan so " << a << " va " << b << " ---" << endl;
        cout << a << " + " << b << " = " << a + b << endl;
        cout << a << " - " << b << " = " << a - b << endl;
        cout << a << " * " << b << " = " << a * b << endl;
        cout << a << " / " << b << " = " << a / b << endl;
        cout << "\n";

        // YC3: So sanh va sap xep
        cout << "--- 3. So sanh va Sap xep ---" << endl;
        if (PhanSo(2, 4) == PhanSo(1, 2)) {
            cout << "Xac nhan: 2/4 bang 1/2" << endl;
        }

        sort(ds_ps.begin(), ds_ps.end());
        cout << "Day phan so sau khi sap xep tang dan: " << endl;
        for (const auto& ps : ds_ps) cout << ps << "  ";
        cout << "\n" << endl;

        // YC4: kiem tra lai tinh toi gian
        PhanSo p_test(3, 7);
        cout << "--- 4. Kiem tra tinh toi gian ---" << endl;
        cout << "Phan so " << p_test << (p_test.is_toi_gian() ? " da toi gian." : " chua toi gian.") << endl;

        // validation
        cout << "\n--- 5. Test Exception (Mau so = 0) ---" << endl;
        PhanSo error_ps(5, 0);

    } catch (const MauSoBangKhong& e) {
        cerr << "LOI NGHIEP VU: " << e.what() << endl;
    } catch (const exception& e) {
        cerr << "LOI HE THONG: " << e.what() << endl;
    }
}