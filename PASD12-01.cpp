#include <iostream>
#include <cstring> 
#define MAX 100
using namespace std;

struct Transport {
    char KotaAwal[30];  
    char KotaAkhir[20]; 
    int Jarak;          
    char Skip;
};

struct stack_type {    
    char KotaAwal[20];  
    char KotaAkhir[20]; 
    int Jrk;            
};                      

struct Transport bus[MAX];     
struct stack_type btstack[MAX];
int buspos = 0;                 
int findpos = 0;
int Tos = 0;                 

// Deklarasi Prototipe Fungsi
void setup();
void route(char *KotaAkhir);
void inbus(const char *KotaAwal, const char *KotaAkhir, int Jarak);
void push(char *KotaAwal, char *KotaAkhir, int Jrk);
void pop(char *KotaAwal, char *KotaAkhir, int *Jrk);
void isbus(char *KotaAwal, char *KotaAkhir);
int find(char *KotaAwal, char *anywhere);
int match(char *KotaAwal, char *KotaAkhir);

int main() {
    char KotaAwal[20], KotaAkhir[20];
    setup();
    
    cout << "Masukkan Perjalanannya" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "Dari: "; cin >> KotaAwal;
    cout << "Ke : "; cin >> KotaAkhir;
    
    isbus(KotaAwal, KotaAkhir);
    route(KotaAkhir);
    
    return 0;
}

void setup() {
    inbus("Jakarta", "Jogyakarta", 650);
    inbus("Jakarta", "Semarang", 450);
    inbus("Jakarta", "Malang", 850);
    inbus("Jogyakarta", "Malang", 300);
    inbus("Semarang", "Surabaya", 450);
    inbus("Semarang", "Jogyakarta", 75);
    inbus("Semarang", "Banyuwangi", 750);
    inbus("Malang", "Madiun", 250);
    inbus("Malang", "Nganjuk", 300);
    inbus("Malang", "Sidoardjo", 30);
}

void inbus(const char *KotaAwal, const char *KotaAkhir, int Jarak) {
    if (buspos < MAX) {
        strcpy(bus[buspos].KotaAwal, KotaAwal); 
        strcpy(bus[buspos].KotaAkhir, KotaAkhir);
        bus[buspos].Jarak = Jarak; 
        bus[buspos].Skip = 0;
        buspos++;
    } else {
        cout << "Database penuh" << endl;
    }
}

void isbus(char *KotaAwal, char *KotaAkhir) {
    int d, Jarak;
    char anywhere[20]; 
    
    d = match(KotaAwal, KotaAkhir);
    if (d != 0) { 
        push(KotaAwal, KotaAkhir, d); 
        return;
    }
    
    Jarak = find(KotaAwal, anywhere);
    if (Jarak != 0) {
        push(KotaAwal, KotaAkhir, Jarak);
        isbus(anywhere, KotaAkhir);
    } else if (Tos > 0) { 
        int Jrk_pop;
        pop(KotaAwal, KotaAkhir, &Jrk_pop);
        isbus(KotaAwal, KotaAkhir);
    }
}

int match(char *KotaAwal, char *KotaAkhir) {
    int t;
    for (t = buspos - 1; t >= 0; t--) { 
        if (!strcmp(bus[t].KotaAwal, KotaAwal) && !strcmp(bus[t].KotaAkhir, KotaAkhir)) {
            return bus[t].Jarak;
        }
    }
    return 0;
}

int find(char *KotaAwal, char *anywhere) {
    while (findpos < buspos) {
        if (!strcmp(bus[findpos].KotaAwal, KotaAwal) && bus[findpos].Skip == 0) {
            strcpy(anywhere, bus[findpos].KotaAkhir);
            bus[findpos].Skip = 1;
            return bus[findpos].Jarak;
        }
        findpos++;
    }
    return 0;
}

void push(char *KotaAwal, char *KotaAkhir, int Jrk) {
    if (Tos < MAX) {
        strcpy(btstack[Tos].KotaAwal, KotaAwal);
        strcpy(btstack[Tos].KotaAkhir, KotaAkhir);
        btstack[Tos].Jrk = Jrk;
        Tos++;
    } else {
        cout << "Stack penuh" << endl;
    }
}

void pop(char *KotaAwal, char *KotaAkhir, int *Jrk) {
    if (Tos > 0) {
        Tos--;
        strcpy(KotaAwal, btstack[Tos].KotaAwal);
        strcpy(KotaAkhir, btstack[Tos].KotaAkhir);
        *Jrk = btstack[Tos].Jrk;
    } else {
        cout << "Stack kosong" << endl;
    }
}

void route(char *KotaAkhir) {
    int t = 0;
    int totJrk = 0;
    while (t < Tos) {
        cout << "Jalur: " << btstack[t].KotaAwal << " -> ";
        totJrk += btstack[t].Jrk;
        t++;
    }
    cout << KotaAkhir << endl;
    cout << "Total Jarak = " << totJrk << " km" << endl;
}