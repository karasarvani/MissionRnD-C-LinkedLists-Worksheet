/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int digit1;
	int digit2;
	struct node *next;
};
int power(int length)
{
	int i, power_10 = 1;
	for (i = 1; i<length; i++)
	{
		power_10 = power_10 * 10;
	}
	return power_10;
}


int convert_sll_2digit_to_int(struct node *head){
	int length = 0, power_10, result = 0;
	struct node *temp;
	temp = head;
	while (temp != NULL)
	{

		length++;
		temp = temp->next;
	}
	temp = head;
	length = length * 2;
	while (temp != NULL)
	{
		power_10 = power(length);
		result = result + (temp->digit1*power_10);
		length--;
		power_10 = power(length);
		result = result + (temp->digit2*power_10);
		length--;
		temp = temp->next;
	}
	return result;
}
