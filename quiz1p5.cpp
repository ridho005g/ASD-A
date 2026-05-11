#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string nip;
    string nama_karyawan;
    double gaji;
} gajiKR;

typedef struct elm *alamatelm;

typedef struct elm {
    gajiKR Kontainer;
    alamatelm next;
} elemen;

typedef struct {
    elemen *first;
    elemen *last;
} queue;

void buatQkosong(queue *Q) {
    (*Q).first = NULL;
    (*Q).last = NULL;
}

int isKosong(queue Q) {
    bool hasil = false;
    if (Q.first == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(queue Q) {
    int hasil = 0;

    if (Q.first != NULL) {
        elemen *bantu;
        bantu = Q.first;

        while (bantu != NULL) {
            hasil = hasil + 1;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void add(string nip, string nama_karyawan, double gaji, queue *Q) {
    elemen *info;
    info = new elemen;

    info->Kontainer.nip = nip;
    info->Kontainer.nama_karyawan = nama_karyawan;
    info->Kontainer.gaji = gaji;
    info->next = NULL;

    if ((*Q).first == NULL) {
        (*Q).first = info;
    } else {
        (*Q).last->next = info;
    }
    (*Q).last = info;
}

void del(queue *Q) {
    if ((*Q).first != NULL) {
        elemen *hapus = (*Q).first;

        if (jmlElemen(*Q) == 1) {
            (*Q).first = NULL;
            (*Q).last = NULL;
        } else {
            (*Q).first = (*Q).first->next;
            hapus->next = NULL;
        }
        delete hapus;
    }
}

void CetakQueue(queue Q) {
    if (Q.first != NULL) {
        cout << "MENAMPILKAN QUEUE\n";
        elemen *bantu = Q.first;
        int i = 1;

        while (bantu != NULL) {
            cout << "-----------------------------\n";
            cout << "Elemen ke        : " << i << endl;
            cout << "nip              : " << bantu->Kontainer.nip << endl;
            cout << "Nama Karyawan    : " << bantu->Kontainer.nama_karyawan << endl;
            cout << "gaji    		  : " << bantu->Kontainer.gaji << endl;

            bantu = bantu->next;
            i++;
        }
        cout << "-----------------------------\n";
    } else {
        cout << "Queue Kosong\n";
    }
}

int main() {
    queue Q;
    buatQkosong(&Q);

    CetakQueue(Q);
    cout << endl;

    cout << "============================\n";

    add("000111", "Budi", 5.5, &Q);
    add("000222", "Susi", 4.5, &Q);
    add("000333", "Nuri", 4.5, &Q);
    add("000444", "Bimo", 6.6, &Q);
    add("000555", "Arif", 7.7, &Q);
    add("000666", "Rido", 3.3, &Q);
    add("000777", "Ella", 2.0, &Q);

    CetakQueue(Q);

    cout << "============================\n\n";

    del(&Q);
    CetakQueue(Q);

    cout << endl;

    del(&Q);
    CetakQueue(Q);

    cout << "============================\n";

    return 0;
}