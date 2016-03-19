#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H

typedef struct List_node {
	int value;
	struct List_node *next;
} List, *pList;

#endif
