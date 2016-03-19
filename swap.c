#include <stdio.h>
#include <stdlib.h>

typedef struct List_node {
    int value;
    struct List_node *next;
} List_node;

typedef struct List_node List;

List *swap(List *head, List *node_1, List *node_2)
{
    if (!head &&
        ((!node_1) || (!node_2) ||
        (node_1 == node_2)))
        return head;

    List *_head = head;
    List *pre_node_1 = NULL ,*pre_node_2 = NULL ,*tmp_node = NULL;
	int num_nodes_in_list = 0;

	// find pre-nodes
	for(; head && head->next;head = head->next)
	{
        if (head->next == node_1) { 
            pre_node_1 = head;
        	num_nodes_in_list = num_nodes_in_list + 1;
		}
        if (head->next == node_2) {
            pre_node_2 = head;
        	num_nodes_in_list = num_nodes_in_list + 1;
		}
	}

    head = _head;

    if (head == node_1) {
        num_nodes_in_list = num_nodes_in_list + 1;
    }

    if (head == node_2) {
        num_nodes_in_list = num_nodes_in_list + 1;
    }

	if( num_nodes_in_list != 2)
			return head;


	if (pre_node_1 == NULL) // node_1 is the head
			head = node_2;		
	else
			pre_node_1->next = node_2;
	
	if (pre_node_2 == NULL) // node_2 is the head
		head = node_1;
	else
		pre_node_2->next = node_1;
   

	tmp_node = node_2->next;
	
	if (node_1->next == node_2) // node_2 is behind node_1
		node_2->next = node_1;
	else
		node_2->next = node_1->next;
	if (node_2->next == node_1) // node_1 is behind node_2
    		node_1->next = node_2;
	else
		node_1->next = tmp_node;


	return head;
}
