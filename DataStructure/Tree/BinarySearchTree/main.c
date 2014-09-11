#include <stdio.h>
#include <stdlib.h>


struct BST {

    int data;
    struct BST *left;
    struct BST *right;
};

struct BST * newNode(int data){

    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));

    if(!temp){

        printf("Memory Allocation Error\n");
        return NULL;
    }

    temp->data = data;
    temp->left=temp->right= NULL;

    return temp;
}

struct BST * insert(struct BST *root, int data){

        if(root == NULL)
        {
            return newNode(data);
            //return root;
        }

        if(root->data > data){

            root->left = insert(root->left,data);
        }
        else if(root->data < data){

            root->right = insert(root->right,data);
        }
        return root;
}

struct BST * FindMin(struct BST * root){
    if(root==NULL)
        return NULL;

    while(root->right)
    {
        root=root->right;
    }
    return root;
};

struct BST * inOrderSuccessor(struct BST * root, struct BST* node){

        if(node == NULL){
            return NULL;
        }

        if(node->right != NULL)
        {
            return FindMin(node->right);
        }

        struct BST* succ = (struct BST*)malloc(sizeof(struct BST));

        //Here we intinalise because, when we need to find successor of last node,
        // it will give garbage value, so identify it , put own known value.
        succ->data = 0;
        succ->left=succ->right = NULL;
        while(root){


            if(node->data > root->data){
                root = root->right;
            }
            else if(node->data < root->data){
                succ = root;
                root= root->left;
            }
            else{
                break;
            }
        }

        return succ;
}

struct BST * deleteNode (struct BST * root, int data){

        if(root == NULL)
            return NULL;

        if(data < root->data){
            root->left = deleteNode(root->left,data);
        }
        else if(data > root->data){
            root->right = deleteNode(root->right,data);
        }
        else{
            struct BST * temp ;

            if(root->left && root->right){

                temp = FindMin(root->right);
                root->data = temp->data;
                root->right = deleteNode(root->right,root->data);

            }
            else
            {
                temp = root;
                if(root->right == NULL){
                    root=root->left;
                }
                else if(root->left == NULL){
                    root= root->right;
                }

                free(temp);
            }
        }

    return root;
};


int checkForBST(struct BST* root, int *prev){

    if(root == NULL)
        return 1;

    if(!checkForBST(root->left,prev))
        return 0;

    if(root->data < *prev){
        return 0;
    }

    *prev = root->data;

    if(!checkForBST(root->right,prev))
        return 0;

   return 1;

}

struct BST* TrimBST(struct BST* root, int a, int b){

    if(root==NULL)
        return NULL;

    struct BST * temp =(struct BST*) malloc(sizeof(struct BST));

// Print Element Between Given Range and also Trim the Tree in Range
//Second Approach is not doing Trimming;


    root->left  = TrimBST(root->left,a,b);
    root->right = TrimBST(root->right,a,b);

    if(root->data < a){
        temp = root->right;
        free(root);
        return temp;
    }

    if(root->data>b){
        temp = root->left;
        free(root);
        return temp;
    }

    printf("%d",root->data);

    return root;
// Print Element Between Given Range

/*    if(root->data >= a){
        root->left = TrimBST(root->left,a,b);
    }

    if(root->data >= a && root->data <= b){
        root->data = root->data;
        printf("%d ",root->data);
    }

    if(root->data<=b){
            root->right = TrimBST(root->right,a,b);
    }

  return root;
  */
};

int countTrees(int n){

    if(n<=1){
        return 1;
    }
    else{
        int sum, left,right, root;
        sum = 0;
        for(root=1;root<=n;root++){
            left = countTrees(root-1);
            right =countTrees(n-root);

            sum += left*right;
        }
        return sum;
    }
}


struct BST* kthSmallestElement(struct BST* root,int *k){

    if(root == NULL)
    {
        return NULL;
    }
    else{
        struct BST * temp =  kthSmallestElement(root->left,k);

        if(!temp){
            *k = *k - 1;
            if(*k==0)
            {
                printf("Kth Smallest Element : %d\n",root->data);
                return root;
            }
        }
        else temp;
    }
    struct BST * temp1 = kthSmallestElement(root->right,k);

    return temp1;

};

int printBST(struct BST * root){

    if(root==NULL)
        return 0;

    printBST(root->left);
    printf("%d ",root->data);
    printBST(root->right);

    return 1;
}

int main()
{
//    printf("Hello world!\n");
/*
          4
        /   \
       2     8
           /   \
          5     10
           \
            7
           /
          6

*/
    struct BST* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(8);
    root->right->left = newNode(5);
    root->right->right = newNode(10);
    root->right->left->right = newNode(7);
    root->right->left->right->left = newNode(6);

    struct BST *temp;
    int a = -1;
//    int *p = &a;
/*
    if(checkForBST(root,&a)){
        printf("Tree is BST\n");
    }
    else{
        printf("Tree is not BST\n");
    }

    a= 3;

    temp = kthSmallestElement(root,&a);
    printf("Kth Smallest Element : %d\n",temp->data);

    temp = inOrderSuccessor(root,root->right->left->right);
    printf("Inorder Successor of 7:: %d\n",temp->data);

    deleteNode(root,8);

    temp = inOrderSuccessor(root,root->right->left->right);

    printf("Inorder Successor of 7:: %d\n",temp->data);
*/

    printBST(root);
    printf("\n");
    temp = TrimBST(root,3,7);
    //printBST(temp);


    printf("\nNumber of Trees with 3 Nodes : %d\n",countTrees(3));
    return 0;
}
