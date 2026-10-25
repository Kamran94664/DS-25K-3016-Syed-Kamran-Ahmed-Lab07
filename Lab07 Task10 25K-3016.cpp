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
    int a[] = {7314, 314, 731, 34, 3147, 147, 47, 7314, 4, 314};
    int n = 10;
    int mx = a[0];
    int p = 0;
    int k = 1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > mx)
        {
            mx = a[i];
        }
    }

    for (int m = mx; m > 0; m = m / 10)
    {
        p++;
    }

    cout << "Max = " << mx << ", passes required = " << p << endl;
    pr("Original: ", a, n);
    cout << endl;

    for (int e = 1; mx / e > 0; e = e * 10)
    {
        cs(a, n, e);
        cout << "After pass " << k << ": ";
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
        k++;
    }

    cout << endl;
    pr("Sorted: ", a, n);

    return 0;
}
