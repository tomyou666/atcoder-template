#include <bits/stdc++.h>
using namespace std;
// #include "atcoder/modint.hpp"
// using mint = atcoder::modint998244353;
#define int long long
using ll = long long;
using ul = unsigned long long;
using ui = unsigned int;
using dl = double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<dl, dl>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<dl>;
using vvd = vector<vd>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vp = vector<pi>;
// ll mod = 1;
constexpr ll mod = 998244353;
const ll INF = mod * mod;
const dl eps = 1e-10;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, num, n) for (int i = num; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define pern(i, num, n) for (int i = n - 1; i >= num; i--)
#define all(v) v.begin(), v.end()
#define LB(v, val) lower_bound(all(v), val)
#define UB(v, val) upper_bound(all(v), val)
#define BS(v, val) binary_search(all(v), val)
void fast_io() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);
}
template <typename T> void print(const T &x) {
  std::cout << x << '\n';
}

template <typename T, typename... Args>
void print(const T &x, const Args &...rest) { // 複数の要素を受け取る関数
  std::cout << x << ' ';
  print(rest...);
}
template <typename T>
void print_dl(const T &x, int precision = 3) // 浮動小数点数を小数点N桁で出力
{
  std::cout << std::fixed << std::setprecision(precision) << x << '\n';
}
template <typename T>
void chmin(T &a, T b) // aをbとの最小値で更新
{
  a = min(a, b);
}
template <typename T>
void chmax(T &a, T b) // aをbとの最大値で更新
{
  a = max(a, b);
}
template <typename T>
void cinarr(vector<T> &v) // 配列を入力
{
  rep(i, v.size()) cin >> v[i];
}
template <typename T>
void printarr(vector<T> &v, bool isReverse = false) // 配列を出力
{
  if (!isReverse) {
    rep(i, v.size()) {
      if (i > 0) cout << " ";
      cout << v[i];
    }
  } else {
    per(i, v.size()) {
      if (i < v.size() - 1) cout << " ";
      cout << v[i];
    }
  }
  cout << endl;
}
template <typename T>
void addv(vector<T> &v, int loc, T val) // ベクトルのloc番目にvalを加算
{
  if (loc >= v.size()) v.resize(loc + 1, 0);
  v[loc] += val;
}

void solve();

#undef int
int main() {
#define int long long
  fast_io();
  solve();
  return 0;
}

void solve() {
}
