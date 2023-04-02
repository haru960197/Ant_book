#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod = pow(10,9) + 7;
// 素因数分解する数をNとする
int prime_num[100000]; //要素数は√N
int prime_index[100000];
int prime_factorization(int N, int* prime_num, int* prime_index){
    // 素因数分解した結果の素数をprime_numに。
    // 　　　　　　　　　　指数をprime_indexに。

    //返り値　素数の数 int prime_num_size
    int prime_num_size = 0;
    int p;
    for(p=2; p*p <= N; p++){
        int p_index = 0;
        while(N % p == 0){
            N /= p;
            p_index++;
        }
        if(p_index > 0){
            prime_num[prime_num_size]   = p;
            prime_index[prime_num_size] = p_index;
            prime_num_size++;
        }
    }
    if(N!=1){
        prime_num[prime_num_size]   = N;
        prime_index[prime_num_size] = 1;
        prime_num_size++;
    }
    return prime_num_size;
}
ll modpow(ll a, int p){
    // aのp乗の計算結果(modを法とする)を返す
    if(p == 0) return 1;
    if(p % 2 == 0){
        int halfP = p / 2;
        ll half = modpow(a, halfP);
        return half*half % mod;
    }
    else{
        return a * modpow(a, p-1) % mod;
    }
}
ll calcComb(int n, int m){
    // nCm (法をmodとする)を返す
    if(m > n-m) return calcComb(n, n-m);
    ll ansMul = 1;
    ll ansDiv = 1;
    for(int i=0; i<m; i++){
        ansMul *= n - i;
        ansDiv *= 1 + i;
        ansMul %= mod;
        ansDiv %= mod;
    }
    return ansMul * modpow(ansDiv, mod - 2) % mod;
}
int main(){
    int N; ll M, ans = 1;
    cin >> N >> M;
    int prime_num_size = prime_factorization(M, prime_num, prime_index);
    for(int i=0; i<prime_num_size; i++){
        int index_b = prime_index[i];
        ans *= calcComb(index_b + (N-1), index_b);
        ans %= mod;
    }
    cout << ans << endl;
}