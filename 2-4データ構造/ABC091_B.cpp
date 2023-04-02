#include <bits/stdc++.h>
using namespace std;
int main() {
    int N, M, ans = 0;
    map<string, int> cards;
    cin >> N;
    for (int i=0; i<N; i++) {
        string s_blue; cin >> s_blue;
        if (cards.count(s_blue)) {
            // cardsにs_blueがすでに含まれている場合
            cards.at(s_blue)++;
        }
        else {
            cards[s_blue] = 1;
        }
    }
    cin >> M;
    for (int i=0; i<M; i++) {
        string s_red; cin >> s_red;
        if (cards.count(s_red)) {
            cards.at(s_red)--;
        }
    }
    for (auto card : cards) {
        int score = card.second;
        ans = max(ans, score);
    }
    cout << ans << endl;
}