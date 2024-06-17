#include <bits/stdc++.h>
using namespace std;

struct MonHoc {
    string monHoc;
    string maMH;
    int soTinChiMH;
    double diemQT;
    double diemCK;
    double trongSoCK;
    double diemMH;
    string ketQuaMH;
};

struct SinhVien {
    int maSV;
    string hoTenSV;
    string gioiTinh;
    int soMonHoc;
    double diemCPA; 
    string xepLoai;
    vector<MonHoc> dsMonHoc;
};

void value(SinhVien &sv) {
    double totalDiem = 0;
    int totalTinChi = 0;
    for (auto &mon : sv.dsMonHoc) {
        mon.diemMH = mon.diemCK * mon.trongSoCK + mon.diemQT * (1 - mon.trongSoCK);
        mon.ketQuaMH = (mon.diemMH > 5) ? "qua mon" : "hoc lai";
        totalDiem += mon.diemMH * mon.soTinChiMH;
        totalTinChi += mon.soTinChiMH;
    }
    sv.diemCPA = totalDiem / totalTinChi;
    
    if (sv.diemCPA >= 9) sv.xepLoai = "A+";
    else if (sv.diemCPA >= 8.5) sv.xepLoai = "A";
    else if (sv.diemCPA >= 7.5) sv.xepLoai = "B+";
    else if (sv.diemCPA >= 6.5) sv.xepLoai = "B";
    else if (sv.diemCPA >= 5) sv.xepLoai = "C";
    else if (sv.diemCPA >= 4) sv.xepLoai = "D";
    else sv.xepLoai = "F";
}

int main() {
    int luaChon;
    int soLuongSV;
    vector<SinhVien> dsSinhVien;
    
    cout << "Nhap so luong sinh vien: ";
    cin >> soLuongSV; 
    dsSinhVien.resize(soLuongSV);

    while (true) {
        cout << "Kip 2-Thu 6-Tuan 41-738920\n";
        cout << "2023.2 Nguyen Hoang Nam - 20225213" << endl;
        cout << "** CHUONG TRINH QUAN LY DIEM SINH VIEN    **" << endl;
        cout << "**1. Nhap cac SINH VIEN                   **" << endl;
        cout << "**2. In THONG TIN SV, KET QUA,..          **" << endl;
        cout << "**0. Thoat                                **" << endl;
        cout << "*******************************************" << endl;
        cout << "**       Nhap lua chon cua ban            **" << endl;
        cin >> luaChon;

        if (luaChon == 1) {
            cout << "Ban da chon nhap ds SINH VIEN!" << endl;
            for (int i = 0; i < soLuongSV; i++) {
                cout << "Nhap thong tin cua sinh vien thu " << i + 1 << " :" << endl;
                cout << "Nhap ma sinh vien: ";
                cin >> dsSinhVien[i].maSV;
                cin.ignore();
                cout << "Nhap ten SV: ";
                getline(cin, dsSinhVien[i].hoTenSV);
                cout << "Nhap so mon hoc: "; 
                cin >> dsSinhVien[i].soMonHoc;
                dsSinhVien[i].dsMonHoc.resize(dsSinhVien[i].soMonHoc);
                
                for (int j = 0; j < dsSinhVien[i].soMonHoc; j++) {
                    cout << "Nhap mon hoc thu " << j + 1 << endl;
                    cout << "Nhap ma MH: ";
                    cin >> dsSinhVien[i].dsMonHoc[j].maMH;
                    cin.ignore();
                    cout << "Nhap ten mon hoc: ";
                    getline(cin, dsSinhVien[i].dsMonHoc[j].monHoc);
                    cout << "Nhap so tin chi: ";
                    cin >> dsSinhVien[i].dsMonHoc[j].soTinChiMH;
                    cout << "Nhap trong so CK: (>0, <1): ";
                    cin >> dsSinhVien[i].dsMonHoc[j].trongSoCK;
                    cout << "Nhap diem QT: ";
                    cin >> dsSinhVien[i].dsMonHoc[j].diemQT;
                    cout << "Nhap diem CK: ";
                    cin >> dsSinhVien[i].dsMonHoc[j].diemCK;
                }
                value(dsSinhVien[i]);
            }
        } else if (luaChon == 2) {
            cout << "Ban da chon xuat DS SINH VIEN !" << endl;
            for (int i = 0; i < soLuongSV; i++) {
                cout << "\tMa SV: " << dsSinhVien[i].maSV << "   Ten sinh vien: " << dsSinhVien[i].hoTenSV << endl;
                cout << "\tSo mon hoc: " << dsSinhVien[i].soMonHoc << endl;
                cout << " \tKet qua hoc tap cac mon:" << endl;
                cout << "Ma mon hoc\tTen mon hoc\tSo tin chi\tTrong so CK\tDiem QT\tDiem CK\tDiem MH\tKet qua MH" << endl;
                for (int j = 0; j < dsSinhVien[i].soMonHoc; j++) {
                    cout << setw(7) << dsSinhVien[i].dsMonHoc[j].maMH
                         << setw(20) << dsSinhVien[i].dsMonHoc[j].monHoc
                         << setw(12) << dsSinhVien[i].dsMonHoc[j].soTinChiMH
                         << setw(10) << dsSinhVien[i].dsMonHoc[j].trongSoCK
                         << setw(10) << dsSinhVien[i].dsMonHoc[j].diemQT
                         << setw(10) << dsSinhVien[i].dsMonHoc[j].diemCK
                         << setw(10) << dsSinhVien[i].dsMonHoc[j].diemMH
                         << setw(10) << dsSinhVien[i].dsMonHoc[j].ketQuaMH << endl;
                }
                cout << "Diem CPA: " << dsSinhVien[i].diemCPA << endl;
                cout << "Xep loai: " << dsSinhVien[i].xepLoai << endl;
                cout << "Bam phim bat ky de tiep tuc!" << endl;
                getchar();
            }
        } else {
            cout << "Ban da thoat khoi chuong trinh!" << endl;
            break;
        }
    }
    return 0;
}
