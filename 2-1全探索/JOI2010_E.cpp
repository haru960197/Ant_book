#include <bits/stdc++.h>
using namespace std;
#define map MAP
int H, W, N, ans=0;
typedef pair<int, int> P;
vector<vector<char>> map(1000, vector<char>(1000));
vector<vector<int>> map_count(1000, vector<int>(1000));
const int INF = 1000000;
int dy[4] = {-1, 0, 1, 0}, dx[4] = {0, 1, 0, -1};

void initialize(){
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            map_count[i][j] = INF;
        }
    }
}
int bfs(P s, P g){
    //sからgにかかる時間を返す
    queue<P> q;
    q.push(s);
    map_count[s.first][s.second] = 0;
    while(q.size()){
        P cur_pos = q.front();
        q.pop();
        if(cur_pos == g) break;
        for(int i=0;i<4;i++){
            P npos(cur_pos.first + dy[i], cur_pos.second + dx[i]);
            if(npos.first < 0 || npos.first >= H || npos.second < 0 || npos.second >= W) continue;
            if(map_count[npos.first][npos.second]!=INF) continue; //訪問済み
            if(map[npos.first][npos.second]=='X') continue; //壁
            map_count[npos.first][npos.second] = map_count[cur_pos.first][cur_pos.second]+1;
            q.push(npos);
        }
    }
    return map_count[g.first][g.second];
}
int main(){
    cin >> H >> W >> N;
    P factory[N], s;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            char c; cin >> c;
            if(c == 'X') map[i][j] = c;
            else{
                if(c == 'S'){
                    s.first = i;
                    s.second = j;
                }
                if('1' <= c && c <= '9'){
                    int num = c-'1'; //factory[0]は工場1の座標
                    factory[num].first = i;
                    factory[num].second = j;
                }
                map[i][j] = '.';
            }
        }
    }
    //入力終わり
    initialize();
    ans += bfs(s, factory[0]); //s -> 1
    for(int i=0;i<N-1;i++){
        initialize();
        ans += bfs(factory[i], factory[i+1]);
    }
    cout << ans << endl;
}