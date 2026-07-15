#include <iostream>
using namespace std;

struct Data {
    int nilai;
};

int Search01(Data data[], int JmlElemenArray, int Elemen);

int main() {

    int JmlElemenArray;

    cout << "|-----------------------------|" << endl;
    cout << "| Algoritma dan Struktur Data |" << endl;
    cout << "| Ridho Sachlan - 4525210066  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|      Sequential Search      |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << endl;

    cout << "Masukan Jumlah Data : ";
    cin >> JmlElemenArray;

    Data data[JmlElemenArray];

    for (int i = 0; i < JmlElemenArray; i++) {
        cout << "Data ke " << i + 1 << " : ";
        cin >> data[i].nilai;
    }

    cout << endl;
    cout << "|       Isi Data Adalah       |" << endl;
    cout << "|-----------------------------|" << endl;

    for (int count = 0; count < JmlElemenArray; count++) {
        cout << "Data [" << count + 1 << "] : "
             << data[count].nilai << endl;
    }

    cout << endl;

    int SearchElemen;
    int flaq;

    cout << "Masukkan Data Yang Akan Dicari : ";
    cin >> SearchElemen;

    flaq = Search01(data, JmlElemenArray, SearchElemen);

    if (flaq != -1)
        cout << "Data ditemukan pada posisi : Data[" 
             << flaq << "]" << endl;
    else
        cout << "Data tidak ditemukan" << endl;

    cin.ignore();
    cin.get();
    return 0;
}

int Search01(Data data[], int JmlElemenArray, int Elemen) {

    int flaq = -1;

    for (int count = 0; count < JmlElemenArray; count++) {

        if (Elemen == data[count].nilai) {
            flaq = count + 1;
            break;
        }
    }

    return flaq;
}