#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  ios_base::sync_with_stdio(false);
  vector<int> dp, p;
  vector<int> dp_list[1001]; // array with element type 'vector'
  int dpmax, t, tmp, flag;
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> tmp;
    p.push_back(tmp); //p.push_back(tmp);
    dp.push_back(1);
  }

  dpmax = 1;
  flag = 0;
  for(int i = 0; i < t; i++) {
    dp_list[i].push_back(p[i]);
    for(int j = 0; j < i; j++) {
      if(p[j] < p[i] && dp[i] < dp[j] + 1) {
        dp_list[i].clear();
        dp_list[i] = dp_list[j];
        dp_list[i].push_back(p[i]);
        dp[i] = dp[j] + 1;
      }
    }
    if(dpmax < dp[i]) {
      dpmax = dp[i];
      flag = i;
    }
  }

  cout << dpmax << '\n';
  for(int i = 0; i < dp_list[flag].size(); i++) cout << dp_list[flag][i] << " ";
  return 0;
}
