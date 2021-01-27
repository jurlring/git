#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
void uph(int x[], int i) {
	int a;
	a = i;
	if (a <= 1)
		return;
	if (a > 1) {
		if (x[a] > x[a / 2]) {
			swap(&x[a], &x[a / 2]);
			uph(x, a / 2);
		}
	}
}
void dop(int x[], int p, int i) {//i는 전체 노드 개수
	int a, q;
	a = p;
	if (a == i || a * 2 > i)//왼쪽 자식 번호가 전체 노드수 보다 크면
		return;
	q = a * 2;
	if (a * 2 + 1 <= i && x[q] < x[a * 2 + 1]) {
		q = a * 2 + 1;
	}
	if (x[q] > x[p]) {
		swap(&x[q], &x[p]);
		dop(x, q, i);
	}
}
int main() {
	int x[100], i = 1, j, n, c;
	char a;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &x[i]);
	for (i = n / 2; i >= 1; i--) {
		dop(x, i, n);
	}
	for (i = n; i >= 2; i--) {
		swap(&x[i], &x[1]);
		dop(x, 1, i - 1);
	}
	for (i = 1; i <= n; i++)
		printf(" %d", x[i]);
}