#include <iostream>
#include <iomanip>
using namespace std;

struct Barang {
    string kode;
    string nama;
    int harga;
    int quantity;
    int jumlah;
};

struct Pelanggan {
    string nama;
    string alamat;
    string telepon;
    int jumlahBarang;
    int totalBayar;
};

int main() {
    Pelanggan p;
    int n;

    cout << "Nama Pelanggan    : ";
    cin >> p.nama;
    cout << "Alamat Pelanggan  : ";
    cin >> p.alamat;
    cout << "Telepon Pelanggan : ";
    cin >> p.telepon;

    cout << "\nBarang yang dibeli: ";
    cin >> n;

    Barang *b = new Barang[n];

    p.jumlahBarang = 0;
    p.totalBayar = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nBarang ke-" << i+1 << endl;
        cout << "Kode     : "; cin >> b[i].kode;
        cout << "Nama     : "; cin >> b[i].nama;
        cout << "Harga    : "; cin >> b[i].harga;
        cout << "Quantity : "; cin >> b[i].quantity;

        b[i].jumlah = b[i].harga * b[i].quantity;

        p.jumlahBarang += b[i].quantity;
        p.totalBayar += b[i].jumlah;
    }

    cout << "\n============================================================\n";
    cout << "                 PENJUALAN TOKO RIDHO SEJAHTERA                \n";
    cout << "============================================================\n";

    cout << "Nama Pelanggan    : " << p.nama << endl;
    cout << "Alamat Pelanggan  : " << p.alamat << endl;
    cout << "Telepon Pelanggan : " << p.telepon << endl;

    cout << "\nBarang Yang Dibeli:\n";
    cout << "------------------------------------------------------------\n";
    cout << left << setw(5) << "No"
         << setw(10) << "Kode"
         << setw(15) << "Nama"
         << setw(10) << "Harga"
         << setw(10) << "Quantity"
         << setw(10) << "Jumlah" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < n; i++) {
        cout << left << setw(5) << i+1
             << setw(10) << b[i].kode
             << setw(15) << b[i].nama
             << setw(10) << b[i].harga
             << setw(10) << b[i].quantity
             << setw(10) << b[i].jumlah << endl;
    }

    cout << "------------------------------------------------------------\n";
    cout << "Jumlah Barang Yang Dibeli = " << p.jumlahBarang << endl;
    cout << "Total Bayar               = " << p.totalBayar << endl;
    cout << "============================================================\n";

    delete[] b;

    cin.get();
}