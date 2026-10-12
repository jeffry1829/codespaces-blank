#include <bits/stdc++.h>
using namespace std;

const int _n = 1e5+10;
int n,m,q;
unordered_map<string,int> dict;

#define rank suhfiaufhiaughagq
int parent[2*_n], rank[2*_n];
void dsinit(int nn){
    for(int i=0;i<nn;i++){
        parent[i] = i;
    }
    memset(rank, 0, sizeof(rank));
}
int dsfind(int e){
    return e == parent[e] ? e : parent[e] = dsfind(parent[e]);
}
void dsunion(int a, int b){
    a = dsfind(a);
    b = dsfind(b);
    if(rank[a] < rank[b]) swap(a,b);
    parent[b] = a;
    if(rank[a] == rank[b]) rank[a]++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    dsinit(2*n+2);
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        dict[word] = i;
    }
    for(int i=0;i<m;i++){
        string sx,sy;
        int t,x,y;
        cin>>t>>sx>>sy;
        x = dict[sx];
        y = dict[sy];
        if(t==1){
            if(dsfind(x) == dsfind(y+n) || dsfind(x+n) == dsfind(y)){
                cout<<"NO\n";
                continue;
            }
            dsunion(dsfind(x), dsfind(y));
            dsunion(dsfind(x+n), dsfind(y+n));
            cout<<"YES\n";
        }else{
            if(dsfind(x) == dsfind(y) || dsfind(x+n) == dsfind(y+n)){
                cout<<"NO\n";
                continue;
            }
            dsunion(dsfind(x), dsfind(y+n));
            dsunion(dsfind(x+n), dsfind(y));
            cout<<"YES\n";
        }
    }
    for(int i=0;i<q;i++){
        string sx,sy;
        int x,y;
        cin>>sx>>sy;
        x = dict[sx];
        y = dict[sy];
        if(dsfind(x) == dsfind(y) || dsfind(x+n) == dsfind(y+n)){
            cout<<1<<'\n';
        }else if(dsfind(x) == dsfind(y+n) || dsfind(x+n) == dsfind(y)){
            cout<<2<<'\n';
        }else{
            cout<<3<<'\n';
        }
    }
    return 0;
}