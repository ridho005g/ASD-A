#include <iostream>
using namespace std;

struct BubbleSort
{
    int data[10] = {45, 25, 21, 00, 66, 45, 25, 21, 00, 66}; // npm 4525210066
    int n = 10;

    void tukar(int a, int b)
    {
        int t;
        t = data[b];
        data[b] = data[a];
        data[a] = t;
    }

    void tampil()
    {
        for(int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void bubble_sort()
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                if(data[j] > data[j - 1])
                {
                    tukar(j, j - 1);
                }
            }

            tampil();
        }
    }
};

int main()
{
    BubbleSort bs;

    cout << "|-----------------------------|" << endl;
    cout << "| Algoritma dan Struktur Data |" << endl;
    cout << "| Ridho Sachlan - 4525210066  |" << endl;
    cout << "|-----------------------------|" << endl;
    cout << "| Selamat Datang di aplikasi  |" << endl;
    cout << "|   Bubble Sort Descending    |" << endl;
    cout << "|-----------------------------|" << endl;

	cout<<endl;
    cout << "Data Sebelum Sorting : ";
    bs.tampil();

    cout << "|-----------------------------|" << endl;
    cout << "|      Proses Descending      |" << endl;
    cout << "|-----------------------------|" << endl;

    bs.bubble_sort();

	cout<<endl;
    cout << " Descending : ";
    bs.tampil();

    cout << "|-----------------------------|" << endl;
    cout << "|       TERIMA KASIH          |" << endl;
    cout << "|-----------------------------|" << endl;

    return 0;
}