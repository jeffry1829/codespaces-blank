#include <bits/stdc++.h>
using namespace std;

const int _n = 510;

int t,n;
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        unordered_map<int,int> mp;
        vector<int> a;
        for(int i=0;i<n;i++){
            int tmp;
            cin>>tmp;
            a.push_back(tmp);
            mp[a[i]]++;
        }
        bool cont = false;
        for(int i=0;i<n;i++){
            if(mp[a[i]] % 2 != 0){
                cout<<-1<<'\n';
                cont = true;
                break;
            }
        }
        if(cont) continue;
        vector<pair<int,int>> ans;
        vector<int> ans2;
        vector<int> tmpvs;
        int cur_anchor = -1;
        for(int i=0;i<a.size();i++){
            if(cur_anchor == -1){
                cur_anchor = a[i];
            }else{
                if(a[i] != cur_anchor){
                    tmpvs.push_back(a[i]);
                }else{
                    cur_anchor = -1;
                    for(int j=0;j<tmpvs.size();j++){
                        ans.push_back({i+j+1, tmpvs[j]});
                        a.insert(a.begin() + i+j+1, tmpvs[j]);
                        a.insert(a.begin() + i+j+1, tmpvs[j]);
                    }
                    ans2.push_back(2*(tmpvs.size()+1));
                    i+=tmpvs.size();
                    tmpvs.clear();
                }
            }
        }
        cout<<ans.size()<<'\n';
        for(int i=0;i<ans.size();i++){
            cout<<ans[i].first<<' '<<ans[i].second<<'\n';
        }
        cout<<ans2.size()<<'\n';
        for(int i=0;i<ans2.size();i++){
            cout<<ans2[i]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}