#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996);
int main() {
	int m, n, k, * x, v;
	char a;
	scanf("%d%d", &m, &n);
	getchar();
	x = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		x[i] = 0;
	while (1) {
		scanf("%c", &a);
		getchar();
		if (a == 'e')
			break;
		scanf("%d", &k);
		getchar();
		v = k % m;
		if (a == 'i') {
			if (x[v] == 0) {
				x[v] = k;
				printf("%d\n", v);
			}
			else {
				while (x[v] != 0) {
					printf("C");
					v++;
					v = v % m;
				}
				x[v] = k;
				printf("%d\n", v);
			}
		}
		if (a == 's') {
			while (x[v] != 0) {
				if (x[v] == k) {
					printf("%d %d\n", v, k);
					break;
				}
				v++;
				v = v % m;
			}
			if (x[v] == 0)
				printf("-1\n");
		}
	}
}