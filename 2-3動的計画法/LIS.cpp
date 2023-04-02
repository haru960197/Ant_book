#include <bits/stdc++.h>
using namespace std;
int dp[100001];
const int INF = 10000000;
int main(){
    int n; cin >> n;
    int nums[n];
    for(int i=0; i<n; i++) cin >> nums[i];
    fill(dp, dp+1+n, INF);
    for(int i=0; i<n; i++){
        *lower_bound(dp, dp+n, nums[i]) = nums[i];
    }
    int max_length;
    for(int i=0; i<100001; i++){
        if(dp[i] == INF){
            max_length = i;
            break;
        }
    }
    cout << max_length << endl;
}