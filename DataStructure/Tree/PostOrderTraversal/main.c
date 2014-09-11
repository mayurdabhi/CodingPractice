#include <stdio.h>
#include <stdlib.h>

typedef struct treenode Node;
typedef struct stack Stack;

struct treenode{
    int data;
    struct treenode * left;
    struct treenode *right;
};

struct stack{
    int size;
    int top;
    struct treenode **nodeList;
};


Node * pop(Stack *s ){

    if(IsEmpty(s)){
        return NULL;
    }
    else{
        Node* tnode = s->nodeList[s->top];
        s->top--;
      //  printf("Pop Top: %d\n",s->top);
        return tnode;
    }
}

int push(Stack *s, Node * tnode){

    if(IsFull(s)){
        return 0;
    }
    else{
        s->nodeList[s->top+1] = tnode;
        s->top++;
        //printf("Top: %d\n",s->top);
        return 1;
    }
}

Node * createNode (int data){

    Node * newNode = (Node *)malloc(sizeof(Node));

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

Stack * createStack(int size){

    Stack *s = malloc(sizeof(Stack));
    s->nodeList = (Node **)malloc(size*sizeof(Node *));
    s->size = size;
    s->top = -1;
}

int IsEmpty(Stack *s){

    if(s->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int IsFull(Stack *s){

    if(s->top==s->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

Node * top(Stack *s){

    if(s->top==-1)
        return NULL;

    return s->nodeList[s->top];
}
int PostOrderTraversal(Node *root){

    Stack *s = createStack(5);
    int count = 18;
    while(count){
        count--;

        if(root){
            printf("root : %d\n",root->data);
            push(s,root);
            root = root->left;
        }
        else{

            if(IsEmpty(s)){
                printf("Stack is empty\n");
                break;
            }
            else if(top(s)->right==NULL){
                root = pop(s);
                printf("1 :%d\n",root->data);

                if(top(s)->right==root){
                    printf("2 : %d\n",top(s)->data);
                    pop(s);
                }
            }

           if(IsEmpty(s)){
                root =NULL;
                break;
            }
            else{
                root = top(s)->right;
            }
        }



    }

}

int main()
{
    Node * root =createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);

    PostOrderTraversal(root);
    return 0;
}
