#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>

//Number of Vertices
#define Vertex 5

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

int primsAlgo(int adjMat[][Vertex])
{

    int visited[Vertex] = {0};
    int parent[Vertex] ;
    int key[Vertex]; // contains min weight from all adjacent edges from v vertex

    int u,v, uTemp;

    for(u=0;u<Vertex-1;u++){
        //parent[u] = -1;
        key[u] = INT_MAX;
    }


    key[0]= 0;
    parent[0] = -1;
    int path[Vertex] ;

    for(uTemp=0;uTemp<Vertex-1;uTemp++){

        //as minIndex operation takes O(n) time u can reduce it to O(1) ,
        //by using maxHeas but it will take time to create heap every time
        u = minIndex(key,visited);

        visited[u] =1;

        for(v=0;v<Vertex;v++){
            if((!visited[v]) && adjMat[u][v] && adjMat[u][v]<key[v])
            {
                key[v]=adjMat[u][v];
                parent[v] = u;
            }
        }
    }

    printGraph(parent,adjMat);
}

int printGraph(int parent[],int dist[][Vertex]){

    int i;
    for(i=1;i<Vertex;i++){
        printf("%d -> %d  : %d\n",parent[i],i,dist[i][parent[i]]);
    }

}

int main()
{

    /* Let us create the following graph
          2    3
      (0)--(1)--(2)
       |   / \   |
      6| 8/   \5 |7
       | /     \ |
      (3)-------(4)
            9          */
   int graph[Vertex][Vertex]
                    = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0},
                     };

    // Print the solution
    primsAlgo(graph);

}
