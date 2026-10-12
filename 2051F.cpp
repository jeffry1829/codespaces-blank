#include <bits/stdc++.h>
using namespace std;

const int _n = 2e5 + 10;
int t,n,m,q,a[_n];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m>>q;
        for(int i=0;i<q;i++){
            cin>>a[i];
        }
        vector<pair<int,int>> lr;
        lr.push_back({m,m});
        for(int i=0;i<q;i++){
            bool skip = false;
            if(lr.size()==1 && lr[0].first <= a[i] && lr[0].second >= a[i]){
                if(lr[0].first == lr[0].second){
                    lr[0].first = -1;
                    lr[0].second = -2;
                }
                lr.push_back({1,1});
                lr.push_back({n,n});
                skip = true;
            }
            for(int j=0;j<lr.size();j++){
                if(lr[j].first==-1) continue;
                if(skip && j>0) continue;
                int& l = lr[j].first;
                int& r = lr[j].second;
                if(r < a[i]) {
                    r = r>=n?r:r+1;
                }
                if(l > a[i]){
                    l = l<=1?l:l-1;
                }
            }

            if(lr.size() == 1){
                cout<<lr[0].second - lr[0].first + 1<<' ';
            }else{
                auto L = lr[1];
                auto R = lr[2];
                auto M = lr[0];
                int sum = 0;
                bool cntl = true, cntm = true, cntr = true;
                if(L.second >= M.first){
                    M.first = 1;
                    M.second = max(M.second, L.second);
                    cntl = false;
                }
                if(R.first <= M.second){
                    M.second = n;
                    M.first = min(M.first, R.first);
                    cntr = false;
                }
                sum += M.second - M.first + 1;
                if(cntl) sum += L.second - L.first + 1;
                if(cntr) sum += R.second - R.first + 1;
                cout<<sum<<' ';
            }
        }
        cout<<'\n';
    }
    return 0;
}