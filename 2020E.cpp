#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll _n = 2e5+10;
const ll mod = 1e9+7;

ll powmod(ll a,ll b){
    ll res = 1;
    while(b){
        if(b & 1){
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

const ll inv1e4 = powmod(10000, mod - 2);
ll t,n,a[_n],p[_n],dp[4];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>p[i];
            p[i] = p[i] * inv1e4 % mod;
        }
        ll ans = 0;
        for(int i=0;i<10;i++){
            for(int j=0;j<=i;j++){
                dp[0] = 1;
                dp[1] = dp[2] = dp[3] = 0;
                for(int k=0;k<n;k++){
                   ll mask = ((a[k] >> i) & 1) | (((a[k] >> j) & 1) << 1);
                   ll q = (1 - p[k] + mod) % mod;
                   ll dp2[4] = {0};
                   for(int l=0;l<4;l++){
                    dp2[l ^ mask] = p[k] * dp[l] % mod + q * dp[l ^ mask] % mod;
                   }
                   for(int l=0;l<4;l++){
                    dp[l] = dp2[l];
                   }
                }
                ans = (ans + (dp[3] << (i+j + (i!=j)))) % mod;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}