#include <bits/stdc++.h>
using namespace std;

const int _n = 1e5+10;
int t,n,m,a[_n];
set<int> separators;

int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin>>t;
  while(t--){
    cin>>n>>m;
    separators.clear();
    int minn = 0x7f7f7f7f;
    for(int i=0;i<n;i++){
      cin>>a[i];
      if(minn > a[i]){
        separators.insert(i);
        minn = a[i];
      }
    }
    
    for(int i=0;i<m;i++){
      int k,d;
      cin>>k>>d;
      k--;
      auto prev_spearator = --separators.upper_bound(k);
      int prev_idx = *prev_spearator;
      int prev_speed = a[prev_idx];
      if(a[k] - d < prev_speed){
        if(k == prev_idx){
          separators.erase(prev_spearator);
        }
        separators.insert(k);
        prev_spearator = separators.find(k);
        ++prev_spearator;
        while(prev_spearator != separators.end()) {
          if(a[*prev_spearator] >= a[k] - d){
            prev_spearator = separators.erase(prev_spearator);
          }else{
            break;
          }
        }
      }
      a[k] -= d;
      cout<<separators.size()<<' ';
    }
    cout<<'\n';
  }

  return 0;
}