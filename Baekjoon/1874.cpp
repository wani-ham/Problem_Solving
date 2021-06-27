#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
	int n, tmp, flag = 1;
  stack<int> nums; // number set
  vector<char> op; // operation
  int max = 0;

  ios_base::sync_with_stdio(false);
  cin >> n;
  cin.ignore(); 
  
  for(int i = 0; i < n; i++) {
    cin >> tmp;
    cin.ignore();
    if(max < tmp) {
      for(int j = max + 1; j <= tmp; j++) {
        nums.push(j);
        op.push_back('+');
        max = tmp;
      }
      nums.pop();
      op.push_back('-');
    }
    else {
      if(!nums.empty() && tmp == nums.top()) {
        op.push_back('-');
        nums.pop();
      }
      else {
        cout << "NO";
        flag = 0;
        break;
      }
    }
  }
  if(flag) {
    for(int i = 0; i < op.size(); i++) cout << op[i] << '\n';
  }
	return 0;
}
