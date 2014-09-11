#include <stdio.h>
#include <stdlib.h>

typedef struct node Node ;

struct node{

    int data;
    struct node *next;
};

Node * createNode(int data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int printLinkList(Node *head){

    Node *temp = head;

    while(temp){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int FloydCycle(Node *root){

    Node *slow, *fast;
    slow = root;
    fast = root;
    int flag = 0;
//Normal Way
//Do not use it while detection cycle;
/*
    while(slow && fast){

        fast = fast->next;
        if(slow == fast){
            flag=1;
            break;
        }
        if(fast == NULL){
            break;
        }
        fast = fast->next;
        if(slow == fast){
            flag=1;
            break;
        }
        slow = slow->next;
    }
*/
    // To detect Cycle do as follow
    do{
        if(!fast || !fast->next){
            return 0;
        }
        else{
            slow = slow->next;
            fast = fast->next->next;
        }

    }while(slow != fast);

    printf("Cycle Found\n");
    slow = root;
    Node *start;
    while(slow != fast){
        printf("%d %d\n",slow->data,fast->data);
        slow = slow->next;
        start = fast;
        fast = fast->next;

    }
    //to remove loop;
    start->next = NULL;

    printLinkList(root);
    printf("Start of loop :%d\n",fast->data);
    return 1; // returning start of loop
}



int main()
{
    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
    root->next->next->next->next = createNode(9);
    root->next->next->next->next->next = createNode(10);
    root->next->next->next->next->next->next = createNode(11);
    root->next->next->next->next->next->next->next = root->next->next->next;

    FloydCycle(root);

    return 0;
}
