#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

void io_init();

int main() {
  io_init();
  string s;
  stack<char> l, r;
  int n;
  cin >> s;
  for(int i = 0; i < s.size(); i++) l.push(s[i]);
  cin >> n;
  for(int i = 0; i < n; i++) {
    char tmp, c;
    cin >> tmp;
    if(tmp == 'P') {
      cin >> c;
      l.push(c);
    }
    else if(tmp == 'L' && !l.empty()) {
      r.push(l.top());
      l.pop();
    }
    else if(tmp == 'D' && !r.empty()) {
      l.push(r.top());
      r.pop();
    }
    else if(tmp == 'B' && !l.empty()) l.pop();
    else continue;
  }

  while(!l.empty()) {
    r.push(l.top());
    l.pop();
  }

  while(!r.empty()) {
    cout << r.top();
    r.pop();
  }
  return 0;
}

void io_init() { // initialize input and output
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return;
}
