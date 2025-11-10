#include <bits/stdc++.h>
using namespace std;

// #define int long long
using ll = long long;

// ll mod = 1;
constexpr ll mod = 998244353;

// モジュラべき乗法
ll mod_pow(ll x, ll n, ll m = mod)
{
  if (n < 0)
  {
    ll res = mod_pow(x, -n, m);
    return mod_pow(res, m - 2, m);
  }
  if (abs(x) >= m)
    x %= m;
  if (x < 0)
    x += m;
  // if (x == 0)return 0;
  ll res = 1;
  while (n)
  {
    if (n & 1)
      res = res * x % m;
    x = x * x % m;
    n >>= 1;
  }
  return res;
}
