#include <bits/stdc++.h>
using namespace std;
struct edge { int to, cost; };
typedef pair<int, int> P; // first:木Tとつながるコスト second:頂点番号
vector<edge> G[10001];
bool used[10001];
int V, E;
int prim() {
    int res = 0;
    priority_queue<P, vector<P>, greater<P> > que;
    fill(used, used + V, false);
    que.push(P(0, 0));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (used[v]) continue; // 頂点vはすでに木Tに属している
        
        // 頂点vを木Tに加える
        res += p.first;
        used[v] = true;
        for (int i=0; i<G[v].size(); i++) {
            edge e = G[v][i];
            if (used[e.to]) continue;
            // 頂点e.toをqueに追加
            que.push(P(e.cost, e.to));
        }
    }
    return res;
}
int main() {
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int s, t, w; cin >> s >> t >> w;
        edge e_s = {t, w};
        G[s].push_back(e_s);
        edge e_t = {s, w};
        G[t].push_back(e_t);
    }
    cout << prim() << endl;
}
