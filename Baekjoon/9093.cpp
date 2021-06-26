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
    string str;
    getline(cin, str);
    str += '\n';
    stack<char> word;

    for(int j = 0; j < str.size(); j++) {
      if(str[j] == ' ' || str[j] == '\n') {
         while(!word.empty()) {
           cout << word.top();
           word.pop();
         }
         cout << str[j];
      }
      else {
        word.push(str[j]);
      }
    }

  } 
	return 0;
}
