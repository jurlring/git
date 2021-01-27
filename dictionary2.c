#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
int drx(int* x, int l, int r, int k) {
	int mid, n = r + 1;
	while (l < r) {
		mid = (l + r) / 2;
		if (k == x[mid])
			return mid;
		else if (k > x[mid])
			l = mid + 1;
		else
			r = mid - 1;
	}
	if (l == r) {
		if (x[l] >= k)
			return l;
		else {
			if (l + 1 >= n)
				return n;
			else
				return l + 1;
		}
	}
	else if (l > r) {
		return l;
	}
}
int main() {
	int n, k, * x;
	scanf("%d%d", &n, &k);
	x = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	printf("%d", drx(x, 0, n - 1, k));
}