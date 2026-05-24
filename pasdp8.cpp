#include <iostream>
using namespace std;

int Search01(int A[], int, int);
int main()
{

    int JmlElemenArray;

    cout << "|-----------------------------|" << endl;
    cout << "| Algoritma dan Struktur Data |" << endl;
    cout << "| Ridho Sachlan - 4525210066  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|      Sequential Search      |" << endl;
    cout << "|-----------------------------|" << endl;
	cout <<endl;
	cout << "masukan jumlah kendaraan : " ; cin >> JmlElemenArray;
	int tika[JmlElemenArray];
    //gotoxy(1,5);
    cout << "         Isi data nya adalah" << endl;
    cout << "-----------------------------------------" << endl;
    cout << endl;
    for(int count=0; count<JmlElemenArray; count++)
    {
        cout << "\t"<< "Data [" << count << "]" << "--> " ; cin >> tika[count];
    }
    int SearchElemen = 0;
    int flaq=0;
    cout << "-----------------------------------------" <<endl;
    cout << endl;
    cout << "Masukkan data yang akan Anda cari ?     "; cin >> SearchElemen;
    flaq = Search01(tika, JmlElemenArray, SearchElemen);
    if(flaq != -1)
        cout << "Data yang dicari ditemukan pada posisi : Data["<< flaq <<"]"<<endl;
    else
        cout << "Data yang Anda cari tidak ditemukan" << endl;
    cin.get();
    return 0;
}
int Search01(int tika[],int JmlElemenArray, int Elemen)
{
    int flaq = -1;
    for(int count=0; count<JmlElemenArray; count++)
    {
        if(Elemen==tika[count])
        {
            flaq=count;
            break;
        }
    }
    return flaq;
}