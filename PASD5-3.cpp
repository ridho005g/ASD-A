#include <iostream>
using namespace std;

struct Node {
    string npm, nama;
    int nilai;
    Node* next;
};

class Queue {
private:
    Node *depan, *belakang;

public:
    Queue() {
        depan = belakang = NULL;
    }

    bool kosong() {
        return depan == NULL;
    }

    void enqueue(string npm, string nama, int nilai) {
        Node* baru = new Node;
        baru->npm = npm;
        baru->nama = nama;
        baru->nilai = nilai;
        baru->next = NULL;

        if (kosong()) {
            depan = belakang = baru;
        } else {
            belakang->next = baru;
            belakang = baru;
        }

        cout << "data telah ditambahkan"<<endl;
		cout<<endl;
    }

    void dequeue() {
        if (kosong()) {
            cout << "queue masi kosong" <<endl;
            return;
        }

        Node* hapus = depan;

        cout << "data keluar: "
             << hapus->npm << " - "
             << hapus->nama << " - "
             << hapus->nilai << endl;

        depan = depan->next;
        delete hapus;

        if (depan == NULL) {
            belakang = NULL;
        }
    }

    void tampil() {
        if (kosong()) {
            cout << "data kosong"<<endl;
            return;
        }

        Node* bantu = depan;
        cout << "isi queue:" <<endl;
        while (bantu != NULL) {
            cout << bantu->npm << " - "
                 << bantu->nama << " - "
                 << bantu->nilai << endl;
            bantu = bantu->next;
        }
    }
};

int main() {
    Queue q;
    int pilih;
    string npm, nama;
    int nilai;

    do {
        cout << "menu:	"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Liat Data" <<endl;
        cout << "4. Keluar" <<endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "NPM  : "; cin >> npm;
            cout << "nama : "; cin >> nama;
            cout << "nilai: "; cin >> nilai;
            q.enqueue(npm, nama, nilai);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.tampil();
            break;

        case 4:
            cout << "Selesai"<<endl;
            break;

        default:
            cout << "Pilihan salah"<<endl;
        }

    } while (pilih != 4);

    cin.get();
}