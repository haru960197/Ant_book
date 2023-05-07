#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll extgcd(ll a, ll b, ll &x, ll &y) {
    ll d = a;
    if (b != 0) {
        d = extgcd(b, a % b, y, x);
        y -= (a / b) * x;
    } else {
        x = 1; y = 0;
    }
    return d;
}
int main() {
    ll a, b; cin >> a >> b;
    ll x, y;
    extgcd(a, b, x, y);
    cout << x << ' ' << y << endl;
}