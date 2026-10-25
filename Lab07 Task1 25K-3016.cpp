#include <iostream>
using namespace std;

int mc = 0;

void pr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int n, int l, int m, int r)
{
    int t[100];
    int i = l;
    int j = m + 1;
    int k = 0;

    while (i <= m && j <= r)
    {
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

    for (int x = 0; x < k; x++)
    {
        a[l + x] = t[x];
    }

    mc++;
    cout << "Merge #" << mc << ": ";
    pr(a, n);
}

void mergeSort(int a[], int n, int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(a, n, l, m);
    mergeSort(a, n, m + 1, r);
    merge(a, n, l, m, r);
}

int main()
{
    int a[] = {78, 45, 92, 63, 45, 88, 51, 70};
    int n = 8;

    cout << "Original: ";
    pr(a, n);
    cout << endl;

    mergeSort(a, n, 0, n - 1);

    cout << endl << "Sorted: ";
    pr(a, n);
    cout << "Total merges: " << mc << endl;

    return 0;
}
