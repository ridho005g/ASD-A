#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef struct _node {
    char *nama;
    char *desc;
    struct _node *next;
} node;

#define HASHSIZE 5
static node *hashtab[HASHSIZE];

void inithashtab() {
    int i;
    for (i = 0; i < HASHSIZE; i++)
        hashtab[i] = NULL;
}

unsigned int myHash(char *s) {
    unsigned int h = 0;
    for (; *s; s++)
        h = *s + h * 31;
    return h % HASHSIZE;
}

node *lookup(char *n) {
    unsigned int hi = myHash(n);
    node *np = hashtab[hi];
    for (; np != NULL; np = np->next) {
        if (!strcmp(np->nama, n))
            return np;
    }
    return NULL;
}

char *m_strdup(char *o) {
    int l = strlen(o) + 1;
    char *ns = (char *)malloc(l * sizeof(char));
    if (ns == NULL)
        return NULL;
    strcpy(ns, o);
    return ns;
}

char *get(char *nama) {
    node *n = lookup(nama);
    if (n == NULL)
        return NULL;
    else
        return n->desc;
}

int install(char *nama, char *desc) {
    unsigned int hi;
    node *np;
    if ((np = lookup(nama)) == NULL) {
        hi = myHash(nama);
        np = (node *)malloc(sizeof(node));
        if (np == NULL)
            return 0;
        np->nama = m_strdup(nama);
        if (np->nama == NULL) return 0;
        np->next = hashtab[hi];
        hashtab[hi] = np;
    } else
        free(np->desc);
    np->desc = m_strdup(desc);
    if (np->desc == NULL) return 0;
    return 1;
}

void displaytable() {
    int i;
    node *t;
    for (i = 0; i < HASHSIZE; i++) {
        if (hashtab[i] == NULL) {
            cout << "[" << i << "] (kosong)" << endl;
        } else {
            t = hashtab[i];
            cout << "[" << i << "] ";
            for (; t != NULL; t = t->next)
                cout << t->nama << " => " << t->desc << "  ";
            cout << endl;
        }
    }
}

void cleanup() {
    node *np, *t;
    int i;
    for (i = 0; i < HASHSIZE; i++) {
        if (hashtab[i] != NULL) {
            np = hashtab[i];
            while (np != NULL) {
                t = np->next;
                free(np->nama);
                free(np->desc);
                free(np);
                np = t;
            }
            hashtab[i] = NULL;
        }
    }
}

void data() {
    int i;
    const char *namas[] = {"nama", "alamat", "telpon", "cita-cita", "sekolah"};
    const char *descs[] = {"Ridho Sachlan", "TB", "9999999", "Pengusaha", "Mahasiswa"};
    inithashtab();
    for (i = 0; i < 5; i++)
        install((char*)namas[i], (char*)descs[i]);
    install((char*)"telpon", (char*)"9999999");
    cout << "Hasilnya adalah: ";
    cout << "nama ="      << get((char*)"nama")      << " | ";
    cout << "alamat ="    << get((char*)"alamat")    << " | ";
    cout << "telpon ="    << get((char*)"telpon")    << " | ";
    cout << "cita-cita =" << get((char*)"cita-cita") << " | ";
    cout << "sekolah ="   << get((char*)"sekolah")   << endl;
}

int main() {
    int pilihan;
    do {
        cout << "====================================================" << endl;
        cout << "| nama || alamat || telpon || cita-cita || sekolah |" << endl;
        cout << "====================================================" << endl;
        cout << "=====================" << endl;
        cout << "|   MENU PILIHAN    |" << endl;
        cout << "=====================" << endl;
        cout << "|1. Tampilan Data   |" << endl;
        cout << "|2. Display Table   |" << endl;
        cout << "|3. Cleanup         |" << endl;
        cout << "|4. Exit            |" << endl;
        cout << "| PILIHAN ANDA?     |" << endl;
        cin >> pilihan;
		cout<<endl;
        switch (pilihan) {
        case 1:
            data();
            break;
        case 2:
            displaytable();
            break;
        case 3:
            cleanup();
            break;
        case 4:
            cout << "Terima Kasih!" << endl;
            break;
        }
        cin.ignore();
    } while (pilihan != 4);
    return 0;
}