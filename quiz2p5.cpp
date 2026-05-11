#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string kode_barang;
    string nama_barang;
    int jumlah_stok;
} jumlah_stokBR;

typedef struct elm *alamatelm;

typedef struct elm {
    jumlah_stokBR Kontainer;
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

void add(string kode_barang, string nama_barang, double jumlah_stok, queue *Q) {
    elemen *info;
    info = new elemen;

    info->Kontainer.kode_barang = kode_barang;
    info->Kontainer.nama_barang = nama_barang;
    info->Kontainer.jumlah_stok = jumlah_stok;
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
            cout << "kode_barang      : " << bantu->Kontainer.kode_barang << endl;
            cout << "Nama Barangz     : " << bantu->Kontainer.nama_barang << endl;
            cout << "jumlah_stok      : " << bantu->Kontainer.jumlah_stok << " Unit" << endl;

            bantu = bantu->next;
            i++;
        }
        cout << "--r-----i------d------h-------o---\n";
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

    add("000111", "Topi", 5, &Q);
    add("000222", "Tas", 4, &Q);
    add("000333", "Kacamata", 4, &Q);
    add("000444", "Sendok", 6, &Q);
    add("000555", "Garpu", 7.7, &Q);
	
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