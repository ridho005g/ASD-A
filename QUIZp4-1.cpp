#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100
#define true 1
#define false 0

struct pelanggan {
	string id ;
    char nama[20];
    string TB;
};

struct pelanggan plggn;
struct pelanggan queue[MAX];
void init(void);
int full(void);
int empty(void);
struct pelanggan entridata(void);
void enqueue(struct pelanggan plggn);
struct pelanggan dequeue(void);
void display(struct pelanggan plggn);
void baca(void);
int awal, akhir;
char nocomment[10];

int main() {
    char pilih;
    cout << "== Program Entri Pelanggan==\n";
    init();
    do {
        cout << "MENU PILIHAN :\n";
        cout << "1. Input Data Pelanggan\n";
        cout << "2. Hapus Data pelanggan\n";
        cout << "3. Lihat Daftar Pelanggan\n";
        cout << "4. Hapus Semua Data\n";
        cout << "5. Selesai.\n";
        cout << "Pilih 1 sd 5 : ";
        cin >> pilih;
        switch (pilih) {
            case '1' : plggn = entridata(); enqueue(plggn); break;
            case '2' : cout << "\nData yang dihapus :\n";
                       plggn = dequeue(); display(plggn); break;
            case '3' : baca(); break;
            case '4' : init(); cout << "\nData telah dikosongkan\n";
                       break;
            case '5' : break;
            default  : cout << "Pilih 1 sd 5!";
                       break;
        }
        cout << "\n";
    } while (pilih != '5');
    return 0;
}

void init(void) {
    awal  = -1;
    akhir = -1;
}

void enqueue(struct pelanggan plggn) {
    if (empty() == true) {
        awal  = 0;
        akhir = 0;
        queue[awal] = plggn;
    } else if (full() != true) {
        akhir++;
        queue[akhir] = plggn;
    } else cout << "Queue sudah penuh... \n";
}

struct pelanggan dequeue(void) {
    int i;
    if (empty() != true) {
        plggn = queue[awal];
        for (i = awal; i <= akhir; i++)
            queue[i] = queue[i+1];
        akhir--;
        return(plggn);
    } else cout << "Queue kosong...\n";
    return plggn;
}

int full(void) {
    if (akhir == MAX-1) return(true);
    else return(false);
}

int empty(void) {
    if (akhir == -1) return(true);
    else return(false);
}

void baca(void) {
    int i;
    cout << "\nIsi Queue : \n";
    if (empty() != true) {
        for (i = awal; i <= akhir; i++) {
            display(queue[i]);
        }
    } else cout << "Data kosong.";
    cout << "\n";
}

struct pelanggan entridata(void) {
    struct pelanggan plggn;
    cout << "\n";
	cout << "Masukkan id : "; cin >> plggn.id;
    cout << "Masukkan Nama : "; cin >> plggn.nama;
	cout << "Masukkan Total belanja : "; cin >> plggn.TB;
    return(plggn);
}

void display(struct pelanggan plggn) {
    cout << "\n";
    cout << "id : " << plggn.id << "\n";
	cout << "Nama : " << plggn.nama << "\n";
	cout << "Total belanja : Rp" << plggn.TB << "\n";
    
}