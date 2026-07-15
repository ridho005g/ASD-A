#include <iostream>
using namespace std;

#define MAX 5

struct Stack {
    int top;
    int data[MAX];
};

void init(Stack &S) {
    S.top = -1;
}

bool isEmpty(Stack S) {
    return S.top == -1;
}

bool isFull(Stack S) {
    return S.top == MAX - 1;
}

void push(Stack &S, int x) {
    if (isFull(S)) {
        cout << "Stack penuh\n";
    } else {
        S.top++;
        S.data[S.top] = x;
    }
}

int pop(Stack &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return -1;
    } else {
        int x = S.data[S.top];
        S.top--;
        return x;
    }
}

void tampil(Stack S) {
    if (isEmpty(S)) {
        cout << "(kosong)";
    } else {
        for (int i = S.top; i >= 0; i--) {
            cout << S.data[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    Stack S1, S2, S3;
    init(S1);
    init(S2);
    init(S3);

    // Kondisi awal (sesuai gambar)
    push(S1, 3);
    push(S1, 2);
    push(S1, 1);

    cout << "Awal:\n";
    cout << "Tumpukan 1: "; tampil(S1);
    cout << "Tumpukan 2: "; tampil(S2);
    cout << "Tumpukan 3: "; tampil(S3);

    // Contoh operasi: pindah dari S1 ke S2
    cout << "\nPindah 1 data dari T1 ke T2\n";
    push(S2, pop(S1));

    cout << "Tumpukan 1: "; tampil(S1);
    cout << "Tumpukan 2: "; tampil(S2);
    cout << "Tumpukan 3: "; tampil(S3);

    cin.get();
}