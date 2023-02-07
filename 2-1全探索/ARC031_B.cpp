#include <bits/stdc++.h>
using namespace std;
bool MAP[10][10]; //陸地がtrue

bool checker(bool** MAP);
void dfs(int y, int x, bool **MAP);

int main(){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            char c; cin >> c;
            MAP[i][j] = ( c == 'o');
        }
    }
    bool **new_MAP = (bool **)malloc(sizeof(bool*)*10);
    for(int i=0; i<10; i++) new_MAP[i] = (bool*)malloc(sizeof(bool)*10);
    bool flag = false;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(MAP[10][10]) continue; //陸地だったらスキップ
            else{
                for(int i2=0; i2<10; i2++){
                    for(int j2=0; j2<10; j2++) new_MAP[i2][j2] = MAP[i2][j2]; //new_MAPを初期化
                }
                new_MAP[i][j] = true;
                dfs(i, j, new_MAP); //ここで島を塗りつぶす
                if(checker(new_MAP)){ //すべて海になっていたら
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
    }
    if(flag) cout << "YES" << endl;
    else cout << "NO" << endl;
    for(int i=0;i<10;i++) free(new_MAP[i]);
    free(new_MAP);
}
void dfs(int y, int x, bool** MAP){
    if(y<0 || y>=10 || x<0 || x>=10) return;
    if(!MAP[y][x]) return; //海だった
    //陸地だった
    MAP[y][x] = false;
    dfs(y-1, x, MAP);
    dfs(y, x+1, MAP);
    dfs(y+1, x, MAP);
    dfs(y, x-1, MAP);
}
bool checker(bool** MAP){
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++) if(MAP[i][j]) return false; //陸地発見
    }
    return true;
}