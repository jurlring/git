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
	if (a * 2 > i)//왼쪽 자식 번호가 전체 노드수 보다 크면
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
	int x[100], i = 1, j, n;
	char a;
	while (1) {
		scanf("%c", &a);
		if (a == 'i') {
			scanf("%d", &n);
			x[i++] = n;
			uph(x, i - 1);
			printf("0\n");
			getchar();
		}
		else if (a == 'd') {
			printf("%d\n", x[1]);
			swap(&x[1], &x[--i]);
			dop(x, 1, i - 1);
			getchar();
		}
		else if (a == 'p') {
			for (j = 1; j < i; j++)
				printf(" %d", x[j]);
			printf("\n");
			getchar();
		}
		else if (a == 'q')
			break;
	}
}