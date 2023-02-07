#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int N; cin >> N;
    priority_queue<ll> q;
    for(int i=0; i<N; i++){
        ll tmp; cin >> tmp;
        q.push(tmp);
    } //nlogn
    ll ans = 0;
    while(q.size()>1){
        ll max, pre_max;
        max = q.top();
        q.pop();
        pre_max = q.top();
        q.pop();
        ans += max + pre_max;
        q.push(max + pre_max);
    } //nlogn
    ans += q.top();
    cout << ans << endl;
}