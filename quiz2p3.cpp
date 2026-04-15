#include <iostream>
using namespace std;

struct Node {
    int nomorAntrian;
    Node* next;
};

struct Queue {
    Node* front = nullptr;
    Node* rear  = nullptr;
    int jumlah  = 0;

    bool isEmpty() { return front == nullptr; }

    void enqueue(int nomor) {
        Node* newNode = new Node{nomor, nullptr};
        if (isEmpty()) front = rear = newNode;
        else { rear->next = newNode; rear = newNode; }
        jumlah++;
        cout << " Nomor antrian " << nomor << " masuk antrian.\n";
    }

    void dequeue() {
        if (isEmpty()) { cout << "Antrian kosong!\n"; return; }
        Node* temp = front;
        cout << " Nomor antrian " << front->nomorAntrian << " dipanggil.\n";
        front = front->next;
        if (!front) rear = nullptr;
        delete temp;
        jumlah--;
    }

    void peek() {
        if (isEmpty()) { cout << "Antrian kosong!\n"; return; }
        cout << ">> Antrian paling depan: " << front->nomorAntrian << "\n";
    }

    void tampilkan() {
        if (isEmpty()) { cout << "Antrian kosong!\n"; return; }
        cout << "\n[DEPAN] ";
        Node* curr = front;
        while (curr) { cout << curr->nomorAntrian << " -> "; curr = curr->next; }
        cout << "[BELAKANG] | Total: " << jumlah << "\n";
    }
};

int main() {
    Queue q;
    int pilihan, nomor;

    cout << "=== SISTEM ANTRIAN LOKET PEMBAYARAN ===\n";
    do {
        cout << "\n1. Ambil Nomor Antrian\n2. Panggil Pelanggan\n3. Lihat Depan\n4. Tampilkan Semua\n0. Keluar\nPilihan: ";
        cin >> pilihan;

        if      (pilihan == 1) { cout << "Nomor antrian: "; cin >> nomor; q.enqueue(nomor); }
        else if (pilihan == 2) q.dequeue();
        else if (pilihan == 3) q.peek();
        else if (pilihan == 4) q.tampilkan();
        else if (pilihan == 0) cout << "Selesai.\n";
        else                   cout << "Pilihan tidak valid!\n";

    } while (pilihan != 0);
}
