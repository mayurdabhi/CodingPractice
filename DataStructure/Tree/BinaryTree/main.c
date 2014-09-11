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

int HasPathSum(struct BinaryTreeNode *root, int sum, int a[], int index){

    if(root == NULL)
        return (sum == 0);

  //  if(root->left == NULL || root->right == NULL){

        a[index]=root->data;
        sum -= root->data;

        if(HasPathSum(root->left,sum,a,index+1)){
           // printPath(a,index+1);
           printf("%d ",a[index]);
            return 1;
        }

        if(HasPathSum(root->right,sum,a,index+1)){
           // printPath(a,index+1);
           printf("%d ",a[index]);
            return 1;
        }
        return 0;
    //}


}

void printPath(int a[], int index){
    int i=0;
    for(i=0;i<index;i++){

            printf("%d =>",a[i]);
    }
    printf("\n");
}

int FindAllAncestors(struct BinaryTreeNode *root, int data){

    if(root == NULL)
        return 0;

    if(root->data==data){
        printf("%d, ",root->data);
        return 1;
    }

    if((root->left && FindAllAncestors(root->left,data))||(root->right && FindAllAncestors(root->right,data) ))
    {
        printf("%d, ",root->data);
        return 1;
    }

    return 0;
}

int searchElement(int inOrder[], int inStart, int inEnd, int data){
    int i=0;
    for(i=inStart;i<=inEnd;i++){
        if(inOrder[i]==data)
                return i;
    }

}

struct BinaryTreeNode* BuildBinaryTree(int inOrder[], int preOrder[], int inStart, int inEnd){

    static int preIndex = 0;
    if(inStart>inEnd)
            return NULL;


    struct BinaryTreeNode *newNode ;
    int tempIndex;

    newNode = createNewNode(preOrder[preIndex++]);
    tempIndex = searchElement(inOrder,inStart,inEnd,newNode->data);

    newNode->left = BuildBinaryTree(inOrder,preOrder,inStart,tempIndex-1);
    newNode->right = BuildBinaryTree(inOrder,preOrder,tempIndex+1,inEnd);

    return newNode;
};

struct stack{
    int n;
    int top;
    struct BinaryTreeNode ** s;
};

struct stack * CreateStack(int n){

    struct stack* st = malloc(sizeof(struct stack));

    st->n  =n;
    st->top = -1;
    st->s = (struct BinaryTreeNode **)malloc(n*sizeof(struct BinaryTreeNode *));
};

struct BinaryTreeNode * pop(struct stack * st){

    if(st->top==-1){
        printf("Stack UnderFlow\n");
        return NULL;
    }

    struct BinaryTreeNode *temp = st->s[st->top];
    printf("Top Of Stack : %d\n",temp->data);
    st->top--;

    return temp;
};

int push (struct stack *st,struct BinaryTreeNode *node){

    if(st->top==st->n-1){
     printf("Stack Overflow\n")  ;
     return 0;
    }
    st->top++;
    st->s[st->top] = node;
    printf("Top Of Stack  push : %d\n",node->data);
    return 1;
}

int stackEmpty(struct stack *st){

    if(st->top==-1){
        return 1;
    }
    else
        return 0;
}

//Complexity : O(n)
int InorderWithOutRecursion(struct BinaryTreeNode * root,int size){

    if(!root){
        printf("Tree doesnt have any node\n");
        return 0;
    }

    struct BinaryTreeNode *current  = root;
    struct stack *st = CreateStack(size);

    while(current||!stackEmpty(st)){

        while(current)
        {
            push(st,current);
            current = current->left;
        }

        current = pop(st);
        printf("%d\n",current->data);
        current = current->right;
    }
}

//Complexity O(nlongn)

int MorrisTraversalPreOrder(struct BinaryTreeNode *root){

    struct BinaryTreeNode *current, *next;
    current = root;
    while(current){

            if(current->left==NULL){
                printf("%d\n",current->data);
                current = current->right;
            }
            else{
                next = current->left;
                while(next->right !=NULL && next->right !=current){
                    next = next->right;
                }

                if(next->right == NULL){
                    printf("%d\n",current->data);
                    next->right = current;
                    current = current->left;
                }
                else{

                    next->right = NULL;
                    current = current->right;
                }
            }
    }

}

int MorrisTraversalInOrder(struct BinaryTreeNode *root){

    struct BinaryTreeNode *current, *pre;

    current = root;
    while(current){

        if(current->left==NULL){
            printf("%d\n",current->data);
            current = current->right;
        }
        else{

            pre = current->left;

            while(pre->right != NULL && pre->right!=current){
                pre = pre->right;
            }

            if(pre->right==NULL){

                pre->right = current;
                current = current->left;
            }
            else{
                pre->right = NULL;
                printf("%d\n",current->data);
                current = current->right;
            }

        }
    }

}

int main()
{

    struct BinaryTreeNode *root = createNewNode(10);
    root->left = createNewNode(8);
    root->right = createNewNode(12);
    root->left->left = createNewNode(3);
    root->left->right = createNewNode(5);
    root->right->left = createNewNode(11);


   // InorderWithOutRecursion(root,6);
   // MorrisTraversalInOrder(root);
    MorrisTraversalPreOrder(root);
    /*

    int sum = 1;
    int a[3];

    if(HasPathSum(root,22,a,0))
    {
        printf("Path Found!\n");
    }
    else
    {
        printf("No Such Path Found!!\n");
    }


    int inOrder[] = {3,2,4,1,6,5};
    int preOrder[] = {1,2,3,4,5,6};

    root = BuildBinaryTree(inOrder,preOrder,0,5);

    if(HasPathSum(root,6,a,0))
    {
        printf("Path Found!\n");
    }
    else
    {
        printf("No Such Path Found!!\n");
    }

    FindAllAncestors(root,6);
*/
    return 0;
}
