//Euclidean algorithm
#include <iostream>

using namespace std;

// iteration
int GCD(int a, int b) {
  int r;
  while(b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

/* recursion
int GCD(int a, int b) {
  return b ? GCD(b, a%b) : a;
}
*/

int main() {
  int a, b, g, tmp;
  cin >> a >> b;

  if(a < b) {
    tmp = a;
    a = b;
    b = tmp;
  }
  g = GCD(a, b);
  cout << g << '\n';
  cout << (a * b)/g << '\n';
}
