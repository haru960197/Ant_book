#include <bits/stdc++.h>
using namespace std;
int w[100], v[100];
int rec(int i, int weight){
    int res;
    if(i<0) res = 0;
    else if(w[i] > weight) res = rec(i-1, weight);
    else res = max(rec(i-1, weight), rec(i-1, weight - w[i])+v[i]);
    return res;
}
int main(){
    int N, W;
    cin >> N >> W;
    for(int i=0; i<N; i++){
        cin >> w[i] >> v[i];
    }
    cout << rec(N, W) << endl;
}