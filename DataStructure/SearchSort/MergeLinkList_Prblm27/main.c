#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * next;

};

struct node *sortedMerge(struct node  *a, struct node  *b){

    struct node * result = NULL;

    if(!a){
        return b;
    }
    if(!b){
        return a;
    }

    if(a->data <= b->data){
        result = a;
        result->next =sortedMerge(a->next,b);
    }
    else{
        result = b;
        result->next = sortedMerge(a,b->next);
    }

    return result;
}

void split(struct node *src, struct node **a, struct node **b){

    if(src == NULL || src->next==NULL){
        *a = src;
        *b = NULL;
    }

    struct node *fast = src->next;
    struct node *slow = src;

    while(!fast){
        fast = fast->next;

        if(!fast){
            fast =fast->next;
            slow = slow->next;
        }
    }

    *a= src;
    *b = slow->next;
    slow->next = NULL;

}

void MergeSort(struct node **headref){

    struct node *head=  *headref;
    struct node *a, *b;

    if(!head || !head->next){
        return;
    }

    split(head,&a,&b);

    MergeSort(&a);
    MergeSort(&b);

    *headref = sortedMerge(a,b);
}

void push(struct  node **head, int data){

    struct node * newNode = malloc(sizeof(struct node));

    newNode->data = data;

    newNode->next = (*head);

    (*head) = newNode;
}

void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}


int main()
{
 /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;

  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 15);
  push(&a, 10);
  push(&a, 5);
  push(&a, 20);
  push(&a, 3);
  push(&a, 2);

  /* Sort the above created Linked List */
  MergeSort(&a);

  printf("Sorted Linked List is: \n");
  printList(a);
    return 0;
}
