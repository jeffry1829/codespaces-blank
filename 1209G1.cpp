#include <bits/stdc++.h>
using namespace std;

const int _n = 2e5+10;
int n,q,a[_n],cnt[_n],ed[_n];
int main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        ed[a[i]] = max(ed[a[i]], i);
    }
    int idx = 1, target = 1, max_a = -1, ans = 0, len = 0;
    while(idx <= n) {
        len = 0;
        while(idx <= target){
            cnt[a[idx]]++;
            if(max_a == -1 || (max_a != -1 && cnt[a[idx]] > cnt[max_a])){
                max_a = a[idx];
            }
            target = max(target, ed[a[idx]]);
            idx++;
            len++;
        }
        ans += len - cnt[max_a];
        // idx++;
        max_a = -1;
        target = idx;
    }
    cout<<ans<<'\n';
    return 0;
}