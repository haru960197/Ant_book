#include <bits/stdc++.h>
using namespace std;
int dp[10001];
int v[101], w[101];
int main(){
    int N, W; cin >> N >> W;
    for(int i=0; i<N; i++) cin >> v[i] >> w[i];

    for(int i=0; i<N; i++){
        for(int j=0; j<=W; j++){
            if(j < w[i]) continue;
            else dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
        }
    }
    cout << dp[W] << endl;
}