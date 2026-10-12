#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int _n = 2e5+10;
int n,m;
ll l[_n],r[_n], ans[_n];
pair<ll,ll> a[_n];
vector<tuple<ll,ll,ll>> minmaxs;
priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>l[i]>>r[i];
    }
    for(int i=0;i<m;i++){
        ll bridge;
        cin>>bridge;
        a[i] = {bridge, i + 1};
    }
    for(int i=0;i<n-1;i++){
        ll minn = l[i+1] - r[i];
        ll maxx = r[i+1] - l[i];
        minmaxs.push_back({minn,maxx,i});
    }
    sort(minmaxs.begin(), minmaxs.end());
    sort(a, a+m);
    int minmaxidx = 0;
    ll anscnt = 0;
    for(int i=0;i<m;i++){
        ll len = a[i].first;
        ll a_idx = a[i].second;
        while(minmaxidx < n - 1 && get<0>(minmaxs[minmaxidx]) <= len && get<1>(minmaxs[minmaxidx]) >= len){
            pq.push({get<1>(minmaxs[minmaxidx]), get<2>(minmaxs[minmaxidx])});
            minmaxidx++;
        }
        if(!pq.empty()){
            pair<ll,ll> cur = pq.top();
            if(cur.first < len){
                cout<<"No\n";
                return 0;
            }
            ans[cur.second] = a_idx;
            anscnt++;
            pq.pop();
        }
    }
    if(anscnt < n-1){
        cout<<"No\n";
        return 0;
    }
    cout<<"Yes\n";
    for(int i=0;i<n-1;i++){
        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}