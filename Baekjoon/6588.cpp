// Add cin.tie(NULL) and ios_base::sync_with_stdio(false) for faster i/o

#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000000

using namespace std;

void e_sieve(int *sieve) {
  sieve[1] = 1;
  for(int i = 2; i < sqrt(MAX); i++) {
    for(int j = i*2; j < MAX+1; j+=i) {
      if(sieve[j] == 0) sieve[j] = 1;
    }
  }
  return; 
}

void push_prime(vector<int> &prime, int *sieve) {
  for(int i = 1; i < MAX+1; i++) {
    if(sieve[i] == 0) prime.push_back(i);
  }
  return;
}

int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  vector<int> prime;
  int sieve[MAX+1] = {0,};
  int n;
  bool flag = true;
  e_sieve(sieve);
  push_prime(prime, sieve);

  while(1) {
    cin >> n;
    cin.ignore();
    if(n == 0) break;

    flag = true;
    for(int i = 0; i < prime.size(); i++) {
      if(sieve[n - prime[i]] == 0) {
        cout << n << " = " << prime[i] << " + " << n - prime[i] << '\n';
        flag = false;
        break;
      }
    }
    if(flag) {
      cout << "Goldbach's conjecture is wrong." << '\n';
      break;
    }
  }
  return 0;
}
