#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

typedef struct treeNode Node;

struct treeNode{
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

Node *createNode(int d){
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = d;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

list<list<Node *> > createLinkList(Node *root){

        // create list to hold each linklist of type Node
        //Must See: How  to declare and access element
        list<list<Node *> > result;// = new list<list<Node> >();

        list<Node *> curr;// = new list<Node *>();
        list<Node *> temp;// = new list<Node *>();

        curr.push_back(root);

        while(!curr.empty()){

            result.push_back(curr);

            temp = curr;
            curr.clear();// = new list<Node *>();

            list<Node *>::iterator it;

            for(it=temp.begin();it!=temp.end();++it){

                if((*it)->left!=NULL){
                    curr.push_back((*it)->left);
                }
                if((*it)->right!=NULL){
                    curr.push_back((*it)->right);
                }
            }
        }

    return result;
}


int compareTree(Node *t1,Node *t2){

    if(!t1 && !t2){
        return 1;
    }

    if(t1->data != t2->data){
        return 0;
    }
    else{
        return (compareTree(t1->left,t2->left) && compareTree(t1->right,t2->right));
    }
}

int checkForSubtree(Node *t1, Node *t2){

    if(!t2){
        return 1;
    }

    if(!t1 && t2){
        return 0;
    }

    if(t1->data==t2->data){
        if(compareTree(t1,t2)){
            return 1;
        }
    }

    return (checkForSubtree(t1->left,t2)||(checkForSubtree(t1->right,t2)));
}



int main()
{

    Node *root = createNode(5);
    root->left = createNode(4);
    root->left->left = createNode(3);
    root->right = createNode(6);
    root->right->left = createNode(7);
    root->right->left->right = createNode(9);

    Node *root2 = createNode(6);
    root2->left = createNode(4);
    root2->left->right = createNode(9);

    list<list<Node *> > result;// = new list<list<Node>>();

    result = createLinkList(root);
    cout<<"Number of Levels :"<<result.size()<<endl;


    int i = checkForSubtree(root,root2);
    if(i){
        cout<<"T2 is SubTree of T1\n";
    }
    else{
        cout<<"T2 is not a SubTree of T1\n";
    }

    return 0;
}
