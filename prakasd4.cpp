#include <iostream>
using namespace std;

struct Node {
	int NilaiUTS;
	int NilaiUAS;
	int N1,N2;
Node *P, *Q;

intmain() {
	P = new Node;
	P -> N1 = 99;
	Q = new Node;
	Q -> N2 = 66;
	
cout << endl;
cout <<" Isi variabel P = " << P -> N1 << endl;
cout <<" Isi variabel Q = " << Q -> N2 << endl;
cour << endl;
cin.get();
}