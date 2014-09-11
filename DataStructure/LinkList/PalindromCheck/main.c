#include <stdio.h>
#include <stdlib.h>

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

int reverseLinkList(Node **head){

    Node *prev, *current, *next;
    prev = next = NULL;
    current = *head;

    while(current){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    (*head) = prev;
}

int compareLinkList(Node *head1, Node *head2){

    while(head1 && head2){

        if(head1->data== head2->data){
            head1= head1->next;
            head2 = head2->next;
        }
        else{
            return 0;
        }
    }
    return 1;
}

int checkPalindrom(Node *head){

    Node *slow = head, *fast = head, *prev = head;
    Node *mid;
    mid = NULL;
    if(head){

        //Find mid Point
        while(slow && fast && fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }

        //Fast is null then list is even
        // so no mid point
        if(fast != NULL)
        {
            mid = slow;
            slow = slow->next;
            // prev->next = NULL;
        }
        Node *second = slow;
        prev->next = NULL;

        //Reverse the list
        printLinkList(second);
        reverseLinkList(&second);
        printLinkList(second);

        int res = compareLinkList(head,second);

        reverseLinkList(&second);
        printLinkList(second);
        if(mid!=NULL){
            prev->next= mid;
            mid->next = second;
        }
        else{
            prev->next = second;
        }
        printf("%d\n",res);
        return res;
    }

}

//Both solution is working O(n)
int insertInSortedLinkList(Node **head, Node *newNode){


    Node **current = head;

    while((*current)!=NULL && (*current)->data < newNode->data){
            printf("%d\n",(*current)->data);
        current = &((*current)->next);
    }

    newNode->next = (*current);
    (*current) = newNode;


    /*

    Node *temp = *head;
    Node *prev = NULL;
    while(temp && temp->data<newNode->data){
        prev = temp;
        temp = temp->next;

    }

    if(prev)
    {
        newNode->next = temp;
        prev->next = newNode;
    }
    else{
        (*head) = newNode;
    }
    */


}

int main()
{

    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(9);
    root->next->next->next->next->next = createNode(10);
	printLinkList(root);
	Node *root1 = root;
	insertInSortedLinkList(&root1,createNode(6));
	insertInSortedLinkList(&root1,createNode(7));
	insertInSortedLinkList(&root1,createNode(8));
	printLinkList(root1);
	/*
	if(checkPalindrom(root)){
        printf("LinkList is palindrom\n");
	}
	else{
        printf("LinkList is not a palindrom\n");
	}
	*/
    return 0;
}
