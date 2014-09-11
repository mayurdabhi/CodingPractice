#include <stdio.h>
#include <stdlib.h>

struct ListNode{

    //int src;
    int dest;
    struct ListNode* next;
};

struct List{
    struct ListNode *head;
};

struct Graph {

    int V;
    struct List *adjList;
};

struct ListNode * createListNode(int i){
    struct ListNode * temp  = malloc(sizeof(struct ListNode));

    temp->dest = i;
    temp->next = NULL;

    return temp;
};

struct Graph * createGraph(int vertex){

        struct Graph *graph = malloc(sizeof(struct Graph));

        graph->V = vertex;
        graph->adjList = (struct List*) malloc(vertex*sizeof(struct List));
        int i;

        for(i=0;i<graph->V;i++){

                graph->adjList[i].head = NULL;
        }

        return graph;
};

int addEdge(struct Graph * graph ,int u, int v){

    struct ListNode * temp  = createListNode(v);
    struct List* tempList  = &graph->adjList[u];


    if(tempList->head == NULL){
        tempList->head = temp;
    }
    else{
        temp->next = tempList->head;
        tempList->head = temp;
    }

}

int printList(struct Graph* g){

  int i;
  for(i=0;i<g->V;i++){

    struct List * tempList  = &g->adjList[i];

    struct ListNode * temp  = tempList->head;;
    printf("%d ",i);
    while(temp){
        printf("-> %d ",temp->dest);
        temp = temp->next;
    }
    printf("\n");
  }
}

int DFSUtil(struct Graph *g, int visited[], int src, int order[] ){

    int static ind = 0;

    visited[src] = 1;
    struct ListNode* temp = g->adjList[src].head;

    while(temp){
        if(!visited[temp->dest]){
            DFSUtil(g,visited,temp->dest,order);
        }
        temp = temp->next;
    }
    order[ind++] = src;
}

int printOrder(int order[], int n){

        int c =0;
        printf("topological Order : \n");
        for(c=n-1;c>=0;c--){
            printf("%d ",order[c]);
        }
        printf("\n");
}

int checkUniqueNess(struct Graph *g, int order[]){


    int i,src, next,flag;

    for(i=g->V-1;i>0;i--){

        src = order[i];
        next = order[i-1];
        flag = 0;
        struct ListNode* temp = g->adjList[src].head;

        while(temp){
            if(temp->dest == next ){
                flag= 1;
                break;
            }
            temp = temp->next;
        }
       if(flag==0){
            break;
        }

    }

    if(flag==0){
        printf("Multiple Topological Order Present\n");
    }
    else{
        printf("Unique Topological Order Present\n");
    }
    return;
}


int topologicalOrder(struct Graph *g){

    int* visited =(int *) malloc(g->V*sizeof(int));
    int* order =  (int *) malloc(g->V*sizeof(int));
    int i;
    for(i=0;i<g->V;i++){
        visited[i]=0;
        order[i] = -1;
    }

    for(i=0;i<g->V;i++){
        if(visited[i]==0){
				DFSUtil(g,visited,i,order);
        }
    }

    printOrder(order, g->V);

    checkUniqueNess(g,order);
}


int main()
{

    struct Graph* graph = createGraph(6);

    addEdge(graph,0,2);
    addEdge(graph,1,2);
    addEdge(graph,1,5);
    addEdge(graph,2,3);
    addEdge(graph,2,4);
    addEdge(graph,3,5);
    addEdge(graph,4,3);
    printList(graph);
    topologicalOrder(graph);
    return 0;
}
