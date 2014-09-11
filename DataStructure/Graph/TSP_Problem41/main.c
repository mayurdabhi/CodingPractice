#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>

struct Edge{

    int src;
    int dest;
    int weight;
};

struct Graph{

    int v;
    int e;
    int ** adjMat;
//    struct Edge* edge;
};

struct Graph * createGraph(int v, int e){

    struct Graph * graph = (struct Graph *)malloc(sizeof(struct Graph));

    graph->v = v;
    graph->e = e;
   int temp[5][5] =  {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    graph->adjMat = (int **)malloc(sizeof(int)*v);

    assert(graph->adjMat);

    int i,j;
    for(i=0;i<v;i++){
        graph->adjMat[i] = malloc(sizeof(int)*v);
        for(j=0;j<v;j++){
            graph->adjMat[i][j] = temp[i][j];
        }

    }

    return graph;
};

int MinIndex(int visited[],int key[]){

    int i, ans = INT_MAX;
    int index;

    for(i=0;i<5;i++){
        if(!visited[i] && key[i]<ans){
            ans = key[i];
            index = i;
        }
    }
    return index;
}

int MST_Prim(struct Graph *g, int src){

    int * visited =(int *)malloc(g->v * sizeof(int));
    int * parent = (int *) malloc(g->v * sizeof(int));
    int * distanceKey =(int *) malloc(g->v * sizeof(int));
    int  i,j,k;

    for(i=0;i<g->v;i++){
        parent[i]= -1;
        visited[i]= 0;
        distanceKey[i] = INT_MAX;
    }

    distanceKey[0]=0;

    for(i=0;i<g->v;i++){

        k = MinIndex(visited,distanceKey);
        //printf("%d \n",k);
        visited[k]=1;

        for(j=0;j<g->v;j++){
            if(!visited[j] && g->adjMat[k][j] && distanceKey[j]>g->adjMat[k][j]){
                distanceKey[j] = g->adjMat[k][j];
                parent[j] = k;

            }
        }
    }

    printf("MST : \n");
    for(i=1;i<g->v;i++){
        printf("%d -> %d  : %d\n",parent[i],i,g->adjMat[i][parent[i]]);
    }
    int newAdjMat[5][5];// = g->adjMat;
    for(i=0;i<g->v;i++){
            for(j=0;j<g->v;j++){
                newAdjMat[i][j] = 0;
            }

    }

    for(i=1;i<g->v;i++){
          //  printf("%d -> %d  : %d\n",parent[i],i,g->adjMat[i][parent[i]]);
            newAdjMat[parent[i]][i] = g->adjMat[i][parent[i]];
    }

    DFSTraversal(newAdjMat,5,src);
}

int DFSUtil(int adjMat[][5],int visited[],int n,int src){

    int i;
    visited[src] = 1;
    printf("%d ->",src);
    for(i=0;i<n;i++){
        if(!visited[i] && adjMat[src][i]){
          DFSUtil(adjMat,visited,n,i);
        }
    }
}

int DFSTraversal(int newAdjMat[][5], int n, int s){

    int visited[n],i;

    for(i=0;i<n;i++){
        visited[i]=0;
    }

    for(i=0;i<n;i++){
        if(!visited[i]){
            DFSUtil(newAdjMat,visited,n,i);
        }
    }

}

int main()
{
    struct Graph * g = createGraph(5,5);
    MST_Prim(g,0);
    return 0;
}
