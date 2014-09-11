#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct Graph {
    int vertex;
    int edges;
    int **adjMat;
};


struct Graph * createGraph (int vertex, int edges){

    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));

    assert(graph);

    graph->vertex = vertex;
    graph->edges = edges;

        int temp[5][5] =  {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    graph->adjMat = (int **)malloc(sizeof(int)*vertex);

    assert(graph->adjMat);

    int i,j;
    for(i=0;i<vertex;i++){
        graph->adjMat[i] = malloc(sizeof(int)*vertex);
        for(j=0;j<vertex;j++){
            graph->adjMat[i][j] = temp[i][j];
        }

    }

    return graph;
};

int count = 0;
//Check count of Simple path form src to dest
int DFSAlgoCountingPath(struct Graph * graph,int visited[],int src, int dest ){

     visited[src]=1;
     printf("%d ",src);

     if(src==dest){
       count++;
       printf("\n");
        visited[src]=0;
       return;

     }
     int i;

     for(i=0;i<graph->vertex;i++){
        if((!visited[i])&&(graph->adjMat[src][i])){
           // printf("Calling Recursively %d %d \n",src,i);
            DFSAlgoCountingPath(graph,visited,i,dest);
            visited[i]=0;
        }
     }
}

int SimplePathCountUtil(struct Graph *graph, int src, int dest){
    int *visited1 = malloc(graph->vertex*sizeof(int));

    memset(visited1,0,graph->vertex*sizeof(int));
    DFSAlgoCountingPath(graph,visited1,src,dest);
    printf("%d Path Exists\n",count);

}

//Check simple path Exist form src to dest
int DFSAlgo(struct Graph * graph,int visited[],int src, int dest ){

     visited[src]=1;
     printf("%d ",src);

     if(src==dest){
       printf("\n");
       return 1;

     }
     int i;

     for(i=0;i<graph->vertex;i++){
        if((!visited[i])&&(graph->adjMat[src][i])){
           // printf("Calling Recursively %d %d \n",src,i);
            if(DFSAlgo(graph,visited,i,dest)){
                return 1;
            }
        }
     }

     return 0;
}


int SimplePathTravelUtil(struct Graph *graph, int src, int dest){
    int *visited = malloc(graph->vertex*sizeof(int));

    memset(visited,0,graph->vertex*sizeof(int));
    if(DFSAlgo(graph,visited,src,dest)){

        printf("Path Exists\n");
    }
    else{
        printf("Path doesnt Exists\n");
    }
}



int main()
{

    struct Graph * graph = createGraph(5,7);

//    graph->adjMat = temp;
    SimplePathTravelUtil(graph,1,3);
    printf("\n\n");
    SimplePathCountUtil(graph,1,3);
    return 0;
}
