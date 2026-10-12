#include <bits/stdc++.h>
using namespace std;

const int _n = 110;
int n,a[_n],b[_n],dp[_n][_n*_n];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    int asum = 0;
    int bsum = 0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        asum += a[i];
        bsum += b[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=asum;j++){
            dp[i][j] = -0x7f7f7f7f;
        }
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j>=1;j--){
            for(int k=1;k<=asum;k++){
                if(k - a[i] >= 0){
                    dp[j][k] = max(dp[j][k], dp[j-1][k-a[i]] + b[i]);
                }
            }
        }
    }
    cout << setprecision(9) << fixed;
    for(int i=1;i<=n;i++){
        double ans = 0;
        for(int j=1;j<=asum;j++){
            ans = max(ans, min(1.0 * j, 1.0 * dp[i][j] + 1.0 * (bsum - dp[i][j]) / 2.0));
        }
        cout << ans <<' ';
    }
    cout << '\n';
    return 0;
}