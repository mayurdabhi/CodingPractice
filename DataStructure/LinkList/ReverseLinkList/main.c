#include <stdio.h>
#include <stdlib.h>

typedef struct node Node ;

struct node{

    int data;
    struct node *next;
};

Node * reverseKListBlock(Node *root,int k){


}

Node* ReverseLinkList(Node *root){

    if(!root){
        return NULL;
    }

    if(!root->next){
        return root;
    }

    Node *temp =root->next;

    root->next = NULL;

    Node *reverseList = ReverseLinkList(temp);

    temp->next = root;
 //   printLinkList(temp);
   // printLinkList(reverseList);
    return reverseList;
}

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

int main()
{
    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    ReverseLinkList(root);
    return 0;
}
