#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll x, y;
    cin >> x >> y;
    int A_length = 0;
    ll A_n = x;
    while(A_n <= y){
        A_n *= 2;
        A_length++;
    }
    cout << A_length << endl;
}