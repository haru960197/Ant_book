#include <bits/stdc++.h>
using namespace std;
int H, W;
bool dfs(int y, int x, vector<vector<char>> &map){
    if(y < 0 || y >= H || x < 0 || x >= W) return false;
    char c = map[y][x];
    if(c == 'g') return true;
    else if(c == '#') return false;
    else{
        // c == 's' || c == '.'
        map[y][x] = '#';
        if(dfs(y-1, x, map)) return true;
        if(dfs(y, x+1, map)) return true;
        if(dfs(y+1, x, map)) return true;
        if(dfs(y, x-1, map)) return true;
        return false;
    }
}
int main(){
    cin >> H >> W;
    vector<vector<char>> map(H, vector<char> (W));
    pair<int, int> s;
    for(int i=0;i<H;i++){
        for(int j=0;j<W;j++){
            cin >> map[i][j];
            if(map[i][j] == 's'){
                s.first = i;
                s.second = j;
            }
        }
    }
    if(dfs(s.first, s.second, map)) cout << "Yes" << endl;
    else cout << "No" << endl;
}