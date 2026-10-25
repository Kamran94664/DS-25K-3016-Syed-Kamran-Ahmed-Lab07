#include <iostream>
using namespace std;

int rc = 0;
int mc = 0;
int cmp = 0;

void merge(int* a, int* t, int l, int m, int r)
{
    int i = l;
    int j = m + 1;
    int k = l;

    while (i <= m && j <= r)
    {
        cmp++;
        if (a[i] <= a[j])
        {
            t[k] = a[i];
            i++;
        }
        else
        {
            t[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= m)
    {
        t[k] = a[i];
        i++;
        k++;
    }

    while (j <= r)
    {
        t[k] = a[j];
        j++;
        k++;
    }

    for (int x = l; x <= r; x++)
    {
        a[x] = t[x];
    }

    mc++;
}

void mergeSort(int* a, int* t, int l, int r)
{
    rc++;

    if (l >= r)
    {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(a, t, l, m);
    mergeSort(a, t, m + 1, r);
    merge(a, t, l, m, r);
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Error: n must be greater than 0" << endl;
        return 1;
    }

    int* a = new int[n];
    int* t = new int[n];

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    mergeSort(a, t, 0, n - 1);

    cout << "Sorted: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Recursive calls: " << rc << endl;
    cout << "Merge operations: " << mc << endl;
    cout << "Comparisons: " << cmp << endl;

    delete[] a;
    delete[] t;

    return 0;
}
