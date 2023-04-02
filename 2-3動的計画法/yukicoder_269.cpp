#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[101][20001];
ll M = pow(10,9) + 7;
int N, S, K;
int main(){
    cin >> N >> S >> K;
    int i, j;
    dp[0][0] = 1;
    for(i=1; i<=N; i++){
        for(j=0; j<=S; j++){
            if(j-i >=0 && j-(i-1)*K >= 0){
                dp[i][j] = (dp[i][j-i] + dp[i-1][j-(i-1)*K]) % M;
            }
            else if(j-i >= 0 && j-(i-1)*K < 0){
                dp[i][j] = dp[i][j-i] % M;
            }
            else if(j-i < 0 && j-(i-1)*K >= 0){
                dp[i][j] = dp[i-1][j-(i-1)*K] % M;
            }
        }
    }
    cout << dp[N][S] << endl;
}