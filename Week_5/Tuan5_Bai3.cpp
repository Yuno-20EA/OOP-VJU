#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class CanBo {
private:
    string name;
    int age;
    string gender;
    string address;
public:
    CanBo(string name, int age, string gender, string address) {
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->address = address;
    }
    void setName(string name) {
        this->name = name;
    }
    void setAge(int age) {
        if (age < 0) {
            cout << "tuoi khong the am duoc vui long nhap lai" << endl;
            return;
        }
        this->age = age;
    }
    void setGender(string gender) {
        this->gender = gender;
    }
    void setAddress(string address) {
        this->address = address;
    }
    string getName() {
        if (name == "") {
            cout << "Ten khong duoc de trong" << endl;
            return "";
        }
        else {
            return name;
        }
    }
    int getAge() {
        return age;
    }
    string getGender() {
        return gender;
    }
    string getAddress() {
        return address;
    }
    virtual void display() {
        cout << "Name: "<< name << endl;
        cout << "Age: "<< age << endl;
        cout << "Gender: "<< gender << endl;
        cout << "Address: "<< address << endl;
    }
    virtual ~CanBo() = default;
};

class CongNhan : public CanBo {
private:
    int level;
public:
    CongNhan(string name, int age,string gender,string address, int level) : CanBo(name, age, gender,address) {
        this->level = level;
    }
    void setLevel(int const level) {
        this->level = level;
    }
    int getLevel() {
        if (level < 1 || level > 10) {
            cout << "khong thoa man " << endl;
            return 0 ;
        }
        else {
            return level;
        }
    }
    void display() {
        CanBo::display();
        cout << "Level: " << level << endl;
    }
};

class KySu : public CanBo {
private:
    string fieldName;
public:
    KySu(string name,int age,string gender,string address,string fieldName) : CanBo(name, age, gender, address) {
        this->fieldName = fieldName;
    }
    void setFieldName(string fieldName) {
        this->fieldName = fieldName;
    }
    string getFieldName() {
        return fieldName;
    }
    void display() {
        CanBo::display();
        cout << "Field Name: " << fieldName << endl;
    }
};

class NhanVien : public CanBo {
private:
    string job;
public:
    NhanVien(string name,int age,string gender,string address,string job) : CanBo(name,age,gender,address) {
        this->job = job;
    }
    void setJob(string job) {
        this->job = job;
    }
    string getJob() {
        return job;
    }
    void display() {
        CanBo::display();
        cout << "Job: " << job << endl;
    }
};

class QLCB {
private:
    vector<unique_ptr<CanBo>> dsCanBo;
public:
    void addCanBo() {
        string name,gender,address,adding;
        int age,loai;
        cout << "\n______Them Can Bo Moi______ "<<endl;
        cout << "1.Cong nhan || 2.Ky su || 3.Nhan vien" << endl;
        cout << "Choose your choose : " ;
        if (!(cin >> loai)) {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        cin.ignore();

        cout << "Name : "; getline(cin,name);
        cout << "Age: "; cin>>age;cin.ignore();
        cout << "Gender: "; getline(cin, gender);
        cout << "Address : "; getline(cin, address);

        if (loai == 1) {
            int bac;
            cout << "Bac 1->10 : "; cin >> bac; cin.ignore();
            dsCanBo.push_back(
                make_unique<CongNhan>(name, age, gender,address, bac)
            );
        }
        else if (loai == 2) {
            cout << "Nganh chuyen mon: ";getline(cin,adding);
            dsCanBo.push_back(
                make_unique<KySu>(name,age, gender, address, adding)
                );
        }
        else if (loai == 3) {
            cout << "cong viec la: ";getline(cin,adding);
            dsCanBo.push_back(
                make_unique<NhanVien>(name, age, gender, address, adding));
        }
        else {
            cout << "Khong hop le.Hay thu lai!" << endl;
        }
    }
    void findCanBo() {
        string tuKhoa;
        cout << "\n  Nhập họ tên cần tìm: ";
        getline(cin, tuKhoa);

        bool found = false;
        for (const auto& cb : dsCanBo) {
            if (cb->getName() == tuKhoa) {
                cout << endl;
                found = true;
                cb->display();
            }
        }
        if (!found) {
            cout << "khong tim thay can bo co ten nhu nay.Xin vui long thu lai!" << endl;
        }
    }
    void display() {
        if (dsCanBo.empty()) {
            cout << "\n  Danh sach trong!" << endl;
            return ;
        }
        else {
            cout << "\n--- DANH SACH CAN BO ---" << endl;
            for (const auto& cb : dsCanBo) {
                cb->display();
                cout << "------------------------" << endl;
            }
        }
    }

    void runcase() {
        int choice;
        do {
            cout << "-------QUAN LI DANH SACH CAN BO-------" << endl;
            cout << " ___________________________________" << endl;
            cout << "||    1.THEM MOI CAN BO             ||" << endl;
            cout << "||    2.TIM KIEM CAN BO THEO TEN    ||" << endl;
            cout << "||    3.IN DANH SACH QUA MAN HINH   ||" << endl;
            cout << "||    4.THOAT KHOI CHUONG TRINH     ||" << endl;
            cout << " ___________________________________" << endl;
            if (!(cin >> choice)) {
                cout << "Vui long chi nhap so!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cin.ignore();
            switch (choice) {
                case 1: addCanBo();   break;
                case 2: findCanBo();   break;
                case 3: display(); break;
                case 4: cout << "BAIBAI!" << endl; break;
                default: cout << " INVALID!!!!!" << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    QLCB cb;
    cb.runcase();
}