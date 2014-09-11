#include <stdio.h>
#include <stdlib.h>

typedef struct node Node ;

struct node{
    int data;
    struct node *next;
};

int printLinkList(Node *head){

    while(head){
        printf("%d ",head->data);
        head= head->next;
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

int InsertIntoLinkList(Node **head, Node *temp){

	if((*head) == NULL){
		(*head) = temp;
		(*head)->next = NULL;
		return 0;
	}
	else{
		temp->next  = *head;
		(*head) = temp;
	}
	//printLinkList(*head);
	return 1;
}

int DivideListEvenOdd(Node **head){

	Node *even, *odd, *temp, *temp1;
    even = NULL;
    odd = NULL;
	temp = *head;

	while(temp){
        temp1 = temp;
        temp = temp->next;
       // printf("%u\n",temp);
       // printf("%d %d\n",temp->data, temp1->data);
		if(temp1->data%2 ==0){
			InsertIntoLinkList(&even,temp1);
		}
		else{
			InsertIntoLinkList(&odd,temp1);
		}
		//printf("Done\n");

	}
   // printf("Done\n");
	temp = even;
       //printf("%d \n",temp->data );
	if(temp==NULL){
        *head = odd;
		return 0;
	}

	while(temp->next){
      //  printf("%d \n",temp->data );
		temp = temp->next;
	}

    //printf("appendign list\n");
	temp->next = odd;
	//printf("printing list\n");
	printLinkList(even);
	*head = even;
	return 1;
}

int main(){

    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(9);
    root->next->next->next->next->next = createNode(10);
    root->next->next->next->next->next->next = createNode(11);
    root->next->next->next->next->next->next->next = createNode(0);
    printLinkList(root);
    DivideListEvenOdd(&root);
    printLinkList(root);
    return 0;
}
