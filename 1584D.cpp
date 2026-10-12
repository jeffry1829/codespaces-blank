#include <bits/stdc++.h>
using namespace std;

#define int long long

const int _lgn = 31;
int t,n;

main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int a=0,b,c;
        for(int i=_lgn;i>=0;i--){
            int tmp = a + (1LL<<i);
            if(tmp > n) continue;
            cout<<"? 1 "<<tmp<<endl;
            int reply;
            cin>>reply;
            if(reply == 0) {
                a += (1<<i);
            }
        }
        cout<<"? "<<a<<" "<<n<<endl;
        int reply1;
        cin>>reply1;
        cout<<"? "<<a+1<<" "<<n<<endl;
        int reply2;
        cin>>reply2;
        b = a + reply1 - reply2 + 1;

        cout<<"? "<<b<<" "<<n<<endl;
        int reply3;
        cin>>reply3;
        cout<<"? "<<b+1<<" "<<n<<endl;
        int reply4;
        cin>>reply4;
        c = b + reply3 - reply4;

        cout<<"! "<<a<<' '<<b<<' '<<c<<endl;
    }

    return 0;
}