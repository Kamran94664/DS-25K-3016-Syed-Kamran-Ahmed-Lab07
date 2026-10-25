#include <iostream>
using namespace std;

int cmp = 0;

void pr(const char* s, int a[], int n)
{
    cout << s;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void merge(int a[], int l, int m, int r)
{
    int nl = m - l + 1;
    int nr = r - m;
    int L[100];
    int R[100];

    for (int i = 0; i < nl; i++)
    {
        L[i] = a[l + i];
    }

    for (int j = 0; j < nr; j++)
    {
        R[j] = a[m + 1 + j];
    }

    cout << endl << "Merging [" << l << ".." << r << "]" << endl;
    pr("  Left : ", L, nl);
    pr("  Right: ", R, nr);

    int i = 0;
    int j = 0;
    int k = l;

    while (i < nl && j < nr)
    {
        cmp++;
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < nl)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < nr)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r)
{
    if (l >= r)
    {
        return;
    }

    int m = (l + r) / 2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

int main()
{
    int a[] = {1299, 499, 2499, 799, 499, 1599, 999, 299};
    int n = 8;

    pr("Original prices: ", a, n);

    mergeSort(a, 0, n - 1);

    cout << endl;
    pr("Sorted prices: ", a, n);
    cout << "Total comparisons: " << cmp << endl;

    return 0;
}
