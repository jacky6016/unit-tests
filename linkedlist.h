#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct List_node {
	int value;
	struct List_node *next;
} List, *pList;

extern List *swap(List *head, List *node_1, List *node_2);
#endif
