#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge {
    int to;
    ll yen, snook;
};
vector<edge> G[5];
int main() {
    G[0].push_back(edge{1,2,3});
    cout << G[0][0].to << endl << G[0][0].yen << endl << G[0][0].snook << endl;
}