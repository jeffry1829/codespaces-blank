#include <bits/stdc++.h>
using namespace std;
#define prev asoijfoidg


const int _n = 2e5+10;
const int _lgn = 20;

int n,m,q,p[_n],a[_n],prev[_n],latest_idx[_n],dp[_n],dpstidx[_n],dpup[_n][_lgn],best[_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    int pprev = -1;
    for(int i=0;i<n;i++){
        cin>>p[i];
        if(i>0){
            prev[p[i]] = pprev;
        }
        pprev = p[i];
    }
    prev[p[0]] = p[n-1];

    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    memset(latest_idx, -1, sizeof(latest_idx));
    memset(dpup, -1, sizeof(dpup));
    dp[0] = 1;
    dpstidx[0] = 0;
    latest_idx[a[0]] = 0;
    dpup[0][0] = -1;
    for(int i=1;i<m;i++){
        if(latest_idx[prev[a[i]]] != -1){
            if(dp[latest_idx[prev[a[i]]]] == n){
                dp[i] = n;
                
            }else{
                dp[i] = 1 + dp[latest_idx[prev[a[i]]]];
                dpstidx[i] = dpstidx[latest_idx[prev[a[i]]]];
            }
            dpup[i][0] = latest_idx[prev[a[i]]];
        }else{
            dp[i] = 1;
            dpstidx[i] = i;
            dpup[i][0] = -1;
        }

        for(int j=1;j<_lgn;j++){
            if(dpup[i][j-1] == -1){
                dpup[i][j] = -1;
            }else{
                dpup[i][j] = dpup[dpup[i][j-1]][j-1];
            }
        }

        if(latest_idx[prev[a[i]]] != -1 && dp[latest_idx[prev[a[i]]]] == n){
            int st = i;
            int step = n-1;
            for(int j=0;j<_lgn;j++){
                if((1 << j) & step) {
                    st = dpup[st][j];
                }
            }
            dpstidx[i] = st;
        }
        

        latest_idx[a[i]] = i;
    }

    best[0] = (n == 1) ? 1 : -1;
    for(int i=1;i<m;i++){
        best[i] = max(best[i-1], dp[i]==n?dpstidx[i]:-1);
    }

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        l--,r--;
        if(best[r] >= l) cout<<"1";
        else cout<<"0";
    }
    cout<<'\n';

    return 0;
}