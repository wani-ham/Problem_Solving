#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  vector<int> tot, p;
  int n, tmp;
  cin >> n;
  cin.ignore();

  p.push_back(0); // align with index
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    p.push_back(tmp);
  }

  tot.push_back(0); // align with index
  tot.push_back(p[1]); // n = 1
  tot.push_back(min(2*p[1], p[2])); // n = 2
  for(int i = 3; i <= n; i++) {
    int min = 10000*1000 + 1;
    for(int j = 1; j <= i; j++) {
      if(min > p[j] + tot[i-j]) min = p[j] + tot[i-j];
    }
    tot.push_back(min);
  }

  cout << tot[n];
  return 0;
}
