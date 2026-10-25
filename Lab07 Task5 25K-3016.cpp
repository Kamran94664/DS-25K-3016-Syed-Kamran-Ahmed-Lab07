#include <iostream>
using namespace std;

int cmp = 0;

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
    int p = a[l];
    int i = l;

    cout << endl << "Pivot = " << p << " (low=" << l << ", high=" << h << ")" << endl;

    for (int j = l + 1; j <= h; j++)
    {
        cmp++;
        if (a[j] < p)
        {
            i++;
            sw(a[i], a[j]);
        }
    }

    sw(a[l], a[i]);

    cout << "After partition: ";
    pr(a, n);

    return i;
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
    int a[] = {55, 25, 75, 15, 65, 35, 45};
    int n = 7;

    cout << "Original: ";
    pr(a, n);

    quickSort(a, n, 0, n - 1);

    cout << endl << "Sorted: ";
    pr(a, n);
    cout << "Comparisons: " << cmp << endl;

    return 0;
}
