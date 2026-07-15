#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int a[20][20], q[20], visited[20], n, i, j, f = 0, r = -1;

void bfs(int v) {
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !visited[i]) {
            q[++r] = i;
        }
    }
    if (f <= r) {
        visited[q[f]] = 1;
        bfs(q[f++]);
    }
}

int main() {
    int v;
    cout << "Masukkan Matriks atau Vertex: ";
    cin >> n;
    
    for (i = 1; i <= n; i++) {
        q[i] = 0;
        visited[i] = 0;
    }
    
    cout << "Masukkan Data Graph Dalam Bentuk Matrik [nxn]: " << endl;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "Masukkan Vertex Awal: ";
    cin >> v;
    
    visited[v] = 1; // Menandai vertex awal telah dikunjungi
    bfs(v);
    
    cout << "Node Yang Dapat Dicapai: " << endl;
    for (i = 1; i <= n; i++) {
        if (visited[i]) {
            cout << i << endl;
        } else {
            cout << "BFS Gagal, Tidak Semua Node Dapat Dijangkau" << endl;
            break;
        }
    }
    
    cout << endl;
    cin.get();
    return 0;
}