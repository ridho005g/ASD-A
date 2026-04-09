#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struktur data untuk buku
struct Buku {
    string judul;
};

// Kelas Stack untuk mengelola tumpukan buku
class StackBuku {
private:
    static const int MAKS = 5;  // Kapasitas maksimal stack
    Buku stack[MAKS];           // Array untuk menyimpan buku
    int top;                    // Indeks elemen teratas
    
public:
    // Constructor
    StackBuku() {
        top = -1;  // Stack kosong
    }
    
    // Cek apakah stack kosong
    bool isEmpty() {
        return top == -1;
    }
    
    // Cek apakah stack penuh
    bool isFull() {
        return top == MAKS - 1;
    }
    
    // PUSH: Menambah buku ke tumpukan
    void push(string judul) {
        if (isFull()) {
            cout << "\n Stack PENUH! Tidak bisa menambah buku.\n";
            cout << "   Kapasitas maksimal " << MAKS << " buku.\n";
            return;
        }
        
        top++;
        stack[top].judul = judul;
        cout << "\n Buku \"" << judul << "\" berhasil ditambahkan ke tumpukan.\n";
    }
    
    // POP: Mengambil buku dari tumpukan (LIFO)
    void pop() {
        if (isEmpty()) {
            cout << "\n Stack KOSONG! Tidak ada buku yang bisa diambil.\n";
            return;
        }
        
        cout << "\n Mengambil buku \"" << stack[top].judul << "\" dari tumpukan.\n";
        top--;
        cout << " Buku berhasil diambil (POP).\n";
    }
    
    // DISPLAY: Menampilkan semua isi stack
    void display() {
        cout << "\n========================================\n";
        cout << "         ISI TUMPUKAN BUKU\n";
        cout << "========================================\n";
        
        if (isEmpty()) {
            cout << "          [ STACK KOSONG ]\n";
        } else {
            cout << "   Posisi    |       Judul Buku\n";
            cout << "----------------------------------------\n";
            for (int i = top; i >= 0; i--) {
                cout << "   Ke-" << (top - i + 1) << " (Top)  | " << stack[i].judul << endl;
                if (i > 0) {
                    cout << "   Ke-" << (top - i + 2) << "        | \n";
                }
            }
            cout << "----------------------------------------\n";
            cout << "   Total buku: " << (top + 1) << " / " << MAKS << endl;
        }
        cout << "========================================\n";
    }
    
    // Menampilkan informasi kapasitas stack
    void infoKapasitas() {
        cout << "\n Informasi Stack:\n";
        cout << "   - Kapasitas maksimal: " << MAKS << " buku\n";
        cout << "   - Buku saat ini: " << (top + 1) << " buku\n";
        cout << "   - Sisa slot: " << (MAKS - (top + 1)) << " buku\n";
    }
};

// Fungsi untuk menampilkan menu utama
void tampilkanMenu() {
    cout << "     MENU STACK PERPUSTAKAAN      \n";
    cout << "  1. PUSH (Tambah Buku)           \n";
    cout << "  2. POP (Ambil Buku)             \n";
    cout << "  3. DISPLAY (Lihat Tumpukan)     \n";
    cout << "  4. Info Kapasitas               \n";
    cout << "  5. Keluar                       \n";
    cout << "Pilihan Anda: ";
}

int main() {
    StackBuku perpustakaan;
    int pilihan;
    string judulBuku;
    
    cout << "\n PROGRAM STACK TUMPUKAN BUKU\n";
    cout << "   (Konsep LIFO - Last In First Out)\n";
    cout << "   Kapasitas maksimal: 5 Buku\n";
    
    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();  // Membersihkan buffer
        
        switch(pilihan) {
            case 1: // PUSH
                cout << "\n Masukkan judul buku: ";
                getline(cin, judulBuku);
                if (!judulBuku.empty()) {
                    perpustakaan.push(judulBuku);
                } else {
                    cout << "\n Judul buku tidak boleh kosong!\n";
                }
                break;
                
            case 2: // POP
                perpustakaan.pop();
                break;
                
            case 3: // DISPLAY
                perpustakaan.display();
                break;
                
            case 4: // Info Kapasitas
                perpustakaan.infoKapasitas();
                break;
                
            case 5: // Keluar
                cout << "\n Terima kasih telah menggunakan program ini!\n";
                break;
                
            default:
                cout << "\n Pilihan tidak valid! Silakan pilih 1-5.\n";
                break;
        }
        
    } while(pilihan != 5);
    
    return 0;
}