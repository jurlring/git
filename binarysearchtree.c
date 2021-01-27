#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#pragma warning(disable:4996)
typedef struct node {
	int key;
	struct node* lch, * rch, * parent;
}node;
void expend(node* z) {
	node* l, * r;
	l = (node*)malloc(sizeof(node));
	r = (node*)malloc(sizeof(node));
	l->lch = NULL;
	l->rch = NULL;
	l->parent = z;
	r->lch = NULL;
	r->rch = NULL;
	r->parent = z;
	z->lch = l;
	z->rch = r;
}
int external(node* a) {
	if (a->lch == NULL && a->rch == NULL)
		return 1;
	else
		return 0;
}
node* search(node* root, int k) {
	if (external(root) == 1)
		return root;
	if (k == root->key)
		return root;
	if (k < root->key)
		return search(root->lch, k);
	else
		return search(root->rch, k);
}
int find(node* root, int k) {
	node* p = search(root, k);
	if (external(p) == 1)
		return NULL;
	else
		return p->key;
}
void insert(node* root, int a) {
	node* p = search(root, a);
	if (external(p) == 0)
		return;
	p->key = a;
	expend(p);
}
void print(node* root) {
	if (root == NULL)
		return;
	else if (external(root) == 1)
		return;
	printf("%d ", root->key);
	print(root->lch);
	print(root->rch);
}
node* inorder(node* w) {
	node* y = w->rch;
	while (external(y->lch) != 1) {
		y = y->lch;
	}
	return y;
}
node* sibling(node* z) {
	node* w = z->parent;
	if (w->lch == z)
		return w->rch;
	else
		return w->lch;
}
void reduce(node* root, node* z) {
	node* zs, * w, * g;
	w = z->parent;
	zs = sibling(z);
	if (w == root) {
		if (external(root->lch) == 1 && external(root->rch) == 1) {
			root->lch = NULL;
			root->rch = NULL;
			free(root->lch);
			free(root->rch);
			return;
		}
		root = zs;
		zs->parent = NULL;
	}
	else {
		g = w->parent;
		zs->parent = g;
		if (g->lch == w)
			g->lch = zs;
		else if (g->rch == w)
			g->rch = zs;
	}
	free(z);
	free(w);
}
void remov(node* root, int k) {
	node* f = search(root, k), * z, * y;
	z = f->lch;
	if (external(z) == 0)
		z = f->rch;
	if (external(z) == 1) {
		reduce(root, z);
	}
	else {
		y = inorder(f);
		z = y->lch;
		f->key = y->key;
		reduce(root, z);
	}
}
int main() {
	int b;
	char a;
	node* root = (node*)malloc(sizeof(node));
	root->parent = NULL;
	root->lch = NULL;
	root->rch = NULL;
	while (1) {
		scanf("%c", &a);
		if (a == 'q')
			break;
		if (a == 'i') {
			scanf("%d", &b);
			insert(root, b);
			getchar();
		}
		if (a == 'p') {
			print(root);
			printf("\n");
		}
		if (a == 's') {
			scanf("%d", &b);
			if (find(root, b) == NULL)
				printf("X\n");
			else
				printf("%d\n", find(root, b));
			getchar();
		}
		if (a == 'd') {
			scanf("%d", &b);
			if (find(root, b) == NULL) {
				printf("X\n");
				continue;
			}
			else {
				printf("%d\n", find(root, b));
				remov(root, b);
			}
			getchar();
		}
	}
}