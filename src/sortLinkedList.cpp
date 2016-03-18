/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * sortLinkedList(struct node *head) {
	struct node*temp, *temp1, *min_address;
	int store, min;
	if (head == NULL)
		return NULL;
	else if (head->next == NULL)
		return head;
	else
	{
		temp1 = head;
		while (temp1 != NULL)
		{
			min = temp1->num;
			min_address = temp1;
			temp = temp1->next;
			while (temp != NULL)
			{
				if (temp->num<min)
				{
					min = temp->num;
					min_address = temp;
				}
				temp = temp->next;
			}
			store = temp1->num;
			temp1->num = min;
			min_address->num = store;
			temp1 = temp1->next;
		}
		return head;
	}
}
