#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

struct edge { int to, from, cost; };
int V, E;
edge es[2001];
int d[1001]; // 始点から各頂点への最短距離
const int INF = 100000000;
bool bellmanford(int s) {
    // 返り値
    // 負の閉路が存在：true
    // 　　存在しない：false
    rep(i, V) d[i] = INF;
    d[s] = 0;
    bool update;
    rep(i, V + 1) {
        update = false;
        rep(j, E) {
            edge e = es[j];
            if (d[e.from] != INF &&
                    d[e.to] > d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                update = true;
            }
        }
    }
    if (update) return true;
    else return false;
}
int main() {
    int s;
    cin >> V >> E >> s;
    rep(i, E) {
        cin >> es[i].from >> es[i].to >> es[i].cost;
    }
    bool haveNegativeCycle = bellmanford(s);
    if (haveNegativeCycle) {
        cout << "NEGATIVE CYCLE" << endl;
        return 0;
    }
    rep(i, V) {
        if (d[i] == INF) cout << "INF" << endl;
        else cout << d[i] << endl;
    }
}