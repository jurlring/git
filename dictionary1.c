#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int findelement(int x[], int k, int l, int r) {
	int mid;
	if (l > r) {
		if ((k - x[r]) < (x[l] - k))
			return r;
		else
			return -1;
	}
	else if (l == r) {
		if (x[l] > k)
			return l - 1;
		else
			return l;
	}
	mid = (r + l) / 2;
	if (x[mid] == k)
		return mid;
	else if (k < x[mid]) {
		return findelement(x, k, l, mid - 1);
	}
	else {
		return findelement(x, k, mid + 1, r);
	}
}
int main() {
	int* x, n, k, p = 0, mid;
	scanf("%d%d", &n, &k);
	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	printf("%d", findelement(x, k, 0, n - 1));
	free(x);
}