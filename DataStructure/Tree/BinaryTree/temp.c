#include <stdlib.h>
#include <stdio.h>

/* A binary tree node has data, left child and right child */
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/**
* Helper function that allocates a new node with the given data and
* NULL left and right pointers.
*
* @param data - data whose node to be created
* @return - node with data
*/
struct node* newNode(int data)
{
    struct node* node = (struct node *)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

/**
 * Check if two trees are Quasi-Isomorphic to each other.
 *
 * @param root - root of the first tree
 * @param root1 - root of the second tree
 * @return - 1 if both are quasi-isomorphic, else 0
 */
int TreesAreQuasiIsomorphic(struct node *root, struct node *root1){
    // both tree are empty, so return true(1)
    if(root==NULL && root1==NULL)
        return 1;
    // one tree is empty
    if(root==NULL || root1==NULL)
        return 0;

    return((TreesAreQuasiIsomorphic(root->left, root1->right) &&
              TreesAreQuasiIsomorphic(root->right, root1->left)) ||
              (TreesAreQuasiIsomorphic(root->right, root1->right) &&
              TreesAreQuasiIsomorphic(root->left, root1->left)));
}

/**
* Helper function for DisplayTree function. Recursively print the
* tree nodes. We pass 0 as default value for level.
*
* @param level - shows the level of the binary tree
* @param root - root of the tree
*/
void Display(int level, struct node *root){
    int i;
    printf("\n");
    if(root){
        Display(level+1, root->right);

        for(i=0 ; i<level ; i++)
            printf("    ");
        if(level == 0)
            printf("%d(R)", root->data);
        else
            printf("%d", root->data);
        Display(level+1, root->left);
    }
}

/**
* Display the tree in 90 degree anti-clockwise direction.
*  R shows Root node, nodes above R shows Right Subtree and nodes
*  below R shows left subtree.
*
* @param root - root of the tree
*/
void DisplayTree(struct node *root){
    printf("\nTree:(R-Root node, Above R-right subtree, Below R-left subtree)");
    Display(0, root);
}

int main()
{
    /* Constructed binary tree is
                7
              /   \
            8      2
          /  \    / \
        3     5  1   9
          \
            4
    */
    struct node *root = newNode(7);
    root->left        = newNode(8);
    root->right       = newNode(2);
    root->left->left  = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(1);
    root->right->right  = newNode(9);
    root->left->left->right = newNode(4);
    DisplayTree(root);

    /* Constructed binary tree is
                9
              /   \
            5     18
          /  \    / \
         2    7  16  23
          \
            4
    */
    struct node *root1  = newNode(9);
    root1->right        = newNode(18);
    root1->left         = newNode(5);
    root1->right->right = newNode(23);
    root1->right->left  = newNode(16);
    root1->left->right  = newNode(7);
    root1->left->left   = newNode(2);
    root1->left->left->right = newNode(4);
    DisplayTree(root1);

    if(TreesAreQuasiIsomorphic(root, root1)){
        printf("\nBoth trees are Quasi-Isomorphic.");
    } else{
        printf("\nBoth trees are not Quasi-Isomorphic.");
    }

    return 0;
}
