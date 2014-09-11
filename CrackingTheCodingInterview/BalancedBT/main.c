#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode Node;

struct treeNode{
    int data;
    Node *left;
    Node * right;
};

int max(int a, int b){

    return (a>b)?a:b;
}

int checkBalanceBT(Node *root, int *flag){

    if(!root){
        return 0;
    }

    int l,r;

    l = checkBalanceBT(root->left,flag);
    r = checkBalanceBT(root->right,flag);
    printf("L %d , R:%d Data:%d\n",l,r,root->data);
    if(abs(l-r)>1){
        *flag = 0;
    }

    {
        int m =  max(l,r)+1;
        printf("max : %d\n",m);
        return m;
    }
}

int checkBST(Node *root, int minVal, int maxVal){

    if(!root){
        return 1;
    }

    int l,r;

    if((minVal!= -1 && root->data <= minVal)||
       (maxVal!=-1 && root->data > maxVal)){
        return 0;
    }

    if(!(checkBST(root->left,minVal,root->data))||
       !(checkBST(root->right,root->data,maxVal))){
            return 0;
    }
    else{
        return 1;
    }

}


Node * createNode(int d){

    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main()
{
    Node* root = createNode(4);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->right->right = createNode(8);
    //root->right->right->right = createNode(10);
    int i;
    i=1;
    checkBalanceBT(root,&i);

    if(i){
        printf("Tree is Balanced BT\n");
    }
    else{
        printf("Tree is not Balanced BT\n");
    }

    i = checkBST(root,-1,-1);
    if(i){
        printf("Tree is BST\n");
    }
    else{
        printf("Tree is not BST\n");
    }
    return 0;
}
