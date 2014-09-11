#include <stdio.h>
#include <stdlib.h>

#define V 5

int isSafe(int graph[][V],int colour[], int current, int v){

    int u;

    for(u=0;u<V;u++){
        //Checking any adjacent node has same colour
        if(graph[v][u] && current == colour[u]){// && u!=v){
            return 0;
        }
    }
    return 1;
}

int mColouringProb(int graph[][V],int m, int src){

    int i,colour[V];

    for(i=0;i<V;i++){
        colour[i]=-1;
    }

    int c = ColouringUtil(graph,colour,m,src);

    (c)?printf("yes\n"):printf("no\n");

}

int ColouringUtil(int graph[][V],int colour[],int m, int v)
{

     if(v==V){
        return 1;
     }
     else{
        int c;
        for(c=1;c<=m;c++){
                //Check current colour is safe to assign
            if(isSafe(graph,colour,c,v))
            {
                colour[v] = c;
                //check all its decendent node also able to get colour safely
                if(ColouringUtil(graph,colour,m,v+1)==1){
                    return 1;
                }

                //if not then check for new colour

                colour[v] = 0;
            }
        }
        //all colour checked still not possible then graph is not able to colour with m colour
        return 0;
     }
}

int main()
{
      /* Create following graph and test whether it is 3 colorable
      (3)---(2)
       |   / |
       |  /  |
       | /   |
      (0)---(1)
    */
    int graph[V][V] = {{0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 1, 1, 0},
    };

    mColouringProb(graph,4,0);
    return 0;
}
