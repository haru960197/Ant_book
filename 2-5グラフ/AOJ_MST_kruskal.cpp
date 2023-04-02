#include <bits/stdc++.h>
using namespace std;
struct unionFindTree {
    int *par;
    int *rank;
    // 配列の最大サイズを指定して配列を確保
    unionFindTree(int MAX_SIZE) {
        par = (int*)malloc(sizeof(int) * MAX_SIZE);
        rank = (int*)malloc(sizeof(int) * MAX_SIZE);
    }

    // n要素で初期化
    void init(int n) {
        for (int i=0; i<n; i++) {
            par[i] = i;
            rank[i] = 0;
        }
    }

    // 木の根を求める
    int find(int x) {
        if (par[x] == x) {
            return x;
        } else {
            // 根が親になるよう再配置
            return par[x] = find(par[x]);
        }
    }

    // xとyの属する集合を併合
    void unite(int x, int y) {
        int par_x = find(x);
        int par_y = find(y);
        if (par_x == par_y) return;

        if (rank[par_x] < rank[par_y]) {
            par[par_x] = par_y;
        } else {
            par[par_y] = par_x;
            if (rank[par_x] == rank[par_y]) rank[par_x]++;
        }
    }

    // xとyが同じ集合に属するか否か
    bool same(int x, int y) {
        return find(x) == find(y);
    }

    // 確保したメモリを解放する
    void clean() {
        free(par);
        free(rank);
    }
};
struct edge { int u, v, cost; };
bool comp(edge& e1, edge& e2) { return e1.cost < e2.cost; }
int V, E;
edge es[100001];
int Kruskal() {
    unionFindTree uft(V);
    sort(es, es + E, comp);
    uft.init(V);
    int res = 0;
    for (int i=0; i<E; i++) {
        edge e = es[i];
        if (!uft.same(e.u, e.v)) {
            uft.unite(e.u, e.v);
            res += e.cost;
        }
    }
    return res;
}
int main() {
    cin >> V >> E;
    for (int i=0; i<E; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        edge e = {u, v, cost};
        es[i] = e;
    }
    cout << Kruskal() << endl;
}