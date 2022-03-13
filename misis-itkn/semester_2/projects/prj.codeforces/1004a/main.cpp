#include <bits/stdc++.h>


const int MOD = 1000000007;
const int MAX = 1000005;

int SetBit (int n, int x) { return n | (1 << x); }
int ClearBit (int n, int x) { return n & ~(1 << x); }
int ToggleBit (int n, int x) { return n ^ (1 << x); }
bool CheckBit (int n, int x) { return (bool)(n & (1 << x)); }

int main (void)
{
    /*
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    */

    long long n, i, d, arr[105], k;

    while (scanf ("%lld %lld", &n, &d) != EOF)
    {
        for (i=0; i<n; i++)
            scanf("%lld", &arr[i]);

        std::set <int> mySet;

        for (i=0; i<n; i++)
        {
            if (i != 0)
            {
                k = arr[i]-d;

                if (k >= (arr[i-1]+d))
                    mySet.insert(k);
            }
            else
                mySet.insert(arr[i]-d);

            if (i == n-1)
                mySet.insert(arr[i]+d);
            else
            {
                k = arr[i]+d;

                if (k <= (arr[i+1]-d))
                    mySet.insert(k);
            }
        }

        printf("%d\n", mySet.size());

        mySet.clear();
    }

    return(0);
}