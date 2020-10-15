#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll NcR(int n, int r)
{

    long long p = 1, k = 1;

    r = min(r, n - r);

    if (r != 0)
    {
        while (r)
        {
            p *= n;
            k *= r;
            long long m = __gcd(p, k);
            p /= m;
            k /= m;

            n--;
            r--;
        }
    }

    else
        p = 1;

    return p;
}
int main(){
    return 0;
}