#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama_mhs;
    double nilai;
} NilaiMK;

typedef struct {
    int first;
    int last;
    NilaiMK Dat[10];
} queue;

void buatQUkosong(queue *Q) {
    (*Q).first = -1;
    (*Q).last  = -1;
}

bool isKosong(queue Q) {
    return Q.first == -1;
}

bool isPenuh(queue Q) {
    return Q.last == 9;
}

void ADD(queue *Q) {
    string npm, nama_mhs;
    double nilai;

    cout << "Masukkan NPM   : ";
    cin >> npm;
    cout << "Masukkan Nama  : ";
    cin >> nama_mhs;
    cout << "Masukkan Nilai : ";
    cin >> nilai;

    if (isPenuh(*Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    if (isKosong(*Q)) {
        (*Q).first = 0;
        (*Q).last  = 0;
    } else {
        (*Q).last++;
    }

    (*Q).Dat[(*Q).last].npm      = npm;
    (*Q).Dat[(*Q).last].nama_mhs = nama_mhs;
    (*Q).Dat[(*Q).last].nilai    = nilai;
    
	cout<<endl;
    cout << "Data berhasil ditambahkan" <<endl;
	cout<< "-------------------------------" << endl;
}

void DEL(queue *Q) {
    if (isKosong(*Q)) {
        cout << "Queue kosong" <<endl;
        return;
    }
    
    cout << "Data keluar: " << (*Q).Dat[(*Q).first].nama_mhs << endl;
    cout <<endl;
	
    if ((*Q).first == (*Q).last) {
        (*Q).first = -1;
        (*Q).last  = -1;
    } else {
        for (int i = (*Q).first + 1; i <= (*Q).last; i++) {
            (*Q).Dat[i - 1] = (*Q).Dat[i];
        }
        (*Q).last--;
    }
}

void CetakQueue(queue Q) {
    if (isKosong(Q)) {
        cout << "Queue Kosong"<<endl;
        return;
    }

    cout << "MENAMPILKAN QUEUE"<< endl;
    cout << "===========================" << endl;

    for (int i = Q.first; i <= Q.last; i++) {
        cout << "Index              : " << i << endl;
        cout << "NPM                : " << Q.Dat[i].npm << endl;
        cout << "Nama Mahasiswa     : " << Q.Dat[i].nama_mhs << endl;
        cout << "Nilai              : " << Q.Dat[i].nilai << endl;
        cout << "==========================" <<endl;
    }
}

int main() {
    queue Q;
    buatQUkosong(&Q);

    int pilih;

    do {
        cout << "MENU QUEUE" <<endl;
        cout << "1. Enqueue" <<endl;
        cout << "2. Dequeue" <<endl;
        cout << "3. Tampil queue" <<endl;
        cout << "4. Exit" <<endl;
        cout << "Pilih : ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                ADD(&Q);
                break;
            case 2:
                DEL(&Q);
                break;
            case 3:
                CetakQueue(Q);
                break;
        }

    } while (pilih != 4);

    cin.get();
}