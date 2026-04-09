#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

class CanBo {
protected:
    string name;
    int age;
    string gender;
    string address;

public:
    CanBo(string name, int age, string gender, string address)
        : name(name), age(age), gender(gender), address(address) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getAddress() const { return address; }

    virtual void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Address: " << address << endl;
    }

    virtual ~CanBo() = default;
};

class CongNhan : public CanBo {
private:
    int level;
public:
    CongNhan(string name, int age, string gender, string address, int level)
        : CanBo(name, age, gender, address), level(level) {}

    void display() const override {
        CanBo::display();
        cout << "Level: " << level << endl;
    }
};

class KySu : public CanBo {
private:
    string fieldName;
public:
    KySu(string name, int age, string gender, string address, string fieldName)
        : CanBo(name, age, gender, address), fieldName(fieldName) {}

    void display() const override {
        CanBo::display();
        cout << "Field Name: " << fieldName << endl;
    }
};

class NhanVien : public CanBo {
private:
    string job;
public:
    NhanVien(string name, int age, string gender, string address, string job)
        : CanBo(name, age, gender, address), job(job) {}

    void display() const override {
        CanBo::display();
        cout << "Job: " << job << endl;
    }
};

class QLCB {
private:
    vector<unique_ptr<CanBo>> dsCanBo;

public:
    void addCanBo() {
        string name, gender, address, adding;
        int age, loai;

        cout << "\n______Them Can Bo Moi______ " << endl;
        cout << "1.Cong nhan || 2.Ky su || 3.Nhan vien" << endl;
        cout << "Choose: ";
        if (!(cin >> loai)) {
            cin.clear();
            cin.ignore(1000, '\n');
            return;
        }
        cin.ignore();

        cout << "Name: "; getline(cin, name);
        if (name.empty()) { cout << "Ten khong duoc de trong!\n"; return; }

        cout << "Age: ";
        if (!(cin >> age) || age < 0) {
            cout << "Tuoi khong hop le!\n";
            cin.clear(); cin.ignore(1000, '\n');
            return;
        }
        cin.ignore();

        cout << "Gender: "; getline(cin, gender);
        cout << "Address: "; getline(cin, address);

        if (loai == 1) {
            int bac;
            cout << "Level (1-10): "; cin >> bac;
            if (bac < 1 || bac > 10) { cout << "Bac khong hop le!\n"; return; }
            dsCanBo.push_back(make_unique<CongNhan>(name, age, gender, address, bac));
        }
        else if (loai == 2) {
            cout << "Nganh chuyen mon: "; cin.ignore(); getline(cin, adding);
            dsCanBo.push_back(make_unique<KySu>(name, age, gender, address, adding));
        }
        else if (loai == 3) {
            cout << "Cong viec: "; cin.ignore(); getline(cin, adding);
            dsCanBo.push_back(make_unique<NhanVien>(name, age, gender, address, adding));
        }
        else {
            cout << "Khong hop le!" << endl;
        }
    }

    void findCanBo() {
        string tuKhoa;
        cout << "\nNhập họ tên cần tìm: ";
        getline(cin, tuKhoa);

        bool found = false;
        for (const auto& cb : dsCanBo) {
            if (cb->getName() == tuKhoa) {
                if (!found) cout << "\n--- KET QUA TIM KIEM ---" << endl;
                cb->display();
                cout << "------------------------" << endl;
                found = true;
            }
        }
        if (!found) cout << "Khong tim thay can bo nay!" << endl;
    }

    void display() {
        if (dsCanBo.empty()) {
            cout << "\nDanh sach trong!" << endl;
        } else {
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
            cout << "\n-------QUAN LI DANH SACH CAN BO-------" << endl;
            cout << "1.THEM MOI | 2.TIM KIEM | 3.IN DANH SACH | 4.THOAT" << endl;
            cout << "Selection: ";
            if (!(cin >> choice)) {
                cout << "Vui long chi nhap so!" << endl;
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }
            cin.ignore();
            switch (choice) {
                case 1: addCanBo(); break;
                case 2: findCanBo(); break;
                case 3: display(); break;
                case 4: cout << "BAIBAI!" << endl; break;
                default: cout << "INVALID!!!!!" << endl;
            }
        } while (choice != 4);
    }
};

int main() {
    QLCB ql;
    ql.runcase();
}
