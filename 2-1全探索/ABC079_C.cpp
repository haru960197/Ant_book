#include <bits/stdc++.h>
using namespace std;
int N[4];
char OP[4];
void print(){
    for(int i=0;i<4;i++){
        if(i==0){
            cout << N[0];
            continue;
        }
        else{
            cout << OP[i] << N[i];
        }
    }
    cout << "=7" << endl;
}
bool dfs(int pos, int sum, char op){
    OP[pos] = op;
    if(op == '+') sum += N[pos];
    else sum -= N[pos];
    if(pos == 3){
        if(sum == 7){
            print();
            return true;
        }
        return false;
    }
    else{
        pos++;
        if(dfs(pos, sum, '+')) return true;
        if(dfs(pos, sum, '-')) return true;
        return false;
    }
}
int main(){
    for(int i=0;i<4;i++){
        char c; cin >> c;
        N[i] = c - '0';
    }
    dfs(0, 0, '+');
}