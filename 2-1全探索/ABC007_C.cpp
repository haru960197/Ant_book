#include <bits/stdc++.h>
using namespace std;
const int INF = 10000000;
int H, W;
pair<int, int> s, g;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, +1, 0};
void bfs(vector<vector<char>> map, vector<vector<int>> &map_count){
    queue<pair<int, int>> q;
    q.push(s);
    map_count[s.first][s.second] = 0;
    do{
        pair<int, int> pos = q.front();
        q.pop();
        if(pos == g) break;
        for(int i=0; i<4; i++){
            pair<int, int> tmp;
            tmp.first = pos.first + dx[i];
            tmp.second = pos.second + dy[i];
            if(tmp.first < 0 || tmp.first >= H || tmp.second < 0 || tmp.second >= W) continue;
            if(map[tmp.first][tmp.second] == '#') continue; //壁
            else if(map_count[tmp.first][tmp.second]!=INF) continue; //訪問済み
            else{
                map_count[tmp.first][tmp.second] = map_count[pos.first][pos.second] + 1;
                q.push(tmp);
            }
        }

    } while(q.size());
}
int main(){
    cin >> H >> W;
    cin >> s.first >> s.second;
    cin >> g.first >> g.second;
    s.first--; s.second--; g.first--; g.second--; //入力は、配列の要素番号が1スタートだから。
    vector<vector<char>> map(H, vector<char>(W));
    vector<vector<int>> map_count(H, vector<int>(W, INF));
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++) cin >> map[i][j];
    }
    bfs(map, map_count);
    cout << map_count[g.first][g.second] << endl;
}