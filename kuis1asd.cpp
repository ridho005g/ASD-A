#include <iostream>
using namespace std;

int main()
{
	int n,*pn,&ppn;
	n = 50;
	pn = &n;
	&ppn = &ppn;
	
cout << endl;
cout << "isi variabel : " << *pn << endl;

cin.get();
}