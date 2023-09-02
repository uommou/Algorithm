#include <stdio.h>

int main() {
	int numarray[6] = { 0 };
	int num;
	int end = 0;
	while (true) {
		int yes = 1;
		numarray[7] = { 0 };
		scanf("%d", &num);
		if (num == 0) {
			break;
		}
		for (int i = 0; num > 0; i++) {
			numarray[i] = num % 10;
			num /= 10;
			if (num == 0) {
				end = i + 1;
			}
		}
		for(int i = 0; i < end/2 ; i++) {
			if (numarray[i] != numarray[end - i - 1]) {
				printf("no\n");
				yes = 0;
				break;
			}
		}
		if (yes == 1) printf("yes\n");
	}
}
