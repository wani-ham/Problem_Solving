#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> num;
  int n;//, cnt = 0;

  num.push_back(0); // align number and index
  cin >> n;

  num.push_back(1); // if n == 1
  num.push_back(2); // if n == 2
  num.push_back(3); // if n == 3

  for(int i = 4; i <= n; i++) {
    num.push_back((num[i-1] + num[i-2]) % 10007);
  }

  cout << num[n] % 10007;
  return 0;
}
