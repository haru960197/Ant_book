#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int N; cin >> N;
    pair<ll, ll> pos[N]; //pos[].firstは後ろの値、pos[].secondが前の値
    for(int i=0; i<N; i++){
        ll x, l;
        cin >> x >> l;
        pos[i].first = x+l;
        pos[i].second = x-l;
    }
    sort(pos, pos+N);
    int ans = 1, robot_num = 0, i;
    while(robot_num < N){
        ll cur_right = pos[robot_num].first;
        for(i=robot_num+1; i<N; i++){
            ll next_left = pos[i].second;
            if(cur_right <= next_left) break;
        }
        robot_num = i;
        if(i!=N) ans++;
    }
    cout << ans << endl;
}