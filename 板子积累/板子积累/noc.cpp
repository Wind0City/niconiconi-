//组合数公式
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Maxn = 5000, mod;
ll fac[50000];
void setFac(int n)
{
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fac[i] = 1LL * fac[i - 1] * i % mod;
    }
}
ll binaryPow(ll a, ll b, ll m)
{
    ll ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = ans * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}
ll C(int n, int m)
{
    if (n < m)
        return 0;
    if (n < 0 || m < 0)
        return 0;
    ll t = fac[n - m] * fac[m] % mod;
    ll inv = binaryPow(t, mod - 2, mod);
    return fac[n] * inv % mod;
}