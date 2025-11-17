#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, num, n) for (int i = num; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define pern(i, num, n) for (int i = n - 1; i >= num; i--)
#define all(v) v.begin(), v.end()

#define ER(v) Enumerate(v)
vector<ll> Enumerate(vector<ll> A) { // ビット全探索
  vector<ll> SumList;
  rep(i, 1 << A.size()) {
    ll sum = 0;
    rep(j, A.size()) {
      ll wari = (1 << j);
      if ((i / wari) % 2 == 1) sum += A[j];
    }
    SumList.push_back(sum);
  }
  return SumList;
}
