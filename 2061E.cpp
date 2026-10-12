#include <bits/stdc++.h>
using namespace std;

const int _n = 1e5+10;
int t,n,m,k,a[_n],b[15],best[_n][15],ormask[1124];
int main(){
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int maxx = 1 << m;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<=m;j++){
                best[i][j] = 0;
            }
        }
        for(int j=0;j<maxx;j++){
            int tmp = 0;
            for(int l=0;l<m;l++){
                if(((1 << l) & j) != 0){
                    tmp |= (~b[l]);
                }
            }
            ormask[j] = (~tmp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<maxx;j++){
                int num = __builtin_popcount(j);
                best[i][num] = max(best[i][num], a[i] - (a[i] & ormask[j]));
            }
        }
        vector<int> v;
        for(int i=0;i<n;i++){
            for(int j=1;j<=m;j++){
                v.push_back(best[i][j] - best[i][j-1]);
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += 1ll * a[i];
        }
        for(int i=0;i<k;i++){
            sum -= 1ll * v[i];
        }
        cout << sum <<'\n';
    }
    return 0;
}