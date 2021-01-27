#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996);
typedef struct hash {
	int i;
	struct hash* next;
}hash;
void addd(hash* p, int k) {
	hash* new = (hash*)malloc(sizeof(hash));
	new->i = k;
	new->next = p->next;
	p->next = new;
}
int search(hash* h, int k) {
	hash* p = h;
	int a = 1;
	while (p->next != NULL) {
		p = p->next;
		if (p->i == k)
			return a;
		a++;
	}
	return 0;
}
void print(hash* h, int m) {
	hash* p;
	for (int i = 0; i < m; i++) {
		p = &h[i];
		while (p->next != NULL) {
			p = p->next;
			printf(" %d", p->i);
		}
	}
}
int del(hash* h, int k) {
	hash* p = h, * q;
	int a = 0;
	while (p->next != NULL) {
		a++;
		if (p->next->i == k) {
			while (p->next->next != NULL) {
				p->next->i = p->next->next->i;
				p = p->next;
			}
			q = p->next;
			p->next = NULL;
			free(q);
			return a;
		}
		p = p->next;
	}
	return 0;
}
int main() {
	int m, k;
	char a;
	hash* h;
	scanf("%d", &m);
	getchar();
	h = (hash*)malloc(sizeof(hash) * m);
	for (int i = 0; i < m; i++) {
		(h + i)->i = i;
		(h + i)->next = NULL;
	}
	while (1) {
		scanf("%c", &a);
		if (a == 'e')
			return 0;
		if (a == 'i') {
			scanf("%d", &k);
			getchar();
			addd(&h[k % m], k);
		}
		if (a == 's') {
			scanf("%d", &k);
			getchar();
			printf("%d\n", search(&h[k % m], k));
		}
		if (a == 'd') {
			scanf("%d", &k);
			getchar();
			printf("%d\n", del(&h[k % m], k));
		}
		if (a == 'p') {
			print(h, m);
			printf("\n");
		}
	}
}