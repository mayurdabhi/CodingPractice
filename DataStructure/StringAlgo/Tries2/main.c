#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOC 26

#define FREE(p) \
    free(p);    \
    p = NULL;

typedef struct trieNode trieNode_t;

struct trieNode{

   // int data;
    int eos;
    trieNode_t* child[NOC];
};

typedef struct trie trie_t;

struct trie{

    int count;
    trieNode_t * root;
};


trieNode_t * createNode(){

   trieNode_t *pNode = NULL;

    pNode = (trieNode_t *)malloc(sizeof(trieNode_t));

//    trieNode_t * newNode = (struct trieNode *)malloc(sizeof(trieNode_t));

    if(!pNode){
        printf("MemoryAssignment Error\n");
        return NULL;
    }
    pNode->eos = 0;
    int i;

  //  pNode->child = (trieNode_t *)malloc(NOC * sizeof(trieNode_t));

    for(i=0;i<NOC;i++)
    {
        pNode->child[i]=NULL;
    }

    return pNode;
}

trie_t * initialise(){

    trie_t * tnew = (trie_t *)malloc(sizeof(trie_t));

    tnew->count = 0;
    tnew->root = createNode();

    return tnew;
}

int insert(trie_t  * troot, char key[]){

    int i, index;
    trieNode_t *temp  = troot->root;
    int len = strlen(key);

    for(i=0;i<len;i++){

        index = key[i]-'a';
        if(!temp->child[index]){
            temp->child[index] = createNode();
        }

        temp = temp->child[index];
    }
    troot->count++;

    temp->eos =troot->count ;
}

int search(trie_t *troot, char key[]){

    int i, index,len;
    len = strlen(key);
    trieNode_t *temp = troot->root;

    for(i=0;i<len;i++){
        index = key[i]-'a';

        if(!temp->child[index]){
            return 0;
        }
        temp = temp->child[index];
    }
    return (0!=temp && temp->eos);
}


int leafNode(trieNode_t *pNode)
{
    return (pNode->eos != 0);
}

int isItFreeNode(trieNode_t *pNode)
{
    int i;
    for(i = 0; i < 26; i++)
    {
        if( pNode->child[i] )
            return 0;
    }

    return 1;
}

int deleteHelper(trieNode_t *pNode, char key[], int level, int len)
{
    if( pNode )
    {
        // Base case
        if( level == len )
        {
            if( pNode->eos )
            {
                // Unmark leaf node
                pNode->eos = 0;

                // If empty, node to be deleted
                if( isItFreeNode(pNode) )
                {
                    return 1;
                }

                return 0;
            }
        }
        else // Recursive case
        {
            int index = key[level]-'a';

            if( deleteHelper(pNode->child[index], key, level+1, len) )
            {
                // last node marked, delete it
                FREE(pNode->child[index]);

                // recursively climb up, and delete eligible nodes
                return ( !leafNode(pNode) && isItFreeNode(pNode) );
            }
        }
    }

    return 0;
}

void deleteKey(trie_t *pTrie, char key[])
{
    int len = strlen(key);

    if( len > 0 )
    {
        deleteHelper(pTrie->root, key, 0, len);
    }
}



int deleteHelper1(trieNode_t *root,int level,  char key[], int size){

    if(root){

        if(level == size && root->eos){

            root->eos=0;
            int i;
            for(i=0;i<NOC;i++){
                    if(root->child[i])
                        return 0;
            }
            return 1;
            /*
            if(isItFreeNode(root))
                return 1;
            else
                return 0;
                */
        }
        else{

            int index = key[level]-'a';

            if(deleteHelper1(root->child[index],level+1,key,size)){

                free(root->child[index]);
                root->child[index] = NULL;
                int i;
                for(i=0;i<NOC;i++){
                    if(root->child[i]){
                        return 0;
                    }
                }


                return (!root->eos);// && isItFreeNode(root));
            }

        }
    }
    return 0;
}
int delete(trie_t *troot, char key[]){

    if(strlen(key)){
        deleteHelper1(troot->root,0,key,strlen(key));
    }
}

int main()
{
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    trie_t * trie;

    char output[][32] = {"Not present in trie", "Present in trie"};

    trie = initialise();
    int i;
    // Construct trie
    for(i = 0; i < 8; i++)
    {
        insert(trie, keys[i]);
    }

    // Search for different keys
    printf("%s --- %s\n", "the", output[search(trie, "the")] );
    printf("%s --- %s\n", "these", output[search(trie, "these")] );
    printf("%s --- %s\n", "their", output[search(trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(trie, "thaw")] );

    delete(trie,"their");
    printf("%s --- %s\n", "their", output[search(trie, "their")] );
}
