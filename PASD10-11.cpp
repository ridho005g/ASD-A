#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

struct Node {
    Node *Left;
    char INFO;
    Node *Right;
};

typedef Node Simpul;

Simpul *Root, *P, *Current;
Simpul *Q[129];

void Inisialisasi() {
    Root = NULL;
    P = NULL;
}

void BuatSimpul(char X) {
    P = (Simpul*) malloc(sizeof(Simpul));

    if (P != NULL) {
        P->INFO = X;
        P->Left = NULL;
        P->Right = NULL;
    }
    else {
        cout << "Memory Heap Penuh" << endl;
        exit(1);
    }
}

void BuatSimpulAkar() {
    if (Root == NULL) {
        if (P != NULL) {
            Root = P;
            Root->Left = NULL;
            Root->Right = NULL;
        }
        else {
            cout << "Simpul Belum Dibuat" << endl;
        }
    }
    else {
        cout << "Pohon Sudah Ada" << endl;
    }
}

void BacaPreOrder(Simpul *Root) {
    if (Root != NULL) {
        cout << Root->INFO << " ";
        BacaPreOrder(Root->Left);
        BacaPreOrder(Root->Right);
    }
}

void BacaInOrder(Simpul *Root) {
    if (Root != NULL) {
        BacaInOrder(Root->Left);
        cout << Root->INFO << " ";
        BacaInOrder(Root->Right);
    }
}

void BacaPostOrder(Simpul *Root) {
    if (Root != NULL) {
        BacaPostOrder(Root->Left);
        BacaPostOrder(Root->Right);
        cout << Root->INFO << " ";
    }
}

int main() {

    Inisialisasi();

    BuatSimpul('R');
    BuatSimpulAkar();

    Root->Left = new Simpul;
    Root->Left->INFO = 'I';
    Root->Left->Left = NULL;
    Root->Left->Right = NULL;

    Root->Right = new Simpul;
    Root->Right->INFO = 'D';
    Root->Right->Left = NULL;
    Root->Right->Right = NULL;

    Root->Left->Left = new Simpul;
    Root->Left->Left->INFO = 'H';
    Root->Left->Left->Left = NULL;
    Root->Left->Left->Right = NULL;

    Root->Left->Right = new Simpul;
    Root->Left->Right->INFO = 'O';
    Root->Left->Right->Left = NULL;
    Root->Left->Right->Right = NULL;

    cout << "PreOrder  : ";
    BacaPreOrder(Root);
	cout<<endl;

    cout << "InOrder   : ";
    BacaInOrder(Root);
	cout <<endl;

    cout << "PostOrder : ";
    BacaPostOrder(Root);
	cout <<endl;

    cout << endl;

    getch();
    return 0;
}