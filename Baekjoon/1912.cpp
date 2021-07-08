#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> dp, p;
  int t, tmp, dpmax = -1000;

  cin >> t;
  for(int i = 0; i < t; i++) {
    cin >> tmp;
    p.push_back(tmp);
  }

  dp.push_back(p.front());
  for(int i = 1; i < t; i++) {
    dp.push_back(max(dp[i-1] + p[i], p[i]));
    dpmax = max(dpmax, dp[i]);
  }

  cout << max(dpmax, dp.front());
  return 0;
}
