#include <iostream>
#include <string>
using namespace std;

struct Node {
    string npm, nama;
    int nilai;
    Node* next;
};

Node* top = NULL;

bool isEmpty() {
    return top == NULL;
}

void push(string npm, string nama, int nilai) {
    Node* baru = new Node();
    baru->npm = npm;
    baru->nama = nama;
    baru->nilai = nilai;
    baru->next = top;
    top = baru;
}

void pop() {
    if (isEmpty()) {
        cout << "Stack kosong" <<endl;
    } else {
        Node* hapus = top;
        top = top->next;
        delete hapus;
    }
}

void tampil() {
    Node* bantu = top;
    if (isEmpty()) {
        cout << "Stack koson" <<endl;
    } else {
        while (bantu != NULL) {
            cout << "NPM   : " << bantu->npm << endl;
            cout << "Nama  : " << bantu->nama << endl;
            cout << "Nilai : " << bantu->nilai << endl;
            cout << "----------------------\n";
            bantu = bantu->next;
        }
    }
}

int main() {
    int n;
    string npm, nama;
    int nilai;

    cout << "Jumlah data: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "NPM   : ";
        cin >> npm;
        cout << "Nama  : ";
        cin >> nama;
        cout << "Nilai : ";
        cin >> nilai;

        push(npm, nama, nilai);
    }
	
	cout << endl;
    cout << "Data dalam Stack:" <<endl;
	cout << "======================" << endl;
    tampil();

    cin.get();;
}