#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string candy[51];
int n;

int check();

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for(int i = 0; i < n; i++) cin >> candy[i];

  int result = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n-1; j++) {
      swap(candy[i][j], candy[i][j + 1]);
      result = max(result, check());
      swap(candy[i][j], candy[i][j + 1]);
                      
      swap(candy[j][i], candy[j + 1][i]);
      result = max(result, check());
      swap(candy[j][i], candy[j + 1][i]);
    }
  }

  cout << result;

  return 0;
}

int check() {
  int result = 1;

  for(int i = 0; i < n; i++) {
    int temp = 1;
    for(int j = 1; j < n; j++) {
      if(candy[i][j-1] == candy[i][j]) temp++;
      else {
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }

  for(int i = 0; i < n; i++) {
    int temp = 1;
    for(int j = 0; j < n-1; j++) {
      if(candy[j][i] == candy[j+1][i]) temp++;
      else {
        result = max(result, temp);
        temp = 1;
      }
    }
    result = max(result, temp);
  }

  return result;
}
