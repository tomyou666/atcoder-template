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

#define ER(v) Enumerate(v)
vector<int> Enumerate(vector<int> A) {
  // ビット全探索
  vector<int> SumList;
  rep(i, 1 << A.size()) {
    int sum = 0;
    rep(j, A.size()) {
      int wari = (1 << j);
      if ((i / wari) % 2 == 1) sum += A[j];
    }
    SumList.push_back(sum);
  }
  return SumList;
}
