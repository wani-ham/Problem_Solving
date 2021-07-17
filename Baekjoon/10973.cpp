#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    vector<int> v;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    if(prev_permutation(v.begin(), v.end()) == false) cout << "-1";
    else {
        for(int i = 0; i < n; i++) cout << v[i] << " ";
    }
    return 0;
}
