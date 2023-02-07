#include <bits/stdc++.h>
using namespace std;
int N, M;
int search(vector<vector<bool>> sides){
    int ret = 0;
    int nodes[N-1];
    for(int i=0;i<N-1;i++) nodes[i] = i+1; //ノード1~N-1のみ。ノード0は始点で固定
    do{
        for(int i=0; i<N-1;i++){
            int node1, node2;
            if(i==0){
                node1 = 0; //始点はノード0で固定
                node2 = nodes[0];
            }
            else{
                node1 = nodes[i-1];
                node2 = nodes[i];
            }
            if(!sides[node1][node2]) break; //node1とnode2を結ぶ辺がない
            if(i == N-2) ret++; //全頂点を一度だけ訪れるパス発見
        }
    } while(next_permutation(nodes, nodes+N-1));
    return ret;
}
int main(){
    cin >> N >> M;
    vector<vector<bool>> sides(N, vector<bool>(N, false));
    for(int i=0;i<M;i++){
        int a, b; cin >> a >> b;
        a--; b--; //ノード1をノード0, とする。
        sides[a][b] = sides[b][a] = true;
    }
    cout << search(sides) << endl;
}