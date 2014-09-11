#include <stdio.h>
#include <stdlib.h>


typedef struct tstNode tstNode_t;

struct tstNode {

    char data;
    int eos;
    tstNode_t * left;
    tstNode_t * eq;
    tstNode_t * right;

};

tstNode_t * createNode (char c){

    tstNode_t* newNode = malloc(sizeof(tstNode_t));

    newNode->left = NULL;
    newNode->right = NULL;
    newNode->eq = NULL;
    newNode->eos =0;
    newNode->data = c;

    return newNode;
}

tstNode_t * insert(tstNode_t * tRoot, char *data){

    if(!tRoot){
        tRoot = createNode(*data);
 //       tRoot->data = data;
        tRoot->eos = 0;
    }

    if(tRoot->data < *data){
        tRoot->left = insert(tRoot->left,data);
    }
    else if(tRoot->data == *data){

        if(*(data+1)){
            tRoot->eq = insert(tRoot->eq,data+1);
        }
        else{
            tRoot->eos = 1;
        }
    }
    else{
        tRoot->right = insert(tRoot->right,data);
    }

    return tRoot;
}

int max(int a,int b,int c){

    return (a>b)?((a>c)?a:c):b;
}

int maxWordLength(tstNode_t * root){

    if(!root)
        return 0;
    else{
        max( maxWordLength(root->left), maxWordLength(root->eq)+1, maxWordLength(root->right));
    }
}
int Search(tstNode_t * troot, char *key){

    if(!troot){
        return 0;
    }

    if(*key<troot->data){
       return Search(troot->left,key);
    }
    else if(*key== troot->data){
        if(*(key+1)){
            return  Search(troot->eq,key+1);
        }
        else if(troot->eos){
            return 1;
        }
    }
    else{
        return Search(troot->right,key);
    }

    return 0;
}


int main()
{

    tstNode_t* root = NULL;

    root = insert(root, "cat");
    root = insert(root, "cats");
    root = insert(root, "upper");
    root = insert(root, "bug");

    int ans = Search(root,"caat");

    if(ans)
        printf("Found\n");
    else
        printf("Not Found\n");

    printf("Max Word Length %d\n", maxWordLength(root));
    return 0;
}
