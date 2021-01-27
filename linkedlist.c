#include <stdio.h>#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char elem;
	struct node* prev;
	struct node* next;
}node;
node* insert(node* p, char a) {
	node* q = (node*)malloc(sizeof(node));
	q->elem = a;
	q->prev = p;
	q->next = p->next;
	(p->next)->prev = q;
	p->next = q;
	return q;
}

void ad(node* p, int r, char a) {
	for (int i = 1; i < r; i++) {
		if (p->elem == 1) {
			printf("invalid position\n");
			return;
		}p = p->next;
	}
	if (p->elem == 1) {
		printf("invalid position\n");
		return;
	}
	else insert(p, a);
}
void del(node* p, int r) {
	node* q;
	q = p;
	for (int i = 0; i < r; i++) {
		if (q->elem == 1) {
			printf("invalid position\n");
			return;
		}q = q->next;
	}
	if (q->elem == 1) {
		printf("invalid position\n");
		return;
	}
	else {
		(q->prev)->next = q->next;
		(q->next)->prev = q->prev;
		free(q);
	}
}
char get(node* p, int r) {
	for (int i = 0; i < r; i++) {
		if (p->elem == 1) {
			printf("invalid position\n");
			return -1;
		}p = p->next;
	}
	if (p->elem == 1) {
		printf("invalid position\n");
		return -1;
	}
	else {
		return p->elem;
	}
}
void printt(node* p) {
	while (p->elem != 1) {
		p = p->next;
		if (p->elem == 1) break;
		printf("%c", p->elem);
	}printf("\n");
}

int main() {
	int N, a;
	char n, p, b;
	node* trail = (node*)malloc(sizeof(node));
	node* head = (node*)malloc(sizeof(node));
	trail->elem = 1;
	head->elem = NULL;
	head->prev = NULL;
	head->next = trail;
	trail->next = NULL;
	trail->prev = head;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		getchar();
		scanf("%c", &n);
		if (n == 'P') {
			printt(head);
		}
		else if (n == 'D') {
			getchar();
			scanf("%d", &a);
			del(head, a);
		}
		else if (n == 'G') {
			getchar();
			scanf("%d", &a);
			b = get(head, a);
			if (b != -1) printf("%c\n", b);
		}
		else if (n == 'A') {
			getchar();
			scanf("%d", &a);
			getchar();
			scanf("%c", &p);
			ad(head, a, p);
		}
	}
	free(head);
	free(trail);
	return 0;
}