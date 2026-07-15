#include <iostream>
using namespace std;

struct RIDHO {
	string nama;
	string alamat;
	int tahun_lahir;
	float tinggi;
	string pekerjaan;
	string nomor_sim;
	string masa_berlaku;

};

int main() {
	RIDHO data;
	
	cout <<"-Input Data SIM" << endl;
	
	cout <<"Nama         : ";
	getline(cin, data.nama);
	
	cout <<"Alamat       : ";
	getline(cin, data.alamat);
	
	cout <<"Tahun Lahir  : ";
	cin >> data.tahun_lahir;
	
	cout <<"Tinggi (cm)  : ";
	cin >> data.tinggi;
	cin.ignore();
	
	cout <<"Pekerjaan    : ";
	getline(cin, data.pekerjaan);
	
	cout <<"Nomor SIM    : ";
	getline(cin, data.nomor_sim);
	
	cout <<"Masa Berlaku : ";
	getline(cin, data.masa_berlaku);
	
	cout <<" ===== DATA SIM ===== " << endl;
	cout <<"Nama         : " << data.nama << endl;
	cout <<"Alamat       : " << data.alamat << endl;
	cout <<"Tahun Lahir  : " << data.tahun_lahir << endl;
	cout <<"Tinggi       : " << data.tinggi << "  cm" << endl;
	cout <<"Pekerjaan    : " << data.pekerjaan << endl;
	cout <<"Nomor SIM    : " << data.nomor_sim << endl;
	cout <<"Masa Berlaku : " << data.masa_berlaku << endl;

	cin.get();
}