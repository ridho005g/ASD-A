#include <iostream> 
using namespace std;

int stack[5];
int top = -1;

int main() {
	top++;
	stack[top] = 5;
	
	top++;
	stack[top] = 10;
	
	cout << "Isi stack setelah push: " << endl;
	for (int i = top; i >= 0; i--) {
		cout << stack[i] << endl;
	}
    
	cout << "data yang keluar: " <<stack[top] <<endl;
	top--;
	
	cout << "isi stack setelah pop: " <<endl;
	for(int i = top; i >= 0; i--) {
		cout << stack[i] << endl;
	}
	
	cin.get();
}