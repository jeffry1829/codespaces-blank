#include <bits/stdc++.h>
using namespace std;

const int _n = 2e5 + 10, _lgn = 20;
int t,n,a[_n],ans[_n],suf_max[_n];
vector<int> idxs[_lgn];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=0;i<_lgn;i++){
            idxs[i].clear();
        }
        int lastidx = -1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i] != -1){
                idxs[a[i]].push_back(i);
            }else{
                lastidx = i;
            }
        }
        suf_max[n-1] = a[n-1]==-1?0x7f7f7f7f:a[n-1];
        for(int i=n-2;i>=0;i--){
            int tmp = a[i];
            if(a[i] == -1) tmp = 0x7f7f7f7f;
            suf_max[i] = max(suf_max[i+1], tmp);
        }
        for(int i=1;i<_lgn;i++){
            if(idxs[i].empty()) continue;
            int fst = idxs[i].back();
            int fstidx = idxs[i].size()-1;
            for(int j=(int)idxs[i].size()-1;j>=0;j--){
                if(suf_max[idxs[i][j]] > i) break;
                fst = idxs[i][j];
                fstidx = j;
            }
            reverse(idxs[i].begin()+fstidx, idxs[i].end());
        }
        int minnum = 1, maxnum = n;
        for(int i=1;i<_lgn;i++){
            if(idxs[i].empty()) continue;
            for(int j=0;j<idxs[i].size();j++){
                if(i % 2 == 1){ // NOT min -> max
                    ans[idxs[i][j]] = maxnum--;
                }else{ // NOT max -> min
                    ans[idxs[i][j]] = minnum++;
                }
            }
        }
        ans[lastidx] = minnum;
        assert(minnum == maxnum);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}