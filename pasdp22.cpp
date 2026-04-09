#include <iostream>
using namespace std;

class Mahasiswa{
	public:
	char NPM[9];
	char nama[30];
	float ipk;
};
int main() {
	Mahasiswa mhs;
	cout << "Nomor Pokok Mahasiswa	= ";cin >> mhs.NPM;
	cout << "Nama Mahasiswa			= ";cin >> mhs.nama;
	cout << "Undek prestasi Komulatif = ";cin >> mhs.ipk;
	cout << endl;
	cout <<"======================="<<endl;
	cout << "     DATA ANDA " << endl;
	cout << "======================" <<endl;
	cout << "Nomor Pokok Mahasiswa = " << mhs.NPM << endl;
	cout << "Nama Mahasiswa        = " << mhs.nama << endl;
	cout << "Indek Prestai Komulatif = " << mhs.ipk << endl;
	cin.get();
}