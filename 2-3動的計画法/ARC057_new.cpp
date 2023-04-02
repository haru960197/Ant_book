#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll INF = 1000000000;
ll game_num[2001];// 0~N
ll dp[2001][2001];
ll game_sum = 0;
int main(){
    int N, K; cin >> N >> K;
    int i, j;
    for(i=1;i<=N;i++){
        ll tmp;
        cin >> tmp;
        game_num[i] = game_num[i-1] + tmp;
        game_sum += tmp;
    }
    fill(dp[0], dp[2001], INF);
    dp[0][0] = 0;
    for(i=0; i<N; i++){
        for(j=0; j<=i+1; j++){
            if(j-1 < 0) dp[i+1][j] = dp[i][j];
            else{
                ll minimum_wins;
                if(i==0) minimum_wins = 1;
                else minimum_wins = game_num[i+1]*dp[i][j-1]/game_num[i]+1;
                dp[i+1][j] = min(dp[i][j],minimum_wins);
            }
            if(dp[i+1][j] > game_num[i+1]) dp[i+1][j] = INF;
            else if(K - dp[i+1][j] > game_sum - game_num[i+1]){
                //残り勝ち数が残りゲーム数を上回ってしまったとき
                dp[i+1][j] = K - (game_sum - game_num[i+1]);
            }
        }
    }
    for(j=N; j>=0; j--){
        if(dp[N][j] == K){
            cout << j << endl;
            break;
        }
    }
}