#include <iostream>
using namespace std;

class BinaryHeap
{
private:
    static const int MAX_N = 15;
    int heap[MAX_N];
    int N;

public:
    BinaryHeap()
    {
        N = 0;
    }

    static int root(int i)
    {
        return (i - 1) / 2;
    }

    static int KIRI(int i)
    {
        return 2 * i + 1;
    }

    static int KANAN(int i)
    {
        return 2 * i + 2;
    }

    void tukar(int &x, int &y)
    {
        int temp = x;
        x = y;
        y = temp;
    }

    void sisip(int data)
    {
        if (N >= MAX_N)
        {
            cout << "Heap penuh!" << endl;
            return;
        }

        heap[N] = data;
        N++;

        int i = N - 1;

        while (i > 0 && heap[root(i)] < heap[i])
        {
            tukar(heap[root(i)], heap[i]);
            i = root(i);
        }
    }

    void maxHeapify(int i)
    {
        int left = KIRI(i);
        int right = KANAN(i);
        int largest = i;

        if (left < N && heap[left] > heap[largest])
            largest = left;

        if (right < N && heap[right] > heap[largest])
            largest = right;

        if (largest != i)
        {
            tukar(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    int getMax()
    {
        return heap[0];
    }

    void tampil()
    {
        for (int i = 0; i < N; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main()
{
    BinaryHeap H;

    H.sisip(10);
    H.sisip(40);
    H.sisip(20);
    H.sisip(60);
    H.sisip(30);

    cout << "Isi Heap : ";
    H.tampil();

    cout << "Nilai Maksimum : "
         << H.getMax() << endl;

    return 0;
}