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

//Merge Sort functions

void SplitList(Node *head, Node **firstRef, Node **secRef ){

    Node *slow,*fast;

    if(head==NULL || head->next == NULL){
        *firstRef = head;
        *secRef = NULL;
    }
    else{

        slow = head;
        fast = head->next;

        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        (*firstRef)= head;
        (*secRef) = slow->next;
        slow->next = NULL;
    }
}

Node * SortedMerge(Node *first, Node *second){
    Node *result;
    if(first==NULL){
        return second;
    }
    else if(second==NULL)
    {
        return first;
    }
    else{

        if(first->data<second->data){
            result = first;
            result->next = SortedMerge(first->next,second);
        }
        else{
            result = second;
            result->next = SortedMerge(second->next,first);
        }
    }
    return result;
}

void MergeSort(Node **head) {

    if((*head)==NULL ||(*head)->next==NULL){
        return 1;
    }
    else{
        Node *front=NULL, *back=NULL;
        SplitList(*head, &front, &back);

        printLinkList(front);
        printLinkList(back);
       // return 1;

        MergeSort(&front);
        MergeSort(&back);
        *head = SortedMerge(front, back);
    }
    return 1;
}


void deleteNode(Node **node){

    if(node!=NULL){
        Node *temp = (*node)->next;
        (*node)->next = temp->next;
        *node = (*node)->next;
        free(temp);
    }
}
//Delete Alternate node from link list
void DeleteAlternateNode(Node **head){

    Node *temp;
    temp = *head;
    //    printf("temp : %d\n",(*head)->data);
    while(temp){
        printf("temp : %d\n",temp->data);
        deleteNode(&temp);
        //temp = temp->next;
    }
}

//Intersection of two link list

void insertNode (Node **head, Node *newNode){

    newNode->next = (*head);
    (*head) = newNode;
}

Node * intersectionOfList(Node *a, Node *b){

    Node dummy;
    Node *result = &dummy;
    dummy.next = NULL;

    while(a && b){

        if(a->data == b->data){
            printf("1\n");
            Node *newNode = createNode(a->data);
            insertNode((&result->next),newNode);
            result = result->next;
            a = a->next;
            b = b->next;
        }
        else if(a->data < b->data){
            a = a->next;
        }
        else if(a->data > b->data)
        {
            b = b->next;
        }
    }
    return (dummy.next);
}

//PairWise Reverse

Node * SwappingKnode(Node **head, int k){

    if((*head)==NULL || (*head)->next == NULL){
        return ;
    }
    Node *cur= *head;
    Node *prev = NULL;
    Node *temp = *head;
    (*head) = cur->next;
    Node *next;
    int count =k;
    while(count>0 && cur){
            next = cur->next;
            cur->next = prev;

            prev =cur;
            cur = next;
            count--;
    }

    printLinkList(*head);
    if(temp){
        SwappingKnode(&cur,k);
        temp->next = cur;
    }

 //   return (*head);
}

void pairWiseReverse(Node **head){

    if(!(*head) || !(*head)->next){
        return ;
    }
    Node *cur = (*head)->next;
    Node *prev = *head;

    (*head) = cur;

   while(1){

        Node * next = cur->next;
        cur->next = prev;

        if(!next || !(next->next)){
            prev->next = next;
            break;
        }
        prev->next = next->next;
        prev = next;
        cur = prev->next;
    }
}

int main()
{
    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(9);
    root->next->next->next->next->next = createNode(10);

    Node *root1 = createNode(2);
    root1->next = createNode(3);
    root1->next->next = createNode(7);
    root1->next->next->next = createNode(8);
    root1->next->next->next->next = createNode(10);

	//printLinkList(root);
    //Node * ans = intersectionOfList(root,root1);
    SwappingKnode(&root,2);
    printLinkList(root);
//	DeleteAlternateNode(&root);
	//MergeSort(&root);


    return 0;
}
