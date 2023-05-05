#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll T[101];
ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
ll lcm(ll a, ll b) {
    // a * b = gcd(a, b) * lcm(a, b) を利用
    // a / gcd(a, b) を先に計算しないとオーバーフロー
    return a / gcd(a, b) * b;
}
int main() {
    cin >> N;
    for (int i=0; i<N; i++) cin >> T[i];
    ll ans_time = T[0];
    for (int i=1; i<N; i++) {
        ans_time = lcm(ans_time, T[i]);
    }
    cout << ans_time << endl;
}