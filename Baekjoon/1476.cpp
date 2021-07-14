//Solve it again with Chinese remainder theorem(CRT) and Extended Euclidean Algorithm(EEA)!

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int calc_y(int e, int s, int m);

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int e, s, m;
  cin >> e >> s >> m;

  cout << calc_y(e, s, m);
  return 0;
}

int calc_y(int e, int s, int m) {
  int year = 1;
  while(1) {
    if(((year - e) % 15 == 0) && ((year - s) % 28 == 0) && ((year - m) % 19 == 0)) {
      break;
    }
    year++;
  }
  return year;
}
