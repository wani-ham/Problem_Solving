#include <stdio.h>

bool check_num[1001][1001] = {0};
int a[1000] = {0};

void init() {
	for(int i = 2; i < 1001; i++) {
		for(int j = 1; j < 1001; j++) {
			check_num[i][j] = false;
		}
	}
}

void check(int n) {
	init();
	a[0] = 1;
	a[1] = 1;
	for(int i = 2; i <= n; i++) {
		for(int k = 1; k <= i/2; k++) {
			check_num[i][2*a[i-k] - a[i-2*k]] = true;
		}
		
		for(int j = 1; j < 1001; j++) {
			if(check_num[i][j] == false) {
				a[i] = j;
				break;
			}
		}
	}
	
	return;
}

int main(void) {
	int n;
	scanf("%d", &n);
	check(n);
	printf("%d", a[n]);
	return 0;
}
