#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
	int t;
  ios_base::sync_with_stdio(false);
  cin >> t;
  cin.ignore(); // cin cannot get '\n'. have to use ignore() to get rid of '\n'

  for(int i = t; i > 0; i--) {
    stack<char> p;
    string str;
    getline(cin, str);
    
    for(int i = 0; i < str.size(); i++) {
      if(str[i] == '(') {
        p.push(str[i]);
      }
      else {
        if(p.empty()) {
          p.push(str[i]);
          break;
        }
        else p.pop();
      }
    }
    if(p.empty()) cout << "YES" << '\n';
    else cout << "NO" << '\n';
  } 
	return 0;
}
