#include <bits/stdc++.h>
using namespace std;
int coins[6] = {500, 100, 50, 10, 5, 1};
int main(){
    int money, ans = 0;
    cin >> money;
    money = 1000 - money;
    for(int i=0;i<6;i++){
        int coin = coins[i];
        while(money / coin){
            ans++;
            money -= coin;
        }
    }
    cout << ans << endl;
}