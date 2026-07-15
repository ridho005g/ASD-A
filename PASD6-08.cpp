#include <iostream>
#include <iomanip>
using namespace std;

class QuickSort {
	int Data[66];
	int n;
public:
	void setData(int jumlah) {
		n = jumlah;
	}
	void inputData() {
		for (int i = 0; i < n; i++) {
			cout << "Data ke-" << i+1 << " : ";
			cin >> Data[i];
		}
	}
	void Q_Sort(int Kiri, int Kanan) {
		int pivot, Kiri_Hold, Kanan_Hold;
		Kiri_Hold = Kiri;
		Kanan_Hold = Kanan;
		pivot = Data[Kiri];
		while (Kiri < Kanan) {
			while ((Data[Kanan] >= pivot) && (Kiri < Kanan))
				Kanan--;
			if (Kiri != Kanan) {
				Data[Kiri] = Data[Kanan];
				Kiri++;
			}
			while ((Data[Kiri] <= pivot) && (Kiri < Kanan))
				Kiri++;
			if (Kiri != Kanan) {
				Data[Kanan] = Data[Kiri];
				Kanan--;
			}
		}
		Data[Kiri] = pivot;
		pivot = Kiri;
		Kiri = Kiri_Hold;
		Kanan = Kanan_Hold;
		if (Kiri < pivot)
			Q_Sort(Kiri, pivot-1);
		if (Kanan > pivot)
			Q_Sort(pivot+1, Kanan);
	}
	void tampil() {
		for (int i = 0; i < n; i++) {
			cout << setw(3) << Data[i];
		}
		cout << endl;
	}
};

int main() {
	int jum;
	QuickSort qs;
	cout << "|-----------------------------|" <<endl;
	cout << "| Algoritma dan Struktur Data |" <<endl;
	cout << "| Ridho Sachlan - 4525210066  |" << endl;
	cout << "|-----------------------------|" << endl;
	cout<< endl;
	cout << "|    Masukkan jumlah data     | : ";
	cin >> jum;
	qs.setData(jum);
	cout << endl;
	qs.inputData();
	cout<<endl;
	cout << "|  Data sebelum diurutkan  |  "<< endl;
	cout << "|--------------------------|" << endl;
	qs.tampil();
	cout << endl;
	qs.Q_Sort(0, jum-1);
	cout << "|  Data setelah diurutkan  |" << endl;
	cout << "|        Ascending         |" << endl;
	cout << "|--------------------------|" << endl;
	qs.tampil();
	cin.ignore();
	cin.get();
}