// 팩토리얼 값의 2와 5의 지수 구하는 방법, pair형을 return 하는 함수 작성하는 방법.

#include <iostream>
#include <utility> // for pair
#include <algorithm> // for min

using namespace std;

pair<long long, long long> two_five(long long x) {
  long long two = 0, five = 0;
  for(long long i = 2; i <= x; i *= 2) two += x/i;
  for(long long i = 5; i <= x; i *= 5) five += x/i;
  return make_pair(two, five);
}

int main() {
  ios_base::sync_with_stdio(false);
  long long n, m;
  cin >> n >> m;
  cout << min(two_five(n).first - two_five(m).first - two_five(n-m).first, two_five(n).second - two_five(m).second - two_five(n-m).second);
  return 0;
}
