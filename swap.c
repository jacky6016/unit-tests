#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

List *swap(List *head, List *node_1, List *node_2)
{
	if (!head && (!node_1 || !node_2 || node_1 == node_2))
		return head;

	List *_head = head;
	List *pre_node_1 = NULL ,*pre_node_2 = NULL ,*tmp_node = NULL;

	// find pre-nodes
	for(; head && head->next;head = head->next)
	{
		if (head->next == node_1)  
			pre_node_1 = head;
		if (head->next == node_2) 
			pre_node_2 = head;
	}

	head = _head;

	if((!node_1 && !node_2) || (!node_1 && head != node_1) || (!node_2 && head != node_2))
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
