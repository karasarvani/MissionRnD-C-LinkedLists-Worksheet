/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
struct node * removeEveryKthNode(struct node *head, int K) {
	struct node*temp, *prev;
	int i, length = 0;
	temp = head;
	while (temp != NULL)
	{
		length++;
		temp = temp->next;
	}
	if (K == 1 || K <= 0)
		return NULL;
	if (K>length)
		return head;
	temp = head;
	if (head == NULL)
		return NULL;
	while (temp != NULL)
	{
		for (i = 1; i<K; i++)
		{
			prev = temp;
			temp = temp->next;
		}
		if (temp == NULL)
			break;
		prev->next = temp->next;
		temp->next = NULL;
		temp = prev->next;
	}
	return head;
}
