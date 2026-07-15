// AKAS AYNUP

#include <iostream>
using namespace std;

struct Node {
    string nama;
    Node *next;
};

Node *front = NULL, *rear = NULL;

void enqueue(string nama) {
    Node *baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (front == NULL) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
}

void tampil() {
    Node *bantu = front;
    while (bantu != NULL) {
        cout << bantu->nama << " ";
        bantu = bantu->next;
    }
    cout << endl;
}

int main() {

    enqueue("A");
    enqueue("B");
    enqueue("C");
	

    cout << "antrian awal: ";
    tampil();

    Node *baru = new Node;
    baru->nama = "D";
    baru->next = front->next;
    front->next = baru;

    cout << "(A) : ";
    tampil();

    front = rear = NULL;
    enqueue("A");
    enqueue("B");
    enqueue("C");

    while (front != NULL) {
        Node *hapus = front;
        front = front->next;
        delete hapus;
    }
    rear = NULL;

    enqueue("F");

    cout << "(B) : ";
    tampil();

    cout << "(C) : ";
    tampil();

    front = rear = NULL;
    enqueue("A");
    enqueue("B");
    enqueue("C");

    Node *bantu = front;
    while (bantu != NULL && bantu->nama != "B") {
        bantu = bantu->next;
    }

    if (bantu != NULL) {
        Node *baru2 = new Node;
        baru2->nama = "E";
        baru2->next = bantu->next;
        bantu->next = baru2;
    }

    cout << "(D) : ";
    tampil();

    cin.get();
}