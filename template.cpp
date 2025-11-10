#include <bits/stdc++.h>
using namespace std;
// #include "atcoder/modint.hpp"
// using mint = atcoder::modint998244353;

// #define int long long
using ll = long long;
using ul = unsigned long long;
using ui = unsigned int;
using ld = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<ld>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;

// ll mod = 1;
constexpr ll mod = 998244353;
const ll INF = mod * mod;

const ld eps = 1e-10;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, num, n) for (int i = num; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define pern(i, num, n) for (int i = n - 1; i >= num; i--)
#define all(v) v.begin(), v.end()
template <typename T>
void chmin(T &a, T b)
{
  a = min(a, b);
}
template <typename T>
void chmax(T &a, T b)
{
  a = max(a, b);
}
template <typename T>
void cinarray(vector<T> &v)
{
  rep(i, v.size()) cin >> v[i];
}
template <typename T>
void coutarray(vector<T> &v, bool isReverse = false)
{
  if (!isReverse)
  {
    rep(i, v.size())
    {
      if (i > 0)
        cout << " ";
      cout << v[i];
    }
  }
  else
  {
    per(i, v.size())
    {
      if (i < v.size() - 1)
        cout << " ";
      cout << v[i];
    }
  }
  cout << endl;
}
template <typename T>
void addv(vector<T> &v, int loc, T val)
{
  if (loc >= v.size())
    v.resize(loc + 1, 0);
  v[loc] += val;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vi A(N);
  cinarray(A);
  coutarray(A);
}
