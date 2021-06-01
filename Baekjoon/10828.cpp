// Stack DIY

#include <stdio.h>
#include <string.h>
#define MAX 1000

void push(int x, int *arr, int *index) {
  arr[++(*index)] = x;
  return;
}

void pop(int *arr, int *index) {
  if(*index == 0) printf("-1\n");
  else {
    printf("%d\n", arr[(*index)]);
    (*index)--;
  }
  return;
}

void top(int *arr, int index) {
  if(index == 0) printf("-1\n");
  else printf("%d\n", arr[index]);
  return;
}

int main(void) {
  int arr[MAX+1];
  int N, x;
  int index = 0;
  char s[10];
  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%s", s);
    if(strcmp(s, "push") == 0) {
      scanf("%d", &x);
      push(x, arr, &index);
    }
    else if(strcmp(s, "pop") == 0) pop(arr, &index);
    else if(strcmp(s, "size") == 0) printf("%d\n", index);
    else if(strcmp(s, "empty") == 0) {
      if(index == 0) printf("1\n");
      else printf("0\n");
    }
    else top(arr, index);
  }
  return 0;
}
