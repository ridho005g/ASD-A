#include <iostream>
#include <string>
using namespace std;

struct Koordinat {
	int X;
    int Y; };

void Tampil_Posisi(Koordinat Posisi);

int main() {
	
Koordinat Posisi;
	
Posisi.X = 56;
Posisi.Y = 40;
cout<<endl;
Tampil_Posisi(Posisi);
	
cin.get();
}

void Tampil_Posisi(Koordinat Posisi) {
	cout << "posisi koordinat x adalah " << Posisi.X <<endl;
	cout << "posisi koordinat y adalah " << Posisi.Y <<endl;
}