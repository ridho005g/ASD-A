#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    int nilai;
    Node* next;
};

Node* top = NULL;

void push(string nama, int nilai) {
    Node* baru = new Node();
    baru->nama = nama;
    baru->nilai = nilai;
    baru->next = top;
    top = baru;
}

void tampil() {
    Node* bantu = top;

    if (top == NULL) {
        cout << "Stack kosong" <<endl;
    } else {
        cout << "TOP" <<endl;
        cout << "-----------------" <<endl;
        while (bantu != NULL) {
            cout << bantu->nama << " - " << bantu->nilai << endl;
            bantu = bantu->next;
        }
        cout << "-----------------" <<endl;
    }
}

int main() {
    push("AL", 80);
    push("Ridho", 75);
    push("Sachlan", 90);
    push("Syahbani", 85);

    cout << "Isi Stack: " <<endl;
    tampil();

    cin.get();
}