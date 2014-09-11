#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define Vertex 5


int Swap(int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;
}

int MinIndex(int minVal[], int visited[]){
    int i, minIndex, min = INT_MAX;

    for(i=0;i<Vertex;i++){

        if((!visited[i])&&(minVal[i]<min)){
            min = minVal[i];
            minIndex = i;
        }
    }
    return minIndex;
}

void printCost(int cost[], int src){

    int k;
    printf("Sorce Node : %d\n",src);
    for(k=0;k<Vertex;k++){
        printf("%d => %d\n",k,cost[k]);
    }
}

int DijkstraAlgo(int graph[][Vertex], int start){

    int minVal[Vertex];
    int visited[Vertex];
    int i;

    for(i=0;i<Vertex; i++){
       visited[i]=0;
       minVal[i] = INT_MAX;

    }
    int u,v;

    minVal[start] = 0;

    for(u=0;u<Vertex;u++){
        int uTemp =  MinIndex(minVal,visited);
        //printf("min cal %d node %d\n",uTemp, minVal[uTemp]);
        visited[uTemp] = 1;
        for(v=0;v<Vertex;v++){
            if((!visited[v]) && (graph[uTemp][v] >0)&& (minVal[v] > minVal[uTemp] + graph[uTemp][v] )){
                    minVal[v] = minVal[uTemp] + graph[uTemp][v];
                    printf("Updating %d : %d\n",v,minVal[v]);

            }
        }
    }


    printCost(minVal,start);

}

int AllPairShortestPath(int graph[][Vertex]){

    int i =0;

    for(i=0;i<Vertex;i++){
        DijkstraAlgo(graph,i);
        printf("\n\n");
  }
}
int main()
{
    //printf("Hello world!\n");
     int graph[Vertex][Vertex]
                    = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    AllPairShortestPath(graph);
    return 0;
}
