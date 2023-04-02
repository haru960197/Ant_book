#include <bits/stdc++.h>
using namespace std;
int dp[1001][1001];
int LCS_size(string, string);
int main(){
    int data_num; cin >> data_num;
    for(int i=0; i<data_num; i++){
        string x, y;
        cin >> x >> y;
        cout << LCS_size(x, y) << endl;
    }
    return 0;
}
int LCS_size(string x, string y){
    int i, j;
    int x_length = x.size(), y_length = y.size();
    //初期化
    for(i=0; i<=x_length;i++) dp[i][0] = 0;
    for(j=0; j<=y_length;j++) dp[0][j] = 0;
    //DP
    for(i=0; i<x_length; i++){
        for(j=0; j<y_length; j++){
            if(x[i] == y[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
        }
    }
    return dp[x_length][y_length];
}