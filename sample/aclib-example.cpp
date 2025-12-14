#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// clang-format off
// using mint = modint998244353;
using mint = modint1000000007;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef vector<vvvl> vvvvl;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef vector<vvvb> vvvvb;
typedef vector<ld> vld;
typedef vector<vld> vvld;
typedef vector<vvld> vvvld;
typedef vector<vvvld> vvvvld;
typedef vector<char> vc;
typedef vector<string> vs;
typedef pair<ll,ll> pl;
typedef pair<ll,pl> ppl;
typedef pair<ll,ppl> pppl;
typedef pair<ll,pppl> pppppl;
constexpr ll mod = 998244353;
const ll INF = 4000000000000000000ll;
const ld eps = 1e-10;
static const long double pi = 3.141592653589793;
#define il inline
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, num, n) for (int i = num; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define pern(i, num, n) for (int i = n - 1; i >= num; i--)
#define all(v) v.begin(), v.end()
#define pb push_back
#define fi first
#define se second
#define LB(v, val) lower_bound(all(v), val)
#define UB(v, val) upper_bound(all(v), val)
#define BS(v, val) binary_search(all(v), val)
#define MINE(v) min_element(all(v))
#define MAXE(v) max_element(all(v))
void yes(bool a){cout<<(a?"yes":"no")<<endl;}
void YES(bool a){cout<<(a?"YES":"NO")<<endl;}
void Yes(bool a){cout<<(a?"Yes":"No")<<endl;}
void possible(bool a){ cout<<(a?"possible":"impossible")<<endl; }
void Possible(bool a){ cout<<(a?"Possible":"Impossible")<<endl; }
void POSSIBLE(bool a){ cout<<(a?"POSSIBLE":"IMPOSSIBLE")<<endl; }
void fast_io() {std::ios::sync_with_stdio(false);std::cin.tie(NULL);}
template <typename T> void cinarr(vector<T> &v){rep(i, v.size()) cin >> v[i];}
template <typename T> void print(const T &x){std::cout << x << '\n';}
template <typename T, typename... Args> void print(const T &x, const Args &...rest){std::cout << x << ' ';print(rest...);}
template <typename T> void print_ld(const T &x, int precision = 3){std::cout << std::fixed << std::setprecision(precision) << x << '\n';}
template <typename T> void printarr(vector<T> &v, bool isReverse = false){if (!isReverse) {rep(i, v.size()) {if (i > 0) cout << " ";cout << v[i];}} else {per(i, v.size()) {if (i < v.size() - 1) cout << " ";cout << v[i];}}cout << endl;}
template <typename T> void addv(vector<T> &v, int loc, T val){if (loc >= v.size()) v.resize(loc + 1, 0);v[loc] += val;}
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
int binary_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}

// clang-format on

// https://atcoder.github.io/ac-library/production/document_ja/segtree.html
void segtree_sample() {      // segtreeの使い方
  auto op = [](ll a, ll b) { // 演算
    return min(a, b);
  };
  auto e = []() { // 初期化(単位元)
    return -INF;
  };
  segtree<ll, op, e> seg(10);
  // seg[0]に3をセット.O(logn)
  seg.set(0, 3);
  // seg[0]をゲット.O(1)
  seg.get(0);
  // [2,4)⇒p[2],p[3]の範囲でopを満たす要素を返す.O(logn)
  seg.prod(2, 4);
  // すべての範囲でopを満たす要素を返す.O(1)
  seg.all_prod();
  // 位置lから右へ、条件fを満たす最大の右端rを探す.O(logn)
  // [l,r)のrが返ってくるので-1する
  ll target = 10;
  seg.max_right(3, [&](ll v) { return v > target; });
  // 位置rから左へ、条件fを満たす最小の左端lを探す.O(logn)
  // [l,r)の範囲なので引数は+1する
  seg.min_left(4, [&](ll v) { return v > target; });
}
