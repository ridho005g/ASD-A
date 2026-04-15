#include <iostream>
#include <string>
using namespace std;

typedef struct {
    string npm;
    string nama;
    double nilai;
} nilaimk;

typedef struct elm *alamattelm;
typedef struct elm {
    nilaimk kontainer;
    alamattelm next;
} elemen;

typedef struct {
    elemen *top;
} stack;

void buatSTkosong(stack *S) {
    (*S).top = NULL;
}

int isKosong(stack S) {
    bool hasil = false;
    if (S.top == NULL) {
        hasil = true;
    }
    return hasil;
}

int jmlElemen(stack S) {
    int hasil = 0;
    if (S.top != NULL) {
        elemen *bantu = S.top;
        while (bantu != NULL) {
            hasil++;
            bantu = bantu->next;
        }
    }
    return hasil;
}

void push(string npm, string nama_mhs, double nilai, stack *S) {
    elemen *info = new elemen;
    info->kontainer.npm   = npm;
    info->kontainer.nama  = nama_mhs;
    info->kontainer.nilai = nilai;

    //FIX 1: Removed wrong "Stack Penuh" message; logic is now correct
    if ((*S).top == NULL) {
        info->next = NULL;       // First element
    } else {
        info->next = (*S).top;   // Link to existing top
    }
    (*S).top = info;
    info = NULL;
}

void Pop(stack *S) {
    if ((*S).top != NULL) {
        elemen *hapus = (*S).top;
        if (jmlElemen(*S) == 1) {
            (*S).top = NULL;
        } else {
            (*S).top = (*S).top->next;
        }
        hapus->next = NULL;
        delete hapus;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void CetakStack(stack S) {
    if (S.top != NULL) {
        cout << "=== MENAMPILKAN STACK ===" << endl;
        elemen *bantu = S.top;
        int i = 1;
        while (bantu != NULL) {
            cout << "Elemen ke-" << i << endl;
            cout << "  NPM   : " << bantu->kontainer.npm   << endl;
            cout << "  Nama  : " << bantu->kontainer.nama  << endl;
            cout << "  Nilai : " << bantu->kontainer.nilai << endl;
            bantu = bantu->next;
            i++;
        }
    } else {
        cout << "Stack Kosong" << endl;
    }
}

int main() {
    stack S;
    buatSTkosong(&S);
    CetakStack(S);
    cout << endl;

    push("4523210666", "Budi", 88.75, &S);
    push("4523210777", "Susi", 78.85, &S);
    push("4523210888", "Nuri", 98.65, &S);
    push("4523210999", "Bimo", 68.55, &S);
    push("4523210555", "Arif", 78.85, &S);
    push("4523210444", "Rido", 98.65, &S);
    push("4523210222", "Ella", 68.55, &S);
    CetakStack(S);
    cout << endl;

    Pop(&S);
    CetakStack(S);
    cout << endl;

    Pop(&S);
    CetakStack(S);

    return 0;
}