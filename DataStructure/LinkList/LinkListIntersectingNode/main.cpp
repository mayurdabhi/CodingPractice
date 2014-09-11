#include <iostream>
#include <list>

using namespace std;

typedef struct node Node ;

struct node{

    int data;
    struct node *next;
};

Node * createNode(int data)
{
    Node * newNode = new Node;//(Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int FindInterSectionPointWithStack(Node *r1, Node *r2){

    list<Node *> l1;
    list<Node *> l2;

    Node *t1 = r1;
    Node *t2 = r2;

    while(t1){
        l1.push_back(t1);
        t1=t1->next;
    }

    while(t2){
        l2.push_back(t2);
        t2=t2->next;
    }

    int flag = 0;
    Node *temp;
    while(!l1.empty() && !l2.empty()){

        if(l1.back()==l2.back()){
            l1.pop_back();
            temp = l2.back();
            l2.pop_back();
        }
        else{
            flag=1;
            break;
        }
    }

    if(flag){
        cout<<"LinkList Intersect at Point: "<<temp->data<<endl;
        return 1;
    }
    cout<<"LinkList is not intersecting\n";
    return 0;
}


int main()
{
    Node *root = createNode(2);
    root->next = createNode(5);
    root->next->next = createNode(7);
    root->next->next->next = createNode(8);
//  root->next->next->next->next = createNode(7);
    root->next->next->next->next = createNode(9);
    root->next->next->next->next->next = createNode(10);
    root->next->next->next->next->next->next = createNode(11);

    Node *root2 = createNode(12);
    root2->next = createNode(15);
    root2->next->next = createNode(16);
    root2->next->next->next = root->next->next->next->next;

    FindInterSectionPointWithStack(root,root2);
    return 0;
}
