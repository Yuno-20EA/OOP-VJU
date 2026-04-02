#include <iostream>

using namespace std;

class HangHoa {
private:
    string Ma_hang;
    string ten_hang;
    string nha_sx;
    double gia;
public:
    HangHoa(string Ma_hang, string ten_hang,string nha_sx, double gia) {
        this->Ma_hang = Ma_hang;
        this->ten_hang = ten_hang;
        this->nha_sx = nha_sx;
        this->gia = gia;
    }
    void setMaHang(string Ma_hang) {
        this->Ma_hang = Ma_hang;
    }
    string getMaHang() {
        return this->Ma_hang;
    }
    void setTenHang(string ten_hang) {
        this->ten_hang = ten_hang;
    }
    string getTenHang() {
        return this->ten_hang;
    }
    void setNhaSx(string nha_sx) {
        this->nha_sx = nha_sx;
    }
    string getNhaSx() {
        return this->nha_sx;
    }
    void setGia(double gia) {
        this->gia = gia;
    }
    double getGia() {
        return this->gia;
    }
    void display() {
        cout << "Ma hang: " << this->getMaHang() << endl;
        cout << "ten hang: " << this->getTenHang() << endl;
        cout << "nha sx: " << this->getNhaSx() << endl;
        cout << "gia: " <<this->getGia() << " Vnd"<< endl;
    }

    virtual ~HangHoa() = default;
};

class HangDienMay : public HangHoa {
private:
    double thoi_gian_bao_hanh;
    double dien_ap;
    double cong_suat;
public:
    HangDienMay(string ma_hang,string ten_hang,string nha_sx,double gia,double thoi_gian_bao_hanh,double dien_ap,double cong_suat) : HangHoa(ma_hang,ten_hang,nha_sx,gia) {
        this->thoi_gian_bao_hanh = thoi_gian_bao_hanh;
        this->dien_ap = dien_ap;
        this->cong_suat = cong_suat;
    }
    void setTG(double thoi_gian_bao_hanh) {
        this->thoi_gian_bao_hanh = thoi_gian_bao_hanh;
    }
    void setDienAp(double dien_ap) {
        this->dien_ap = dien_ap;
    }
    void setCongSuat(double cong_suat) {
        this->cong_suat = cong_suat;
    }
    double getTG() {
        return this->thoi_gian_bao_hanh;
    }
    double getDienAp() {
        return this->dien_ap;
    }
    double getCongSuat() {
        return this->cong_suat;
    }
    void display() {
        HangHoa::display();
        cout << "thoi gian bao hanh la: "<<this->getTG() << " thang" << endl;
        cout << "dien ap la: " << this->getDienAp() << " V"<< endl;
        cout << "cong suat la: " << this->getCongSuat() << " W" << endl;
    }
};

class HangSanhSu : public HangHoa {
private:
    string loai_nguyenlieu;
public:
    HangSanhSu(string ma_hang,string ten_hang,string nha_sx,double gia,string loai_nguyenlieu) : HangHoa(ma_hang,ten_hang,nha_sx,gia) {
        this->loai_nguyenlieu = loai_nguyenlieu;
    }
    void setType(string loai_nguyenlieu) {
        this->loai_nguyenlieu = loai_nguyenlieu;
    }
    string getType() {
        return this->loai_nguyenlieu;
    }
    void display() {
        HangHoa::display();
        cout << "loai_nguyenlieu: " << this->getType() << endl;
    }
};

class HangThucPham : public HangHoa {
private:
    string nsx;
    string nhh;
public:
    HangThucPham(string ma_hang,string ten_hang,string nha_sx,double gia,string nsx,string nhh) : HangHoa(ma_hang,ten_hang,nha_sx,gia) {
        this->nsx = nsx;
        this->nhh = nhh;
    }
    void setNsx(string nsx) {
        this->nsx = nsx;
    }
    void setNhh(string nhh) {
        this->nhh = nhh;
    }
    string getNsx() {
        return this->nsx;
    }
    string getNhh() {
        return this->nhh;
    }
    void display() {
        HangHoa::display();
        cout << "nsx: " << this->nsx << endl;
        cout << "nhh: " << this->nhh << endl;
    }
};

int main() {
    HangDienMay dm1("DM_Xanh_001","Tu lanh","Funiki",200000,12,220,110);
    dm1.display();
    cout << "____________________________" << endl;

    HangSanhSu ss1("LS002","bat su tu thoi nha Thanh","khong ro",100000,"su nguyen chat");
    ss1.display();
    cout << "____________________________" << endl;
    HangThucPham tp1("Do uong tot cho suc khoe","rau ma dau xanh","Rau ma mix",50000,"31/3/2026","4/4/2026");
    tp1.display();
}