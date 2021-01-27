#include <stdio.h>
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void downheap(int H[], int n, int i) {
	int greater = 2 * i;
	if (i * 2 > n) return;
	if (2 * i + 1 <= n) {
		if (H[2 * i + 1] > H[greater])
			greater = 2 * i + 1;
	}
	if (H[i] >= H[greater]) return;
	swap(&H[i], &H[greater]);
	downheap(H, n, greater);
}

void buildheap(int H[], int n) {
	for (int i = n / 2; i > 0; i--) {
		downheap(H, n, i);
	}
}
void rbuildheap(int H[], int n, int i) {
	if (i > n) return;
	rbuildheap(H, n, 2 * i);
	rbuildheap(H, n, 2 * i + 1);
	downheap(H, n, i);
}
void printt(int H[], int n) {
	for (int i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}printf("\n");
}
int main() {
	int a, n, H[100] = { 0 };
	scanf("%d", &a);
	n = a;
	for (int i = 1; i <= a; i++) {
		scanf("%d", &H[i]);
	}
	buildheap(H, n);
	printt(H, n);
	return 0;
}