#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

//Number of Vertices
#define Vertex 9

int minIndex(int dist[], int visited[]){

    int minDist=INT_MAX,ans,i;

    ans = 0;
    for(i=0;i<Vertex;i++){
        if((!visited[i]) && (dist[i]<minDist)){
            ans =i;
            minDist=dist[i];
        }
    }
    return ans;
}




//Dijkstra Algorithm with Adjacency list

int DijkstraAlgorithm(int adjMat[][Vertex], int start)
{

    int visited[Vertex] = {0};
    int distance[Vertex] ;
    int u,v, uTemp;

    for(u=0;u<Vertex-1;u++){
        distance[u] = INT_MAX;
    }

    distance[start] = 0;
    int path[Vertex] ;

    for(uTemp=0;uTemp<Vertex;uTemp++){

        //as minIndex operation takes O(n) time u can reduce it to O(1) ,
        //by using maxHeap but it will take time to create heap every time
        u = minIndex(distance,visited);

        visited[u]=1;
        path[uTemp] = u;
        for(v=0;v<Vertex;v++){
            if((!visited[v]) && adjMat[u][v] && (distance[u]+adjMat[u][v]<distance[v]))
            {
                distance[v] = distance[u]+adjMat[u][v];
            }
        }
    }

    printGraph(path,distance);
}

int printGraph(int path[],int dist[]){

    int i;
    for(i=0;i<Vertex;i++){
        printf("%d : %d\n",path[i],dist[path[i]]);
    }
    printf("\n\n");//,dist[path[i-1]]);
}

int main()
{

   int graph[Vertex][Vertex] = {  {0, 4, 0, 0, 0, 0, 0, 8, 0},
                                  {4, 0, 8, 0, 0, 0, 0, 11, 0},
                                  {0, 8, 0, 7, 0, 4, 0, 0, 2},
                                  {0, 0, 7, 0, 9, 14, 0, 0, 0},
                                  {0, 0, 0, 9, 0, 10, 0, 0, 0},
                                  {0, 0, 4, 0, 10, 0, 2, 0, 0},
                                  {0, 0, 0, 14, 0, 2, 0, 1, 6},
                                  {8, 11, 0, 0, 0, 0, 1, 0, 7},
                                  {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    DijkstraAlgorithm(graph, 0);

}
