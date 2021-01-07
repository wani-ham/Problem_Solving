#include <cstdio>
#define NTH 10001

int main() {
  int prime[NTH+1]; // list of prime numbers
  bool isPrime = true;
  int num = 3;
  int size = 1; // size of prime array
  prime[0] = 2; // initialize prime list

  while(size < NTH) {
    isPrime = true;
    for(int i = 0; i < size; i++) {
      if(num % prime[i] == 0) {
        isPrime = false;
        break;
      }
    }
    if(isPrime) { // if num is prime number
      prime[size] = num; // append it to the list
      size++; // increase size
    }
    num++;
  }
  printf("The %dth(st) prime number is %d\n", NTH, prime[size-1]);
  return 0;
}
