#include <iostream>
using namespace std;

class BubbleSort
{
private:
    int data[5];
    int n;

public:
    void input()
    {
        cout << "Masukkan jumlah data = ";
        cin >> n;

        for(int i = 0; i < n; i++)
        {
            cout << "Masukkan data ke-" << (i + 1) << " = ";
            cin >> data[i];
        }

        cout << endl;
    }

    void tampil()
    {
        for(int i = 0; i < n; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void ascending()
    {
        for(int i = 1; i < n; i++)
        {
            for(int j = n - 1; j >= i; j--)
            {
                if(data[j] < data[j - 1])
                {
                    int temp;
                    temp = data[j];
                    data[j] = data[j - 1];
                    data[j - 1] = temp;
                }
            }

            tampil();
        }
    }
};

int main()
{
    BubbleSort bs;

	cout << "|-----------------------------|" <<endl;
	cout << "| Algoritma dan Struktur Data |" <<endl;
	cout << "| Ridho Sachlan - 4525210066  |" << endl;
	cout << "|-----------------------------|" << endl;
	cout << "| Selamat Datang di aplikasi  |" << endl;
    cout<<  "|       Bubble Sort           |"<<endl;
    cout<<  "-------------------------------"<<endl;
    bs.input();

    cout << "ascending :" << endl;
    bs.tampil();
    bs.ascending();
    bs.tampil();

    cout << "==========================" << endl;
    cout << "      TERIMA KASIH        " << endl;
    cout << "==========================" << endl;

    return 0;
}