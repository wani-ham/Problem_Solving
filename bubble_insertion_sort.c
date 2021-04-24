// 버블 정렬과 삽입 정렬 비교 및 구현 코드

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 50 

int num[MAX] = {};

void rand_num() {
  srand(time(NULL));
  for(int i = 0; i < MAX; i++) {
    num[i] = rand() % (MAX+1);
  }
  return;
}

void bubble_sort() { 
  int temp;
  for(int i  = 0; i < MAX; i++) {
    for(int j = 0; j < MAX-i; j++) {
      if(num[j] > num[j+1]) {
        temp = num[j+1];
        num[j+1] = num[j];
        num[j] = temp;
      }
    }
  }
}

void insertion_sort() {
  int temp, key, j;

  for(int i = 0; i < MAX; i++) {
    key = num[i+1];
    for(j = i; j >= 0; j--) {
      if(num[j] < key) {
        break;
      }
      else {
        num[j+1] = num[j];
      }
    }
    num[j+1] = key;
  }
  return;
}

void print_result() {
  for(int i = 0; i < MAX; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
  return;
}

int main(void) {
  clock_t start, end;

  printf("<Bubble sort>\n");
  rand_num();
  printf("Not yet sorted: ");
  print_result();
  start = clock();
  bubble_sort();
  end = clock();
  printf("Sorted: ");
  print_result();
  printf("\nTime: %lf", (double)(end-start)/CLOCKS_PER_SEC);
  printf("\n\n");
  
  printf("<Insertion sort>\n");
  rand_num();
  printf("Not yet sorted: ");
  print_result();
  start = clock();
  insertion_sort();
  end = clock();
  printf("Sorted: ");
  print_result();
  printf("\nTime: %lf\n", (double)(end-start)/CLOCKS_PER_SEC);
  return 0;
}
