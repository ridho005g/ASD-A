#include <iostream>
#include <string>
using namespace std;

struct DataBuku {
    string kodeBuku;
    string judulBuku;
    string pengarang;
};

struct Node {
    DataBuku data;
    Node* next;
};

class StackBuku {
private:
    Node* top;
    int jumlah;

public:
    StackBuku() {
        top = nullptr;
        jumlah = 0;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(DataBuku buku) {
        Node* newNode = new Node();
        newNode->data = buku;
        newNode->next = top;
        top = newNode;
        jumlah++;
        cout << "Buku [" << buku.judulBuku << "] berhasil ditambahkan ke tumpukan.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << " Tumpukan kosong! Tidak ada buku untuk diambil.\n";
            return;
        }
        Node* temp = top;
        cout << "Buku diambil: [" << top->data.judulBuku << "] oleh " << top->data.pengarang << "\n";
        top = top->next;
        delete temp;
        jumlah--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "✘ Tumpukan kosong!\n";
            return;
        }
        cout << "\n== Buku Paling Atas ==\n";
        cout << "Kode     : " << top->data.kodeBuku   << "\n";
        cout << "Judul    : " << top->data.judulBuku  << "\n";
        cout << "Pengarang: " << top->data.pengarang  << "\n";
    }

    void tampilkan() {
        if (isEmpty()) {
            cout << "umpukan kosong!\n";
            return;
        }
        cout << "\n====== ISI TUMPUKAN BUKU ======\n";
        cout << "Total: " << jumlah << " buku\n";
        cout << "-------------------------------\n";
        Node* curr = top;
        int i = 1;
        while (curr != nullptr) {
            cout << "[" << i++ << "] Kode: " << curr->data.kodeBuku
                 << " | Judul: " << curr->data.judulBuku
                 << " | Pengarang: " << curr->data.pengarang << "\n";
            curr = curr->next;
        }
        cout << "===============================\n";
    }

    ~StackBuku() {
        while (!isEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

DataBuku inputBuku() {
    DataBuku buku;
    cout << "Kode Buku    : "; cin.ignore(); getline(cin, buku.kodeBuku);
    cout << "Judul Buku   : "; getline(cin, buku.judulBuku);
    cout << "Pengarang    : "; getline(cin, buku.pengarang);
    return buku;
}

int main() {
    StackBuku stack;
    int pilihan;

    cout << "====================================== \n";
    cout << "  SISTEM TUMPUKAN BUKU PERPUSTAKAAN   \n";
    cout << "       (History Peminjaman)          \n";
    cout << "====================================\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Kembalikan Buku (Push)\n";
        cout << "2. Ambil Buku untuk Diproses (Pop)\n";
        cout << "3. Lihat Buku Paling Atas (Peek)\n";
        cout << "4. Tampilkan Semua Tumpukan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n-- Input Data Buku --\n";
                stack.push(inputBuku());
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.tampilkan();
                break;
            case 0:
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}