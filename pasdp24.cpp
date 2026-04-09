#include <iostream>
#include <string.h>
using namespace std;

typedef struct {
	string npm;
	string nama_mhs;
	double nilai;
} NilaiMK;

typedef struct {
	int top;
	NilaiMK Dat[10];
} stack;

void buatSTKosong (stack *S) {
	(*S).top = -1;
}

bool isKosong (stack S) {
	bool hasil = false;
	
	if (S.top == -1)  {
		hasil = true;
	}
	return hasil;
}

bool isPenuh (stack S) {
	bool hasil = false;
	
	if (S.top == 9) {
		hasil = true;
	}
	return hasil;
}

void push(string npm