// #pragma GCC optimize(1)
// #pragma GCC optimize(2)
// #pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("Ofast", "unroll-loops", "march=native")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
// #pragma comment(linker, "/STACK:1024000000,1024000000")
#include <bits/stdc++.h>

// #include <ext/pb_ds/assoc_container.hpp>
// #include <bits/extc++.h>
// __gnu_pbds::gp_hash_table<string, int> mp;
// __gnu_pbds::priority_queue<long long, decltype([](long long& a, long long& b) { return a > b; })> pq;
// using namespace __gnu_pbds;
using namespace std;
// #define int long long
#define rep(i, a, n) for (int i = a; i < n; i++)
#define per(i, a, n) for (int i = n - 1; i >= a; i--)
#define pb push_back
// #define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define abs(x) (((x) < 0) ? (-(x)) : (x))
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x; }
ll powmod(ll a, ll b) {
  ll res = 1;
  a %= mod;
  assert(b >= 0);
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline int pmod(int x, int d) {
  int m = x % d;
  return m + ((m >> 31) & d);
}
#define y1 ojsapogjahg
#define prev ojaposjdas
#define rank oiajgpowsdjg
#define left aijhgpiaejhgp
// #define end aononcncnccc
// head
const int _n = 2e5 + 10;
int t, n, m, q, h[_n];

bool ans[_n];
vector<int> G[_n];
struct node {
  int id,h;
  bool operator<(auto& rhs) const {
    return h > rhs.h;
  }
};
priority_queue<node> pq_h;

int rank[_n], parent[_n];
void dsinit(int n){
  memset(rank, 0, n);
  for(int i=0;i<n;i++){
    parent[i] = i;
  }
}
int dsfind(int e) {
  return parent[e] == e ? e : parent[e] = dsfind(parent[e]);
}
void dsunion(int a, int b){
  int p1 = dsfind(a);
  int p2 = dsfind(b);
  if(p1 < p2) swap(p1,p2);
  parent[p2] = p1;
  if(rank[p1] == rank[p2]) rank[p1]++;
}

struct query {
  int id,a,b,e;
  bool operator<(auto& rhs) const {
    return h[a]+e < h[rhs.a] + rhs.e;
  }
};
query qs[_n];
main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin>>t;
  while(t--){
    cin>>n>>m;
    dsinit(n);
    while(!pq_h.empty()) {
      pq_h.pop();
    }
    for(int i=0;i<n;i++){
      cin>>h[i];
      pq_h.push({i,h[i]});
      G[i].clear();
    }
    for(int i=0;i<m;i++){
      int u,v;
      cin>>u>>v;
      u--;
      v--;
      G[u].push_back(v);
      G[v].push_back(u);
    }
    cin>>q;
    for(int i=0;i<q;i++){
      int a,b,e;
      cin>>a>>b>>e;
      a--;
      b--;
      qs[i] = {i,a,b,e};
    }
    sort(qs, qs+q);
    for(int i=0;i<q;i++){
      query curq = qs[i];
      int maxh = h[curq.a] + curq.e;
      while(!pq_h.empty()){
        node curn = pq_h.top();
        if(curn.h > maxh) break;
        pq_h.pop();
        for(int j=0;j<(int)G[curn.id].size();j++){
          if(h[G[curn.id][j]] <= maxh){
            dsunion(curn.id, G[curn.id][j]);
          }
        }
      }
      if(dsfind(curq.a) == dsfind(curq.b)) {
        ans[curq.id] = 1;
      } else {
        ans[curq.id] = 0;
      }
    }
    for(int i=0;i<q;i++){
      if(ans[i]) cout << "YES\n"; 
      else cout << "NO\n"; 
    }
    cout << '\n';
  }
  return 0;
}