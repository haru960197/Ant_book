#include <bits/stdc++.h>
using namespace std;
int n;
long long ans = 0;
void dfs(int* num, int pos, long long sum, long long pre_num){
    if(pos == n-1){
        sum += pre_num*10 + num[pos];
        ans += sum;
        return;
    }
    dfs(num, pos+1, sum + pre_num*10 + num[pos], 0); // + 
    dfs(num, pos+1, sum, pre_num*10 + num[pos]); // 続く
}
int main(){
    string s; cin >> s;
    n = s.size();
    int num[n];
    for(int i=0;i<n;i++) num[i] = s.at(i) - '0';
    dfs(num, 0, 0, 0);
    cout << ans << endl;
}