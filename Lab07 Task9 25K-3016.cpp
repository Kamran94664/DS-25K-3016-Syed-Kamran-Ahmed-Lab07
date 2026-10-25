#include <iostream>
using namespace std;

void pr(const char* s, int a[], int n)
{
    cout << s;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void cs(int a[], int n, int e, int p)
{
    int o[100];
    int c[10];

    for (int i = 0; i < 10; i++)
    {
        c[i] = 0;
    }

    cout << endl << "=== Pass " << p << " (place " << e << ") ===" << endl;
    pr("Original   : ", a, n);

    for (int i = 0; i < n; i++)
    {
        int d = (a[i] / e) % 10;
        c[d]++;
    }
    pr("Frequency  : ", c, 10);

    for (int d = 1; d < 10; d++)
    {
        c[d] = c[d] + c[d - 1];
    }
    pr("Cumulative : ", c, 10);

    // going from right to left keeps duplicates in order (stable)
    for (int i = n - 1; i >= 0; i--)
    {
        int d = (a[i] / e) % 10;
        c[d]--;
        o[c[d]] = a[i];
    }
    pr("Output     : ", o, n);

    for (int i = 0; i < n; i++)
    {
        a[i] = o[i];
    }
    pr("Copied back: ", a, n);
}

int main()
{
    int a[] = {4721, 305, 472, 89, 3005, 721, 1000, 305, 9999, 42, 870, 100};
    int n = 12;
    int mx = a[0];
    int p = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
        }
    }

    pr("Original IDs: ", a, n);

    for (int e = 1; mx / e > 0; e = e * 10)
    {
        cs(a, n, e, p);
        p++;
    }

    cout << endl;
    pr("Sorted IDs: ", a, n);

    return 0;
}
