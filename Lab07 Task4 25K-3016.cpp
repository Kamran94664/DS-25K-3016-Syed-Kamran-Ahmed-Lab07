#include <iostream>
using namespace std;

int pc = 0;

void sw(int &x, int &y)
{
    int t = x;
    x = y;
    y = t;
}

void pr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int partition(int a[], int n, int l, int h)
{
    int p = a[h];
    int i = l - 1;

    pc++;
    cout << endl << "Partition #" << pc << ": low=" << l << ", high=" << h << ", pivot=" << p << endl;

    for (int j = l; j < h; j++)
    {
        if (a[j] <= p)
        {
            i++;
            sw(a[i], a[j]);
        }
    }

    sw(a[i + 1], a[h]);

    cout << "After partition: ";
    pr(a, n);

    return i + 1;
}

void quickSort(int a[], int n, int l, int h)
{
    if (l < h)
    {
        int p = partition(a, n, l, h);
        quickSort(a, n, l, p - 1);
        quickSort(a, n, p + 1, h);
    }
}

int main()
{
    int a[] = {40, 20, 70, 10, 60, 30, 50};
    int n = 7;

    cout << "Original: ";
    pr(a, n);

    quickSort(a, n, 0, n - 1);

    cout << endl << "Sorted: ";
    pr(a, n);
    cout << "Partition operations: " << pc << endl;

    return 0;
}
