#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int main() {
	int a, b, n, m;
	char k;
	scanf("%d%d%d", &a, &b, &n);
	getchar();
	for (int i = 0; i < n; i++) {
		scanf("%c", &k);
		m = (a + b) / 2;
		if (k == 'Y') {
			a = m + 1;
		}
		else if (k == 'N') {
			b = m;
		}
	}
	printf("%d", a);
}