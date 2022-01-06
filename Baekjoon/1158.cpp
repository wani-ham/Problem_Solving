// BOJ 1158
// Using queue
#include <iostream>
#include <queue>

using namespace std;

void io_init();
void init_q(int n);

queue<int> q;

int main() {
  io_init();
  int n, k;
  cin >> n >> k;
  init_q(n);
  cout << "<";
  while(!q.empty()) {
    for(int i = 0; i < k-1; i++) {
      q.push(q.front());
      q.pop();
    }
    cout << q.front();
    if(q.size() != 1) cout << ", ";
    q.pop();
  }
  cout << ">";
  return 0;
}

void io_init() { // initialize input and output
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  return;
}

void init_q(int n) {
  for(int i = 1; i <= n; i++) {
    q.push(i);
  }
}
