#include <stdio.h>
#include <stdlib.h>

#define Vertex 5

int low[Vertex];
int num=0;
int dfsnum[Vertex];



int minimum(int a,int b){
    return (a<b)?a:b;
}
void CutVertices(int adjMat[][Vertex],int u){
    low[u]=dfsnum[u]= num++;
    int v;

    for (v=0;v<Vertex;v++){
        if(adjMat[u][v] && dfsnum[v]== -1){
            CutVertices(adjMat,v);
            if(low[v]>dfsnum[u]){
                printf("CutVertex %d\n",u);
            }
            low[u]=minimum(low[v],low[u]);
        }
        else{
            low[u] = minimum(low[u],dfsnum[v]);
        }
    }
}

int main()
{
//    printf("Hello world!\n");
    int graph[Vertex][Vertex]
                    = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 0, 0},
                      {0, 3, 0, 0, 0},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    //memset(dfsnum,-1,Vertex);
    int i;
    for(i=0;i<Vertex;i++){
        dfsnum[i]= -1;
//        low[i]=10; //max possible value
    }
    CutVertices(graph,0);
    return 0;
}
