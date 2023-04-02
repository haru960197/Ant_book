#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P; // {コスト, 頂点番号}
struct edge {
    int to;
    ll yen, snook;
};
const ll INF = 1000000000000000;
int N, M, s, t;
ll d_yen[100001];   // sから各頂点への円コスト
ll d_snook[100001]; // 各頂点からtへのsnookコスト
vector<edge> G[100001]; // 隣接リスト
void dijkstra(int s, ll *d, string currency) {
    // s:出発頂点, d:d_yenかd_snook, currency:"yen" or "snook"
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + N, INF + 1);
    d[s] = 0;
    que.push(P(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;
        for (int i=0; i<G[v].size(); i++) {
            edge &e = G[v][i];
            ll cost;
            if (currency == "yen") cost = e.yen;
            else cost = e.snook;
            if (d[e.to] > d[v] + cost) {
                d[e.to] = d[v] + cost;
                que.push(P(d[v] + cost, e.to));
            }
        }    
    }
}
void init() {
    cin >> N >> M >> s >> t;
    s--; t--;
    for (int i=0; i<M; i++) {
        int u, v;
        ll a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        G[u].push_back(edge{v, a, b});
        G[v].push_back(edge{u, a, b});
    }
}
int main() {
    init();
    dijkstra(s, d_yen, "yen");
    dijkstra(t, d_snook, "snook");
    priority_queue<P, vector<P>, greater<P> > que;
    for (int i=0; i<N; i++) {
        que.push(P(d_yen[i] + d_snook[i], i));
    }
    int ans_line = 1;
    while (ans_line <= N) {
        int now_year = ans_line - 1;
        P p = que.top();
        if (p.second + 1 <= now_year){
            // 頂点番号 < 今の年
            que.pop();
            continue;
        }
        cout << INF - p.first << endl;
        ans_line++;
    }
}