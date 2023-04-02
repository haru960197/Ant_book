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
int main() {
    int N, K, L;
    cin >> N >> K >> L;
    unionFindTree ruft(N), tuft(N);
    map<pair<int, int>, int> united_cities;
    ruft.init(N); tuft.init(N);
    for (int i=0; i<K; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        ruft.unite(p, q);
    }
    for (int i=0; i<L; i++) {
        int p, q;
        cin >> p >> q;
        p--; q--;
        tuft.unite(p, q);
    }

    for (int i=0; i<N; i++) {
        // ここで根の数値を統一
        ruft.find(i);
        tuft.find(i);
    }
    for (int i=0; i<N; i++) {
        // mapで{ruft[i], tuft[i]}の種類と個数を整理
        pair<int, int> united_city = {ruft.par[i], tuft.par[i]};
        if (united_cities.count(united_city)) {
            united_cities.at(united_city)++;
        }
        else {
            united_cities[united_city] = 1;
        }
    }

    for (int i=0; i<N; i++) {
        pair<int, int> united_city = {ruft.par[i], tuft.par[i]};
        cout << united_cities.at(united_city) << ' ';
    }
    cout << endl;
}