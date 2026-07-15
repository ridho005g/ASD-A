#include <iostream>
using namespace std;

#define MAX 10

char q[MAX];

int sizeQueue() {
    int i = 0;
    while (i < MAX && q[i] != '\0') {
        i++;
    }
    return i;
}

void tampil() {
    int n = sizeQueue();

    if (n == 0) {
        cout << "Queue kosong"<<endl;
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << q[i] << " ";
    }
    cout << endl;
}

void enqueue(char data) {
    int n = sizeQueue();

    if (n == MAX) {
        cout << "Queue penuh"<<endl;
        return;
    }

    q[n] = data;
}

void dequeue() {
    int n = sizeQueue();

    if (n == 0) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Keluar: " << q[0] << endl;

    for (int i = 0; i < n - 1; i++) {
        q[i] = q[i + 1];
    }

    q[n - 1] = '\0';
}

void insertAfter(char target, char data) {
    int n = sizeQueue();

    if (n == MAX) {
        cout << "Queue penuh!\n";
        return;
    }

    int pos = -1;

    for (int i = 0; i < n; i++) {
        if (q[i] == target) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    for (int i = n; i > pos + 1; i--) {
        q[i] = q[i - 1];
    }

    q[pos + 1] = data;
}

void clearQueue() {
    for (int i = 0; i < MAX; i++) {
        q[i] = '\0';
    }
}

int main() {

    clearQueue();

    enqueue('A');
    enqueue('B');
    enqueue('C');

    cout << "Antrian Awal: ";
    tampil();

    insertAfter('A', 'D');
    cout << "a. memasukan D setelah A: ";
    tampil();

    clearQueue();
    enqueue('A');
    enqueue('B');
    enqueue('C');

    enqueue('F');
    cout << "b. F yang paling akhir dengan A, B, C hilang: ";
    tampil();
	cout << "c. soalnya sama kaya b hehe";
	cout<<endl;

    insertAfter('B', 'E');
    cout << "d. memaasukan E setelah B: ";
    tampil();

    cin.get();
}