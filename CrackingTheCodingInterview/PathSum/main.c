#include <stdio.h>
#include <stdlib.h>

struct node
{
      struct node *left,*right,*parent;
      int key;
};

typedef struct node *Node;

//n node and log(n) height then total O(log(n)!)
void printAllPaths(Node root,int currentSum, int totalSum)
{
       if(root==NULL)return;

      //  printf("Current SUM %d Current node : %d\n",currentSum,root->key);
       if(root->key==currentSum)
       {
               // printf("Current node : %d\n",root->key);
               printPath(root,totalSum);  //print the currently found path separately
               printf("\n");
       }
       else
       {
                printAllPaths(root->left, currentSum - root->key, totalSum);
                printAllPaths(root->right, currentSum - root->key, totalSum);
       }

/*But to cover the entire possibilities u must not return from here otherwise the solution paths starting from root->left or root->right will remain unexplored.
*/
       printAllPaths(root->left, totalSum ,totalSum);
       printAllPaths(root->right, totalSum ,totalSum);

       return;
}

void printPath(Node root,int sum)
{
        if(!root){
            return;
        }
        if(root->key==sum)
               printf(" %d ",root->key);
        else
        {
            printPath(root->parent,sum-root->key);
            printf(" %d ",root->key);
        }


       return;
}

Node createNode(Node parent,int i){

    Node newNode = malloc(sizeof(struct node));

    newNode->key = i;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = parent;

}

int main()
{

    Node root = createNode(NULL,6);
    root->left = createNode(root,4);
    root->right = createNode(root,8);
    root->left->left = createNode(root->left,3);
    root->left->right = createNode(root->left,5);
    root->right->left = createNode(root->right,7);
    root->right->right = createNode(root->right,10);

    printAllPaths(root,15,15);

    return 0;
}
