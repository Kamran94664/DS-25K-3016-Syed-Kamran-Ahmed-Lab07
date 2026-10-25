#include <iostream>
using namespace std;

void pr(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void cs(int a[], int n, int e)
{
    int o[100];
    int c[10];

    for (int i = 0; i < 10; i++)
    {
        c[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int d = (a[i] / e) % 10;
        c[d]++;
    }

    for (int d = 1; d < 10; d++)
    {
        c[d] = c[d] + c[d - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        int d = (a[i] / e) % 10;
        c[d]--;
        o[c[d]] = a[i];
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = o[i];
    }
}

int main()
{
    int a[] = {94, 802, 7, 1234, 56, 321, 405, 18};
    int n = 8;
    int mx = a[0];
    int p = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
        }
    }

    cout << "Original: ";
    pr(a, n);
    cout << endl;

    for (int e = 1; mx / e > 0; e = e * 10)
    {
        cs(a, n, e);
        p++;
        cout << "After pass " << p << ": ";
        pr(a, n);
    }

    cout << endl << "Sorted: ";
    pr(a, n);
    cout << "Total passes: " << p << endl;

    return 0;
}
