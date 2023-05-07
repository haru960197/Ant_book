#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1000000000 + 7;
map<int, int> prime_fact;
void prime_factoization(int N) {
    for (int i=2; i * i <=N; i++) {
        while (N % i == 0) {
            ++prime_fact[i];
            N /= i;
        }
    }
    if (N != 1) {
        if (!prime_fact.count(N)) prime_fact[N] = 1;  
        else prime_fact[N]++;
    }
}
int main() {
    int N; cin >> N;
    while (N > 0) {
        prime_factoization(N);
        N--;
    }
    ll ans = 1;
    for (auto prime : prime_fact) {
        ans *= prime.second + 1;
        ans %= MOD;
    }
    cout << ans << endl;
}