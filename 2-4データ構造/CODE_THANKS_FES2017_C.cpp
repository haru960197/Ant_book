#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, K;
ll b[100000];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>> > 
    time_cost; // {かかる時間, 機械番号}
ll ans = 0;
int main() {
    cin >> N >> K;
    for (int i=0; i<N; i++) {
        ll a;
        cin >> a >> b[i];
        time_cost.push(make_pair(a, i));
    }
    for (int i=0; i<K; i++) {
        auto min_machine = time_cost.top(); time_cost.pop();
        ans += min_machine.first;
        min_machine.first += b[min_machine.second];
        time_cost.push(min_machine);
    }
    cout << ans << endl;
}