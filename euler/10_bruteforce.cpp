#include <iostream>
#include <vector>
#define MAX 2000000

using namespace std;

int main(void) {
  vector<int> prime;
  long long int result = 0;
  int num = 3;

  result += 2;
  prime.push_back(2);

  while(num <= MAX) {
    bool isPrime = true;
    for(int i = 0; i < prime.size(); i++) {
      if(num % prime[i] == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) {
      prime.push_back(num);
      result += num;
    }
    num++;
  }
  printf("%lld\n", result);
  return 0;
}
