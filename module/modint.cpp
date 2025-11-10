
#include <bits/stdc++.h>
using namespace std;
// #define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;

// ll mod = 1;
constexpr ll mod = 998244353;
// mod should be <2^31
struct modint
{
  int n;
  modint() : n(0) { ; }
  modint(ll m)
  {
    if (m < 0 || mod <= m)
    {
      m %= mod;
      if (m < 0)
        m += mod;
    }
    n = m;
  }
  operator int() { return n; }
};
bool operator==(modint a, modint b) { return a.n == b.n; }
bool operator<(modint a, modint b) { return a.n < b.n; }
modint operator+=(modint &a, modint b)
{
  a.n += b.n;
  if (a.n >= mod)
    a.n -= (int)mod;
  return a;
}
modint operator-=(modint &a, modint b)
{
  a.n -= b.n;
  if (a.n < 0)
    a.n += (int)mod;
  return a;
}
modint operator*=(modint &a, modint b)
{
  a.n = ((ll)a.n * b.n) % mod;
  return a;
}
modint operator+(modint a, modint b) { return a += b; }
modint operator-(modint a, modint b) { return a -= b; }
modint operator*(modint a, modint b) { return a *= b; }
modint operator^(modint a, ll n)
{
  if (n == 0)
    return modint(1);
  modint res = (a * a) ^ (n / 2);
  if (n % 2)
    res = res * a;
  return res;
}
ll inv(ll a, ll p)
{
  return (a == 1 ? 1 : (1 - p * inv(p % a, a)) / a + p);
}
modint operator/(modint a, modint b) { return a * modint(inv(b, mod)); }
modint operator/=(modint &a, modint b)
{
  a = a / b;
  return a;
}
