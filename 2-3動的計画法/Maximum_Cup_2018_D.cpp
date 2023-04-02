#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[10001][1000];
int oil[10000];
const ll INF = 1000000000;
int main(){
    int i, j, N, M, L, X;
    cin >> N >> M >> L >> X;
    for(i=0; i<N; i++) cin >> oil[i];
    fill(dp[0], dp[N+1], INF);
    dp[0][0] = 0;
    for(i=0; i<N; i++){
        for(j=0; j<M; j++){
            int move_dist = oil[i]%M;
            int prev_pos;
            if(j - move_dist >= 0) prev_pos = j - move_dist;
            else prev_pos = M + (j - move_dist);
            dp[i+1][j] = min(dp[i][j], dp[i][prev_pos]+oil[i]);
        }
    }
    if(dp[N][L] <= L + M*(X-1)) cout << "Yes" << endl;
    else cout << "No" << endl;
}