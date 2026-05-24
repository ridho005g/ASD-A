#include <iostream>
using namespace std;

int sequentialSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int n;
	
    cout << "|-----------------------------|" << endl;
    cout << "| Algoritma dan Struktur Data |" << endl;
    cout << "| Ridho Sachlan - 4525210066  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "|      Sequential Search      |" << endl;
    cout << "|-----------------------------|" << endl;
	cout <<endl;

    cout << "Masukkan jumlah kendaraan: ";
    cin >> n;

    if (n <= 0) {
        cout << "Jumlah kendaraan harus lebih dari 0!" << endl;
        return 1;
    }

    int kendaraan[n]; 

    cout << "Masukkan " << n << " nomor kendaraan:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data [" << i << "] --> ";
        cin >> kendaraan[i];
    }

    cout << "------------------------------" << endl;
    cout << "Data parkiran saat ini:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Data [" << i << "] --> " << kendaraan[i] << endl;
    }

    int cari;
    cout << "------------------------------" << endl;
    cout << "Masukkan nomor kendaraan yang ingin dicari: ";
    cin >> cari;

    int posisi = sequentialSearch(kendaraan, n, cari);

    if (posisi != -1) {
        cout << "Data ditemukan pada posisi index ke-" << posisi << " Data[" << posisi << "]" << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    cin.ignore();
    cin.get();    
    return 0;
}