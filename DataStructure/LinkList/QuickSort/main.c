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

Node * getEnd(Node *head){

    while(head && head->next){
        head= head->next;
    }
    return head;
}

Node * Partition(Node *head, Node *end, Node **hStart, Node **hEnd){

    Node *pivot, *cur, *tail,*prev;

    pivot = end;
    prev = NULL;
    cur = head;
    tail = pivot;

    while(cur!=pivot){

        if(cur->data<pivot->data){

            if((*hStart)==NULL){
                (*hStart) = cur;
            }

            prev = cur;
            cur = cur->next;
        }
        else{

            if(prev){
                prev->next = cur->next;
            }
            Node *temp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = tail->next;
            cur = temp;
        }
    }

    if((*hStart)==NULL){
        (*hStart) = pivot;
    }
    (*hEnd) = tail;
    printf("Inside partition\n");
    printLinkList(*hStart);
    return pivot;
}


Node *RecursiveQuickSort(Node *head, Node *end ){

    if(head==NULL || head == end){
        return head;
    }

    // Dont forgot to initialise with null
    Node *hEnd = NULL;
    Node *hStart = NULL;
    Node *pivot;

    pivot = Partition(head,end,&hStart,&hEnd);
    printLinkList(pivot);
    printLinkList(hStart);

    // if pivot is not equal to hstart then it has element less then pivot
    if(pivot!=hStart){

        Node *temp = hStart;

        while(temp->next!=pivot){
            temp = temp->next;
        }

        temp->next = NULL;

        hStart = RecursiveQuickSort(hStart,temp);

        temp = getEnd(hStart);
        temp->next = pivot;
    }

    pivot->next = RecursiveQuickSort(pivot->next,hEnd);

    return hStart;
}

void QuickSort(Node **head){
    printLinkList(*head);
    (*head) = RecursiveQuickSort(*head, (getEnd(*head)));
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



int main()
{

    Node *root = createNode(3);
    root->next = createNode(5);
    root->next->next = createNode(11);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(7);
    root->next->next->next->next->next = createNode(10);
    printLinkList(root);
    QuickSort(&root);
    printLinkList(root);
    return 0;
}
