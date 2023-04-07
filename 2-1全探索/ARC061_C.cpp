#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int nums[11];
int num_size;
ll dfs(int step, ll semi_sum, ll sum) {
  ll num = semi_sum * 10 + nums[step];
  if (step == num_size - 1) {
    return sum + num;
  }
  step++;
  ll ret = 0;
  ret += dfs(step, num, sum);
  ret += dfs(step, 0, sum + num);
  return ret;
}
int main() {
  string s;
  cin >> s;
  num_size = s.size();
  for (int i=0; i<num_size; i++) {
    nums[i] = s.at(i) - '0';
  }
  cout << dfs(0, 0, 0) << endl;
} 