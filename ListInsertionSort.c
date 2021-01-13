#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10

typedef struct node* link;
struct node { int item; link next; };

void printList(link x)
{
	for (; x != NULL; x = x->next)
	{
		printf("%2d", x->item);
		printf(" -> ");
	}
	printf("NULL\n");
}

int main()
{
	srand(time(0));

	struct node heada, headb;
	link t, u, x, a = &heada, b;
	int i;
	
	a->next = NULL;
	for (i = 0, t = a; i < N; ++i)
	{
		t->next = malloc(sizeof(*t));
		t = t->next; t->next = NULL;
		t->item = rand() % 100;
	}

	printf("The unsorted list is: ");
	printList(a->next);

	b = &headb; b->next = NULL;

	for (t = a->next; t != NULL; t = u)
	{
		u = t->next;
		for (x = b; x->next != NULL; x = x->next)
			if (x->next->item > t->item) break;
		t->next = x->next; x->next = t;
	}

	printf("  The sorted list is: ");
	printList(b->next);

	return 0;
}