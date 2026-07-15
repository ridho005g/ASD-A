#include <iostream>
using namespace std;

void heapify(char arr[], int n, int i)
{
    int terbesar = i;
    int kiri = 2 * i + 1;
    int kanan = 2 * i + 2;

    if (kiri < n && arr[kiri] > arr[terbesar])
        terbesar = kiri;

    if (kanan < n && arr[kanan] > arr[terbesar])
        terbesar = kanan;

    if (terbesar != i)
    {
        swap(arr[i], arr[terbesar]);
        heapify(arr, n, terbesar);
    }
}

void heapSort(char arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;
    cout << "Jumlah huruf : ";
    cin >> n;

    char data[100];

    cout << "Masukkan huruf:\n";
    for (int i = 0; i < n; i++)
        cin >> data[i];

    heapSort(data, n);

    cout << "\nUrutan Ascending : ";
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";

    return 0;
}