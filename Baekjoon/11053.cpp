#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  vector<int> p, dp;
  int dpmax, t, tmp;
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> tmp;
    p.push_back(tmp);
    dp.push_back(1);
  }

  dpmax = 1;
  for(int i = 1; i < t; i++) {
    for(int j = 0; j < i; j++) {
      if(p[j] < p[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    dpmax = max(dp[i], dpmax); // sort를 따로하지 않아도 쉽게 max 값 추출 요령!
  }

  cout << dpmax;
  return 0;
}
