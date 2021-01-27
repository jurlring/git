#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996);
int main() {
	int m, n, k, * x, v, q, h;
	char a;
	scanf("%d%d%d", &m, &n, &q);
	getchar();
	x = (int*)malloc(sizeof(int) * m);
	for (int i = 0; i < m; i++)
		x[i] = 0;
	while (1) {
		scanf("%c", &a);
		getchar();
		if (a == 'e') {
			for (int i = 0; i < m; i++)
				printf(" %d", x[i]);
			break;
		}
		if (a == 'p') {
			for (int i = 0; i < m; i++)
				printf(" %d", x[i]);
			printf("\n");
			continue;
		}
		scanf("%d", &k);
		getchar();
		v = k % m;
		h = q - (k % q);
		if (a == 'i') {
			if (x[v] == 0) {
				x[v] = k;
				printf("%d\n", v);
			}
			else {
				while (x[v] != 0) {
					printf("C");
					v += h;
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
				v += h;
				v = v % m;
			}
			if (x[v] == 0)
				printf("-1\n");
		}
	}
}