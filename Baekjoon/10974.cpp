#include <iostream>

using namespace std;

void print_arr();
void bt(int cnt);

int arr[9];
bool visited[9] = {false, };
int n;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  bt(0);
  return 0;
}

void print_arr() {
  for(int i = 0; i < n; i++) {
    cout << arr[i] << " ";
  }
  cout << "\n";
  return;
}

void bt(int cnt) {
  if(cnt == n) {
    print_arr();
    return;
  }

  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      visited[i] = true;
      arr[cnt] = i;
      bt(cnt + 1);
      visited[i] = false;
    }
  }
  return;
}
