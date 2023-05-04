#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int N, M;
const int INF = 1000000000;
int d[301][301];
void warshall_floyd() {
    rep(k, N)
        rep(i, N)
            rep(j, N)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}
int find_best_worst_case() {
    int min_time = INF;
    rep(i, N) {
        int worst_case = 0;
        rep(j, N) {
            worst_case = max(worst_case, d[i][j]);
        }
        min_time = min(min_time, worst_case);
    }
    return min_time;
}
int main() {
    cin >> N >> M;
    rep(i, N) rep(j, N) d[i][j] = INF;
    rep(i, N) d[i][i] = 0;
    rep(i, M) {
        int a, b, t; cin >> a >> b >> t;
        a--; b--;
        d[a][b] = d[b][a] = t;
    }
    warshall_floyd();
    cout << find_best_worst_case() << endl;
}
