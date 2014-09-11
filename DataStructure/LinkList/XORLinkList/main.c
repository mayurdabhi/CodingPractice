#include <stdio.h>
#include <stdlib.h>

typedef struct node  Node;

struct node{

    int data;
    struct node *ptd; // xor of next and prev pointers
};

Node * XOR_Node(Node *a, Node *b){

    return (Node *)((unsigned int)a ^ (unsigned int) b);
}

int insertNode(Node **head, int k){

    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->data = k;
    newNode->ptd = XOR_Node(*head,NULL);
    //each node is inserted into front of node
    if(*head != NULL){

        (*head)->ptd = XOR_Node((*head)->ptd,NULL);
        (*head)->ptd = XOR_Node((*head)->ptd,newNode);
    }

    *head =  newNode;
}

int printLinkList(Node *head){

    Node *temp = head;
    Node *prev, *next;
//for root node prev = NULL
    prev = NULL;

    while(temp){
        printf("%d ",temp->data);
        next = XOR_Node(prev,temp->ptd);
        prev= temp;
        temp = next;
    }
    printf("\n");
}


int main()
{
    Node *root = NULL;

    insertNode(&root,3);
    insertNode(&root,5);
    insertNode(&root,7);
    insertNode(&root,8);
    insertNode(&root,9);
    insertNode(&root,13);

    printLinkList(root);
    return 0;
}
