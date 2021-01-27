#include <stdio.h>
#include <stdlib.h>
typedef struct tree {
	int num;
	struct tree* left;
	struct tree* right;
}tree;
tree* produce(int a) {
	tree* new = (tree*)malloc(sizeof(tree));
	new->num = a;
	new->left = NULL;
	new->right = NULL;
	return new;
}
tree* find(tree* root, int a) {
	tree* f;
	if (!root) return NULL;
	if (a == root->num) return root;
	f = find(root->left, a);
	if (f) return f;
	return find(root->right, a);
}
tree* linked(tree* root, int a, int b, int c) {
	tree* parent = find(root, a);
	if (b != 0) parent->left = produce(b);
	if (c != 0) parent->right = produce(c);
}
int main() {
	int n, s, a, b, c, j;
	char x[100];
	tree* root, * P;
	scanf("%d", &n);
	scanf("%d%d%d", &a, &b, &c);
	root = produce(a);
	root->left = produce(b);
	root->right = produce(c);
	for (int i = 1; i < n; i++) {
		scanf("%d%d%d", &a, &b, &c);
		linked(root, a, b, c);
	}
	scanf("%d", &s);
	getchar();
	for (int i = 0; i < s; i++) {
		P = root;
		for (j = 0; ; j++) {
			scanf("%c", &x[j]);
			if (x[j] == '\n') break;
		}
		printf(" %d", P->num);
		for (int k = 0; k < j; k++) {
			if (x[k] == 'R') P = P->right;
			if (x[k] == 'L') P = P->left;
			printf(" %d", P->num);
		}printf("\n");
	}
}