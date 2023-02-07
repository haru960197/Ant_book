#include <bits/stdc++.h>
using namespace std;
int N, W;
int dp[101][10001];
int main(){
    cin >> N >> W;
    int v[N], w[N];
    for(int i=0; i<N; i++) cin >> v[i] >> w[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<=W; j++){
            if(j < w[i]) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]]+v[i]);
        }
    }
    cout << dp[N][W] << endl;
}