#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int findpivot(int l, int r) {
	return rand() % (r - l) + l;
}
int inplacepartition(int L[], int l, int r, int k) {
	int i, j, p;
	p = L[k];
	swap(&L[k], &L[r]);
	i = l;
	j = r - 1;
	while (i <= j) {
		while (i <= j && p >= L[i])
			i++;
		while (i <= j && p <= L[j])
			j--;
		if (i < j)
			swap(&L[i], &L[j]);
	}
	swap(&L[i], &L[r]);
	return i;
}
void inplacesort(int L[], int l, int r) {
	int k, a;
	if (l >= r)
		return;
	k = findpivot(l, r);
	a = inplacepartition(L, l, r, k);
	inplacesort(L, l, a - 1);
	inplacesort(L, a + 1, r);
}
int main() {
	int n, * L = NULL, * p;
	scanf("%d", &n);
	L = (int*)malloc(n * sizeof(int));
	for (p = L; p < L + n; p++)
		scanf("%d", p);
	inplacesort(L, 0, n - 1);
	for (p = L; p < L + n; p++)
		printf(" %d", *p);
	free(L);
	return 0;
}