#include <stdio.h>

int min_n = 0, min_s = 0, min_w = 0, min_e = 0;
char dir = 'e';
int n, arrow, len, pos_x = 0, pos_y = 0, ans[10001], tmp_arrow;

void change_dir() {
	if(dir == 'n') {
			if(arrow == 1) dir = 'w';
			else dir = 'e';
	}
		
	else if(dir == 'e') {
		if(arrow == 1) dir = 'n';
		else dir = 's';
	}
		
	else if(dir == 'w') {
		if(arrow == 1) dir = 's';
		else dir = 'n';
	}
		
	else {
		if(arrow == 1) dir = 'e';
		else dir = 'w';
	}
	return;
}

int main(void) {
	scanf("%d", &n);
	
	if(n == 1) {
		printf("1");
		return 0;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d %d", &len, &tmp_arrow);
		if(i == 0) {
			min_e = 1;
			pos_x = 1;
			ans[i] = 1;
			arrow = tmp_arrow;
			continue;
		}
		change_dir();
		if(dir == 'n') {
			ans[i] = min_n - pos_y + 1;
			pos_y += min_n - pos_y + 1;
			min_n = pos_y;
		}
		
		else if(dir == 'e') {
				ans[i] = min_e - pos_x + 1;
				pos_x += min_e - pos_x + 1;
				min_e = pos_x;
		}
		
		else if(dir == 'w') {
				ans[i] = pos_x - min_w + 1;
				pos_x -= pos_x - min_w + 1;
				min_w = pos_x;
		}
		
		else {
				ans[i] = pos_y - min_s + 1;
				pos_y -= pos_y - min_s + 1;
				min_s = pos_y;
		}
		arrow = tmp_arrow;
	}
	
	for(int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
  
	return 0;
}
