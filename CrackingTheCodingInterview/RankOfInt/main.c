#include <stdio.h>
#include <stdlib.h>

typedef struct Bnode node;

struct Bnode{

    int data;
    struct Bnode *left, *right;
    int leftSize;
};

node * createNode(int d){

    node * newNode = malloc(sizeof(node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->leftSize = 0;

    return newNode;
}

int getRank(node *root , int d){

    if(!root){
        return 0;
    }

    if(root->data == d ){
        return root->leftSize;
    }
    else if(root->data<d){

        return root->leftSize+1+ getRank(root->right,d);
    }
    else{
        return getRank(root->left,d);
    }
}


//Insert node
int insertNode(node **root, int d){

    if(!*root){
        *root = createNode(d);
        return 1;
    }

    if((*root)->data ==d ){
        (*root)->leftSize++;
        return 1;
    }
    else if((*root)->data<d){

        return insertNode(&((*root)->right),d);
    }
    else{
        (*root)->leftSize++;
        return insertNode(&((*root)->left),d);
    }
}

int track(node **root, int d){

    insertNode(root,d);
}

int main()
{

    node *root = createNode(5);
    track(&root,1);
    track(&root,4);
    track(&root,4);
    printf("Rank of %d : %d\n",3, getRank(root,3));
    track(&root,5);
    track(&root,9);
    track(&root,7);
    track(&root,13);
    track(&root,3);
    printf("Rank of %d : %d\n",1, getRank(root,1));
    printf("Rank of %d : %d\n",3, getRank(root,3));
    printf("Rank of %d : %d\n",4, getRank(root,4));
    printf("Rank of %d : %d\n",8, getRank(root,8));
    track(&root,1);
    printf("Rank of %d : %d\n",1, getRank(root,1));

    return 0;
}
