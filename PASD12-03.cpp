#include <iostream>

using namespace std;

struct simpul;
struct jalur;

typedef struct simpul *altsimpul;
typedef struct jalur *altjalur;

typedef struct simpul {
    char kontenersimpul;
    altsimpul nextsimpul;
    altjalur arc;
} cansimpul;

typedef struct jalur {
    int kontenerjalur;
    altjalur nextJalur;
    cansimpul *tujuan;
} canjalur;

typedef struct {
    cansimpul *first;
} graph;


void simpulbaru(graph *G)
{
    G->first = NULL;
}

void tambahsimpul(char c, graph *G)
{
    cansimpul *baru = new cansimpul;

    baru->kontenersimpul = c;
    baru->nextsimpul = NULL;
    baru->arc = NULL;

    if(G->first == NULL)
    {
        G->first = baru;
    }
    else
    {
        cansimpul *last = G->first;

        while(last->nextsimpul != NULL)
        {
            last = last->nextsimpul;
        }

        last->nextsimpul = baru;
    }
}


cansimpul *findsimpul(char c, graph G)
{
    cansimpul *hasil = NULL;
    cansimpul *bantu = G.first;
    bool ketemu = false;

    while((bantu != NULL) && (!ketemu))
    {
        if(bantu->kontenersimpul == c)
        {
            hasil = bantu;
            ketemu = true;
        }
        else
        {
            bantu = bantu->nextsimpul;
        }
    }

    return hasil;
}


void tambahjalur(cansimpul *awal, cansimpul *tujuan, int beban)
{
    canjalur *baru = new canjalur;

    baru->kontenerjalur = beban;
    baru->tujuan = tujuan;
    baru->nextJalur = NULL;

    if(awal->arc == NULL)
    {
        awal->arc = baru;
    }
    else
    {
        canjalur *last = awal->arc;

        while(last->nextJalur != NULL)
        {
            last = last->nextJalur;
        }

        last->nextJalur = baru;
    }
}


void delJalur(char ctujuan, cansimpul *awal)
{
    canjalur *hapus = awal->arc;

    if(hapus != NULL)
    {
        if(hapus->tujuan->kontenersimpul == ctujuan)
        {
            awal->arc = hapus->nextJalur;
            delete hapus;
        }
        else
        {
            canjalur *prev = NULL;
            bool ketemu = false;

            while((hapus != NULL) && (!ketemu))
            {
                if(hapus->tujuan->kontenersimpul == ctujuan)
                {
                    ketemu = true;
                }
                else
                {
                    prev = hapus;
                    hapus = hapus->nextJalur;
                }
            }

            if(ketemu)
            {
                prev->nextJalur = hapus->nextJalur;
                delete hapus;
            }
        }
    }
}


void tampilGraph(graph G)
{
    cansimpul *bantu = G.first;

    while(bantu != NULL)
    {
        cout << "Simpul " << bantu->kontenersimpul << " : ";

        canjalur *jalur = bantu->arc;

        while(jalur != NULL)
        {
            cout << jalur->tujuan->kontenersimpul
                 << "(" << jalur->kontenerjalur << ") ";

            jalur = jalur->nextJalur;
        }

        cout << endl;
        bantu = bantu->nextsimpul;
    }
}

int main()
{
    graph G;
    simpulbaru(&G);


    tambahsimpul('A', &G);
    tambahsimpul('B', &G);
    tambahsimpul('C', &G);


    cansimpul *A = findsimpul('A', G);
    cansimpul *B = findsimpul('B', G);
    cansimpul *C = findsimpul('C', G);


    tambahjalur(A, B, 45);
    tambahjalur(A, C, 25);
    tambahjalur(B, C, 66);

    cout << "Graph sebelum penghapusan:" << endl;
    tampilGraph(G);


    delJalur('C', A);

    cout << "\nGraph setelah penghapusan jalur A -> C:" << endl;
    tampilGraph(G);

    return 0;
}