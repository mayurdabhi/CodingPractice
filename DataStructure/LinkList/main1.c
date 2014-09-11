#include <stdio.h>
#include <stdlib.h>


struct ListNode{
    int data;
    struct ListNode *next;
};

//Insert new node in linklist
// use double pointer for head node, so that you dont need to return new node
struct ListNode *CreateLinkList(int data){
    struct ListNode *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));

    if(head == NULL)
    {
         printf("Memory Error while creating LinkList\n");
         return NULL;
    }
    else{
        head->data = data;
        head->next = NULL;
        printf("LinkList created\n");
    }
    return head;
}
void InsertIntoLinkList(struct ListNode **head, int data, int position){

    struct ListNode *newNode, *temp;

    newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

    if(!newNode){
        printf("Memory Error while inserting node into linklist\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if(position ==1){
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at head of linklist\n");
    }
    else{

        temp = *head;
        while(temp->next!=NULL){
            position--;

            if(position - 1 == 0){
                newNode->next =temp->next;
                temp->next = newNode;
                printf("Node inserted at given position of linklist\n");
                return;
            }
            temp= temp->next;
        }

        if(position > 0){
            printf("No such position exists\n");
        }
    }
    return;
}
struct ListNode * NthNodeFromEnd(struct ListNode *head, int NthNodeNumber)
{
    struct ListNode *temp, *NthNode;
    int count =0;
    temp = head;
    NthNode  = head;

    for(temp = head; temp!=NULL;){
        count++;
        if(NthNodeNumber - count < 0){
            NthNode = NthNode->next;
        }
        temp = temp->next;
    }

    //checks that nth  value is less than length of link list
    if(count>= NthNodeNumber){
        printf("NthNode from End :: %d\n",NthNode->data);
        return NthNode;
    }
    else
        return NULL;
};


void PrintLinkList(struct ListNode *head){
    struct ListNode *temp;
    temp = head;
    printf("Printing LinkList::\n");
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp = temp->next;
    }
}

void SearchInLinkList(struct ListNode *head, int data){

    struct ListNode *temp;
    // = (struct ListNode *)malloc(sizeof(struct ListNode));
    temp = head;

   while(temp != NULL){
        if(temp->data == data){
            printf("Node found in LinkList\n");
            return;
        }
        temp = temp->next;
   }
   printf("Node is not found in LinkList\n");

}

void FindMiddle(struct ListNode *head)
{
    struct ListNode *fast,*slow;

    fast =slow = head;
    int i=0;

    while(fast->next != NULL){
        if(i==0){
            fast = fast->next;
            i=1;
        }
        else if(i==1)
        {
            fast = fast->next;
            slow = slow->next;
            i=0;
        }
    }

    printf("Middle Element of LinkList :: %d\n",slow->data);
}

void IsLinkListLengthEven(struct ListNode *head)
{
    struct ListNode *tempHead ;

    while(tempHead && tempHead->next){
        tempHead = tempHead->next->next;
    }

    if(tempHead){
        printf("LinkList length is Odd\n");
    }
    else
    {
        printf("LinkList length is Even\n");
    }
}

struct ListNode *RecursiveReverse (struct ListNode *head){
    struct ListNode *secondNode ;

    if(head == NULL)
        return head;
    if(head->next == NULL)
        return head;

    secondNode= head->next;
    head->next =NULL;

    struct ListNode *reverseRest;

    reverseRest = RecursiveReverse(secondNode);
    secondNode->next =head;
    return reverseRest;

}

void PrintLinkListFromEnd(struct ListNode *head){

    if(!head)
        return;

    PrintLinkListFromEnd(head->next);
    printf("%d\n",head->data);
}

void LengthLinkList(struct ListNode *head){
    struct ListNode *temp;
    int count = 0;

    temp = head;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    printf("Length of LinkList::%d\n", count);

}


int main()
{
    struct ListNode *head;
    head = (struct ListNode *)malloc(sizeof(struct ListNode));

    head = CreateLinkList(7);
    InsertIntoLinkList(&head,3,1);
    InsertIntoLinkList(&head,4,1);
    InsertIntoLinkList(&head,2,1);
    InsertIntoLinkList(&head,5,2);
    InsertIntoLinkList(&head,6,3);
 //   InsertIntoLinkList(&head,7,6);
    PrintLinkList(head);
    NthNodeFromEnd(head,3);
    LengthLinkList(head);
    SearchInLinkList(head,4);
    SearchInLinkList(head,9);
    head = RecursiveReverse(head);
    PrintLinkList(head);
    FindMiddle(head);
    IsLinkListLengthEven(head);

    printf("Print linklist from End (Recursively)::\n");
    PrintLinkListFromEnd(head);

    return 0;
}
