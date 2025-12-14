#include <atcoder/all>
#include <bits/stdc++.h>

using namespace std;
using namespace atcoder;

// clang-format off
typedef long long int ll;
// using mint = modint998244353;
// using mint = modint1000000007;
constexpr ll mod = 998244353;
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
typedef vector<pair<ll,ll>> vpl;
typedef pair<ll,ll> pl;
typedef pair<ll,pl> ppl;
typedef pair<ll,ppl> pppl;
typedef pair<ll,pppl> pppppl;
const ll INF = 4000000000000000000ll;
const ld eps = 1e-10;
static const long double pi = 3.141592653589793;
#define il inline
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, num, n) for (int i = num; i < n; i++)
#define per(i, n) for (int i = n - 1; i >= 0; i--)
#define pern(i, num, n) for (int i = n - 1; i >= num; i--)
#define all(v) v.begin(), v.end()
#define rall(c) rbegin(c), rend(c)
#define pb push_back
#define eb emplace_back
#define ppb pop_back
#define ppf pop_front
#define fi first
#define se second
#define LB(v, val) lower_bound(all(v), val)
#define UB(v, val) upper_bound(all(v), val)
#define BS(v, val) binary_search(all(v), val)
#define MINE(v) min_element(all(v))
#define MAXE(v) max_element(all(v))
#define SORT(v) So(v)
#define SORE(v) Sore(v)
#define REV(v) reverse(all(v))
#define INT(...) int __VA_ARGS__; IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__; IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__; IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__; IN(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__; IN(__VA_ARGS__)
#define VEC(type, name, size) vector<type> name(size); IN(name)
#define VEC2(type, name1, name2, size) vector<type> name1(size), name2(size);  for (int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size) vector<type> name1(size), name2(size), name3(size);  for (int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VV(type, name, h, w) vector<vector<type>> name(h, vector<type>(w)); IN(name)
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
template<class T> using _pq = priority_queue<T, vector<T>>;
template<class T> using _pql = priority_queue<T, vector<T>, greater<T>>;
template<class T> bool chmin(T &a,T b){if(b<a){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,T b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(all(v));}
void So(string &v) {sort(all(v));}
template<class T> void Sore(vector<T> &v) {sort(all(v), greater<T>());}
void Sore(string &v) {sort(all(v),[](auto &a,auto &b){return a>b;});}
int binary_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
int scan() {return getchar();}
void scan(int &a) {cin >> a;}
void scan(long long &a) {cin >> a;}
void scan(char &a) {cin >> a;}
void scan(double &a) {cin >> a;}
void scan(string &a) {cin >> a;}
template <class T, class S> void scan(pair<T, S> &p) {scan(p.first), scan(p.second);}
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {for (auto &i : a) scan(i);}
template <class T> void scan(T &a) {cin >> a;}
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) { scan(head); IN(tail...);}
// clang-format on

// stringstreamのサンプル
void stringstream_example() {
  vl A = {1, 3, 4};
  stringstream ss;
  for (int i = 0; i < (int)A.size(); i++) {
    ss << A[i];
    if (i != (int)A.size() - 1) {
      ss << ", ";
    }
  }
  string out = ss.str();
  printf("Joined string: %s", out.c_str()); // 例: "Joined string: 1, 3, 4"
}
