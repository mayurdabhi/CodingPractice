#include <stdio.h>
#include <stdlib.h>
#include "LinkList.c"
/*
	Given only a pointer to a node to be deleted in a singly linked list.
	Fast solution is to copy the data from the next node to the node to
	be deleted and delete the next node. Something like following.
*/

typedef struct node Node ;

struct node{

    int data;
    struct node *next;
};

int printLinkList(Node *head){

    Node *temp = head;

    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

Node * createNode(int data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int deleteNode(Node **ptr){

	if((*ptr)==NULL){
		printf("Node is Null\n");
		return 0;
	}
	else if((*ptr)->next == NULL){

		Node *temp1 = NULL;
		Node *temp = (*ptr);
		(*ptr) = temp1;
		free(temp);

		(*ptr)
		 = NULL;
		printf("%d %d\n",temp->data, temp->next);
		return 1;
	}
	else{

		Node *temp = (*ptr)->next;
		(*ptr)->data = temp->data;
		(*ptr)->next = temp->next;
		free(temp);
		return 1;
	}

}

int main(){
	Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(10);
	printLinkList(root);
	deleteNode(&(root->next->next));
	printLinkList(root);
	deleteNode(&(root->next->next->next));
	printLinkList(root);

	return 0;
}
