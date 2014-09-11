#include <stdio.h>
#include <stdlib.h>

#include <stdio.h>
#include <stdlib.h>


struct BinaryTreeNode {
    int data;
    struct BinaryTreeNode *left;
    struct BinaryTreeNode *right;
};

struct BinaryTreeNode * createNewNode (int data){

    struct BinaryTreeNode *newNode = (struct BinaryTreeNode*) malloc(sizeof(struct BinaryTreeNode));

    if(!newNode)
    {
        printf("Error in allocating Memory\n");
        return NULL;
    }

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void reverse(struct BinaryTreeNode **r11,struct BinaryTreeNode **r22, int l){

    struct BinaryTreeNode *r1 , *r2;
    r1 = *r11;
    r2 = *r22;

    if(!r1 || !r2){
        return;
    }



    if(l%2==1){
        printf("%d %d\n", r1->data,r2->data);
        int temp = r1->data;
        r1->data = r2->data;
        r2->data = temp;
    printf("%d %d\n", r1->data,r2->data);
    }
    reverse(&(r1->left), &(r2->right), l+1);
    printf("Before Revers :%d %d\n", r1->data,r2->data);
    reverse(&(r1->right), &(r2->left),l+1);
    printf("After Revers :%d %d\n", r1->data,r2->data);
    return;
}

int printInorder(struct BinaryTreeNode *r1){

    if(!r1){
        return;
    }
    printInorder(r1->left);
    printf("%d ",r1->data);
    printInorder(r1->right);
}
int main()
{

    struct BinaryTreeNode *root = createNewNode(10);
    root->left = createNewNode(8);
    root->right = createNewNode(12);
    root->left->left = createNewNode(3);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(11);
    root->right->right = createNewNode(15);

    printInorder(root);
    printf("\n");
    reverse(&(root->left), &(root->right),1);
    printInorder(root);
    printf("Hello world!\n");
    return 0;
}
