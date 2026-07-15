#include <iostream>
#include <iomanip>
using namespace std;

class Pelanggan {
public:
    string nama, alamat, kelamin, telp;
    int umur;
};

int main() {
    int n;
    Pelanggan p[100];

    cout << "INPUT DATA PELANGGAN\n";
    cout << "Jumlah pelanggan : ";
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\nNama Pelanggan Toko      : ";
        cin >> p[i].nama;
        cout << "Alamat Pelanggan Toko    : ";
        cin >> p[i].alamat;
        cout << "Umur Pelanggan Toko      : ";
        cin >> p[i].umur;
        cout << "Jenis Kelamin [L/P]      : ";
        cin >> p[i].kelamin;
        cout << "No telp Pelanggan        : ";
        cin >> p[i].telp;
    }

    cout << "\n============================================\n";
    cout << "           Data Pelanggan Toko\n";
    cout << "============================================\n";

    cout << left << setw(10) << "Nama"
         << setw(10) << "Alamat"
         << setw(8)  << "Umur"
         << setw(10) << "Kelamin"
         << setw(10) << "No telp" << endl;

    for(int i = 0; i < n; i++) {
        cout << left << setw(10) << p[i].nama
             << setw(10) << p[i].alamat
             << setw(8)  << p[i].umur
             << setw(10) << p[i].kelamin
             << setw(10) << p[i].telp << endl;
    }

    cin.get();
}