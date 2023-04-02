#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX_V 100000
struct edge{ int to, cost;};
vector<edge> G[MAX_V];
int G_color[MAX_V]; //0で初期化、1が黒、-1が白
int V; // 頂点数

void dfs(int v, int color) {
    G_color[v] = color;
    int opp_color;
    if (color == 1) opp_color = -1;
    else            opp_color =  1;

    for (int i=0; i<G[v].size(); i++) {
        // 選択中の隣接頂点と、その頂点に向かう辺の重み
        int v_to   = G[v].at(i).to;
        int v_cost = G[v].at(i).cost;

        if (G_color[v_to] != 0) {
            // すでに塗られている場合
            continue;
        }

        if (v_cost % 2 == 0) {
            // 辺の重みが偶数の場合。同じ色で塗る
            dfs(v_to, color);
        }
        else {
            dfs(v_to, opp_color);
        }
    }
}

int main() {
    cin >> V;
    for (int i=0; i<V-1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        edge u_edge = {v, w};
        edge v_edge = {u, w};
        G[u].push_back(u_edge);
        G[v].push_back(v_edge);
    }
    dfs(0, 1);
    for (int i=0; i<V; i++) {
        int color = G_color[i];
        if (color == -1) color = 0;
        cout << color << endl;
    }
}