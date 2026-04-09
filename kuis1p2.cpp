#include <iostream>
using namespace std;

class Barang{
	public:
	atring kodeBarang;
	string namaBarang;
	int harga;
};
int main() {
	Barang brg; 
	
	cout << "Kode  Barang   : ";
    cin >> brg.kodeBarang;
    cout << "namaBarang     : ";
    cin >> brg.namaBarang;
    cout << "Harga          : ";
    cin >> brg.harga;
	
	cout <<" ===== DATA BARANG ===== " << endl;
	cout <<"Kode Barang    : " << brg.kodeBarang << endl;
	cout <<"Nama Barang	   : " << brg.namaBarang << endl;
	cout <<"Harga          : " << brg.harga << endl;

	cin.get();
}