#include <stdio.h>
#include <stdlib.h>

struct AVLNode {

    int data;
    int height;
    struct AVLNode* left;
    struct AVLNode* right;
};


int max(int a, int b){

    return (a>b)?a:b;
}

struct AVLNode * RightRotate(struct AVLNode * node){

    struct AVLNode *temp = node->right;

    node->right = temp->left;
    temp->left = node;

    node->height = max(height(node->left),height(node->right))+1;
    temp->height = max(height(temp->right),node->height)+1;
    return temp;
}

struct AVLNode * leftRotate(struct AVLNode * node){

    struct AVLNode *temp = node->left;

    node->left = temp->right;
    temp->right = node;

    node->height = max(height(node->left),height(node->right))+1;
    temp->height = max(height(temp->left),node->height)+1;
    return temp;
}

int height(struct AVLNode * root){

    if(!root)
        return 0;

    else{
      /* int left = height(root->left);
       int right = height(root->right);
       return max(left,right)+1;
       */
       return root->height;
    }
}

struct AVLNode* InsertNode(struct AVLNode *root, int data){
    if(!root){
        root= malloc(sizeof(struct AVLNode));
        root->data = data;
        root->height = 0;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    else if(root->data > data){
        root->left = InsertNode(root->left,data);

        if(height(root->left)-height(root->right)>1){
            if(data < root->left->data){
                root = leftRotate(root);
            }
            else{
                root->left = leftRotate(root->left);
                root = RightRotate(root);
            }
        }


    }
    else if(root->data < data){
        root->right = InsertNode(root->right,data);

        if(height(root->right)-height(root->left)>1){
            if(data > root->right->data){
                root = RightRotate(root);
            }
            else{
                root->right = RightRotate(root->right);
                root = leftRotate(root);
            }
        }
    }

    root->height = max(height(root->left),height(root->right))+1;
    return root;
};

void preOrder(struct AVLNode *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct AVLNode *root)
{
    if(root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}


int main()
{

     struct AVLNode *root = NULL;

      /* Constructing tree given in the above figure */
      root = InsertNode(root, 10);

      root = InsertNode(root, 20);
      root = InsertNode(root, 30);
      root = InsertNode(root, 40);
      root = InsertNode(root, 50);
      root = InsertNode(root, 25);

      /* The constructed AVL Tree would be
                30
               /  \
             20   40
            /  \     \
           10  25    50
      */

      printf("Pre order traversal of the constructed AVL tree is \n");
     // inOrder(root);
   // return 0;


    int a=2, b=2;

    if(a>b){
        printf(">\n");
    }
    else{
        printf("<\n");
    }
}
