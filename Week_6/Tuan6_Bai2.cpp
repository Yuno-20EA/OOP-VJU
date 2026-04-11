#include <algorithm>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

// 1.Custom exceptions
class TuoiKhongHopLe : public runtime_error {
public:
    TuoiKhongHopLe() :
        runtime_error("Loi.Tuoi khong hop le!!(tuoi nen nam trong khoang tu 18 den 65)") {}
};
 class CapBacKhongHopLe : public runtime_error {
 public:
     CapBacKhongHopLe() :
        runtime_error("Loi.Cap bac khong hop le!!(nen nam trong khoang tu 1 den 10)") {}
 };

// 2.Xay dung abstract base class
class CanBo {
private:
    string name;
    int age;
    string gender;
    string address;
public:
    CanBo(string name, int age, string gender, string address) :
        name(name), age(age), gender(gender), address(address) {
        setAge(age);
    }
    virtual ~CanBo() = default;
    void setAge(int age) {
        if (age < 18 || age > 65) throw TuoiKhongHopLe();
        this->age=age;
    }
    int getAge() {return age;}
    void setName(string name) {
        this->name = name;
    }
    string getName() {return name;}
    void setGender(string gender) {
        this->gender = gender;
    }
    string getGender() {return gender;}
    void setAddress(string address) {
        this->address = address;
    }
    string getAddress() {return address;}
    //pure virtual method (ham thuan ao:chi goi de khai bao chu khong co tinh nang thuc hien)
    virtual void description() const =0;

    //da hinh hoa toan tu
    virtual void display(ostream& os) const {
        os << "Ho va ten: " << name << "||" << "Tuoi: " << age << "||" << "Gender: " << gender << "||" << "Address: " << address << endl;
    }
    //overloading (sap xep theo abc)
    bool operator==(const CanBo& other) const {
        return (this->name == other.name) && (this->age == other.age);
    }
    //overloading toan tu in ra ban hinh
    friend ostream& operator<<(ostream& os, const CanBo& can_bo) {
        can_bo.display(os);
        return os;
    }
};
//cac lop con
class CongNhan :public CanBo {
private:
    int level;
public:
    CongNhan(string name, int age, string gender, string address, int level) : CanBo(name, age, gender, address) , level(level) {
        setLevel(level);
    }
    void setLevel(int level) {
        if (level <  1 || level > 10) throw CapBacKhongHopLe();
        this->level = level;
    }
    //override
    void description() const override {
        cout << "[Cong Nhan] Toi dang lam viec o xuong" << level << endl;
    }
    void display(ostream& os) const override {
        CanBo::display(os);
        os << " || Bac: " << level << endl;
    }
};

class KySu :public CanBo {
private:
    string fieldName;
public:
    KySu(string name,int age,string gender,string address,string fieldName) : CanBo(name, age, gender, address) , fieldName(fieldName) {}
    void description() const override {
        cout << "[Ky Su]  toi dang lam viec o lab" << endl;
    }
    void display(ostream& os) const override {
        CanBo::display(os);
        os << " || Nganh: " << fieldName << endl;
    }
};

class NhanVien :public CanBo {
private:
    string cong_viec;
public:
    NhanVien(string name,int age,string gender,string address,string cong_viec) : CanBo(name, age, gender, address) , cong_viec(cong_viec) {}
    void description() const override {
        cout << "[Nhan Vien]  Toi lam viec o van phong" << endl;
    }
    void display(ostream& os) const override {
        CanBo::display(os);
        os << " || Cong viec la: " << cong_viec << endl;
    }
};
enum class LoaiCB {CongNhan = 1,KySu = 2,NhanVien = 3};

class QLCB {
private:
    vector<unique_ptr<CanBo>> dsCanBo;

    string tolower(string s) const {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        return s;
    }
public:
    void addingCanBo() {
        try {
            int choice;
            cout << "\n THEM CAN BO MOI " << endl;
            cout << "  1. Cong nhan  2. Ky su  3. Nhan vien\n  Chon: ";
            if (!(cin >> choice)) throw invalid_argument("Lua chon phai la cac so (1,2,3)");
            cin.ignore();

            string name, gender, address;
            cout << "  Ho va ten: ";    getline(cin, name);
            cout << "  Tuoi: ";      int age; cin >> age; cin.ignore();
            cout << "  Gioi tinh: "; getline(cin, gender);
            cout << "  Dia chi: ";   getline(cin, address);

            unique_ptr<CanBo> cb;
            string extra;

            switch (static_cast<LoaiCB>(choice)) {
                case LoaiCB::CongNhan: {
                    int level;
                    cout << "Bac(1-10): ";cin >> level;cin.ignore();
                    cb = make_unique<CongNhan>(name,age,gender,address,level);
                    break;
                }
                case LoaiCB::KySu: {
                    cout << "Nganh: ";getline(cin,extra);
                    cb = make_unique<KySu>(name,age,gender,address,extra);
                    break;
                }
                case LoaiCB::NhanVien: {
                    cout << "Cong Viec: ";getline(cin,extra);\
                    cb = make_unique<NhanVien>(name,age,gender,address,extra);
                    break;
                }
                default: {
                    cout << "Khong ton tai loai can bo tren" << endl;
                    return;
                }
            }
            dsCanBo.push_back(move(cb));
            cout << "Da them thanh cong!!"  << endl;
        }
        catch (exception& e) {
            cerr <<  "Loi!!" << e.what() << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    void TimCanBo() {
        string keyword;
        cout << "Nhap tu khoa de tim kiem: ";getline(cin,keyword);
        string keywordlow = tolower(keyword);

        bool found = false;
        for (const auto& cb : dsCanBo) {
            if (tolower(cb->getName()).find(keywordlow) != string::npos) {
                cout << "     " << *cb;
                found = true;
            }
            else {
                cout << "Khong tim thay can bo co ten nhu vay" << endl;
            }
        }
    }
    void display(ostream& os) const {
        if (dsCanBo.empty()) {
            cout  << "\n Danh sach hien tai dang trong."  << endl;
            return;
        }
        cout << "\n ---DANH SACH CAC CAN BO---" << endl;
        for (const auto& cb : dsCanBo) {
            cb->description();
            cout << "    " << *cb;
        }
    }
    void runcase() {
        int chon;
        while (true) {
            cout << "HE THONG QUAN LY" << endl;
            cout << "1. Them moi | 2. Tim kiem | 3. Hien thi | 4. Thoat\nLua chon: ";
            if (!(cin>>chon)) {
                cin.clear();cin.ignore(1000,'\n');
                continue;
            }
            cin.ignore();
            if (chon == 4) break;
            switch (chon) {
                case 1:addingCanBo();
                    break;
                case 2:TimCanBo();
                    break;
                case 3:
                    display(cout);
                    break;
                default:
                    cout << "Lua chon khong hop le!!!"  << endl;
            }
        }
    }
};

int main() {
    QLCB ql;
    ql.runcase();
}