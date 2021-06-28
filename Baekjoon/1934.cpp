#include <iostream>

using namespace std;

int GCD(int a, int b) {
  int r;
  while(b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int LCM(int a, int b, int gcd) {
  return (a * b) / gcd;
}

int main() {
  int t, a, b, tmp;
  cin >> t;
  cin.ignore();

  while(t--) {
    cin >> a >> b;
    cin.ignore();
    if(a < b) {
      tmp = a;
      a = b;
      b = tmp;
    }
    cout << LCM(a, b, GCD(a, b)) << '\n';
  }
  return 0;
}
