#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {

    int data;
    struct node * left;
    struct node * right;
};

struct node * CreateBST(int n){

    struct node * root = malloc(sizeof(struct node));

    assert(root!=NULL);

    root->data = n;
    root->left = NULL;
    root->right = NULL;

    return root;
};

int insertNode (struct node * head,int d){

    struct node * root = malloc(sizeof(struct node));
    struct node * temp = head;
    assert(root!=NULL);

    root->data = d;
    root->left = NULL;
    root->right = NULL;

    while(temp){
        if(temp->data >= root->data){

            if(!temp->left){
                temp->left = root;
                return 0;
            }
            else{
                temp = temp->left;
            }

        }
        else{

            if(!temp->right)
            {
                temp->right = root;
                return 0;
            }
            else{
                temp= temp->right;
            }
    }
    }
    return 0;
}

int findNthElement(struct node * root, int n, int *k){

    static int count = 1;
    if(root){
        findNthElement(root->left,n,k);
        if(count==n){
            printf("%d\n", root->data);
            *k = root->data;
        }
        count++;

        findNthElement(root->right,n,k);
    }
}

int main()
{

    struct root *root = CreateBST(8);
    insertNode(root,5);
    insertNode(root,3);
    insertNode(root,6);
    insertNode(root,9);
    insertNode(root,10);
    insertNode(root,14);
    insertNode(root,2);
    int k;

    findNthElement(root,7,&k);

    return 0;
}
