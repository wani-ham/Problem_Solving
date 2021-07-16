 
#include <iostream>

using namespace std;

void print_arr();
void bt(int cnt);

int arr[9];
int n, m;

int main() {
  cin >> n >> m;
  bt(0);
  return 0;
}

void print_arr() {
  for(int i = 0; i < m; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return;
}

void bt(int cnt) {
  if(cnt == m) {
    print_arr();
    return;
  }

  for(int i = 1; i <= n; i++) {
    if(0 == cnt || arr[cnt - 1] <= i) {
        arr[cnt] = i;
        bt(cnt + 1);
    }
  }
  return;
}
