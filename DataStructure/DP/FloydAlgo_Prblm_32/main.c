#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define N 4
#define INF INT_MAX

int MIN(int a,int b){

    return (a<b)?a:b;
}

int printPath(int path[][N], int trace[][N], int i, int j){

    while(trace[i][j]>0){

        int k = trace[i][j]-1;
           printf("%d -> %d\n", i,j);
        if(k<0){
            return 0;
        }
        if(path[i][k]<=path[k][j] && path[i][k]){
            i=k;
        }
        else{
            j=k;
        }
    }
    printf("%d -> %d\n", i,j);
}

int FloydAlgo(int path[][N], int n){

    int shortestPath[N][N], trackPath[N][N];
    int i,j,k,temp;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            shortestPath[i][j] = path[i][j];
            trackPath[i][j] = 0;
        }
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                temp = path[i][j];
                path[i][j] = MIN(path[i][j], path[i][k]+path[k][j]);
                if(path[i][j]<0){
                    path[i][j] = temp;
                }
                else if(temp!=path[i][j]){
                    trackPath[i][j] = k+1;
                }
            }
        }
    }

    printf("\n");

     for(i=0;i<n;i++){
        for(j=0;j<n;j++){

                printf("%d ",path[i][j]);
        }
        printf("%d\n");
    }

printf("\n");
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){

                printf("%d ",trackPath[i][j]);
        }
        printf("%d\n");
    }
    printPath(path,trackPath,0,2);
}


int main()
{
      int graph[N][N] = { {0,   5,  INF, INF},
                        {50, 0,   15, 5},
                        {30, INF, 0,   15},
                        {15, INF, 5, 0}
                      };
    FloydAlgo(graph,N) ;

    return 0;
}
