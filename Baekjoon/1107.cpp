#include <iostream>
#include <algorithm>
#include <string>
#define MAX 1000000

using namespace std;

int digit(int x);
bool check(int x);

int button[11] = {0,};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, t, tmp, tmp_ans, ans = MAX;
  bool checked = false;
  
  cin >> n;
  cin >> t;

  for(int i = 0; i < t; i++) {
    cin >> tmp;
    button[tmp] = 1; // if 1 => jammed
  }

  for(int i = 0; i < MAX; i++) {
    if(!check(i)) {
      checked = true;
      if(abs(n-100) < digit(i) + abs(n-i)) tmp_ans = abs(n-100);
      else tmp_ans = digit(i) + abs(n-i);
      ans = min(tmp_ans, ans);  
    }
  }

  if(!checked) ans = abs(n-100);

  cout << ans;
  return 0;
}

int digit(int x) {
  int digits = 0;
  if(x == 0) return 1;
  while(x != 0) {
    x /= 10;
    digits++;
  }
  return digits;
}

bool check(int x) {
  int tmp;
  bool flag = false;
  if(x == 0 && button[0] == 1) return true; 
  while(x != 0) {
    tmp = x % 10;
    x /= 10;
    if(button[tmp] == 1) {
      flag = true;
      break;
    }
  }
  return flag;
}
