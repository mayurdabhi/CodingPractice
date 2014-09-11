#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


struct edge {

    int src, dest;
};

struct graph{
    int v,e;
    struct edge *edges;
};

int find(int parent[], int x){

    if(parent[x] == -1){
        return x;
    }
    else{
        return find(parent,parent[x]);
    }

}

int Union(int parent[], int x, int y){

       int xset = find(parent,x) ;
       int yset = find(parent,y);
       parent[xset] = yset;

}

struct graph * createGraph(int v, int e){

       struct graph* g  = (struct graph*)malloc(sizeof(struct graph));

       assert(g);

       g->v = v;
       g->e = e;
       g->edges = (struct edge *)malloc(e*sizeof(struct edge));

       assert(g->edges);

       return g;
};


int isCycle(struct graph* g )
{

    assert(g);

    int* parent   = (int *)malloc(g->v * sizeof(int));
    int size,i;

    //
    memset(parent,-1,g->v*sizeof(int));



    for(i=0;i<g->e;i++){
        int x =find(parent,g->edges[i].src);
        int y =find(parent,g->edges[i].dest);

        if(x==y){
            return 1;
        }

        Union(parent,x,y);
    }

    return 0;
}


int main()
{
     /* Let us create following graph
         0
        |  \
        |    \
        1-----2 */
    struct graph* graph = createGraph(3, 3);

    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    // add edge 1-2
    graph->edges[1].src = 1;
    graph->edges[1].dest = 2;

    // add edge 0-2
    graph->edges[2].src = 0;
    graph->edges[2].dest = 2;

    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );

    return 0;

}
