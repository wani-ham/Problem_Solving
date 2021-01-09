#include <cstdio>
#define MAX 2000000

int main(void) {
  bool num[MAX+1]; // if true: not prime
  long long int result = 0;

  for(int i = 1; i < MAX+1; i++) {
    num[i] = false;
  }

  for(int i = 2; i < MAX+1; i++) {
    if(num[i] == true) continue;
    else {
      for(int j = 2*i; j < MAX+1; j += i) {
        num[j] = true;
      }
    }
  }

  for(int i = 2; i < MAX + 1; i++) {
    if(num[i] == false) result += i;
  }

  printf("%lld\n", result);
  return 0;
}
