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

struct subset {
    int parent;
    int rank;

};


int Find(struct subset *subsets, int x){

    if(subsets[x].parent == -1){
        return x;
    }
    else{
        subsets[x].parent =  Find(subsets,subsets[x].parent);
    }
    return subsets[x].parent;

}

int Union(struct subset * subsets, int x, int y){

       int xset = Find(subsets,x) ;
       int yset = Find(subsets,y);

       //smaller ranked tree rooted with higher ranked tree
       if(subsets[xset].rank > subsets[yset].rank){
            subsets[yset].parent = xset;
       }
       else if(subsets[xset].rank < subsets[yset].rank){
           subsets[xset].parent = yset;
        }
        else{
            subsets[yset].parent = xset;
            subsets[xset].rank++;
        }
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


int isCycle(struct graph *g){

    int v = g->v;
    int e = g->e;
    int i;
    struct subset *subsets = (struct subset*)malloc(v*sizeof(struct subset));

    for(i=0;i<v;i++){
        subsets[i].parent = -1;
        subsets[i].rank = 0;
    }

    for(i=0;i<e;i++){
        int x = Find(subsets,g->edges[i].src);
        int y = Find(subsets,g->edges[i].dest);

        if(x==y){
            return 1;
        }

        Union(subsets,x,y);
    }
    return 0;
}

int main()
{
    int V = 3, E = 3;
    struct graph* graph = createGraph(V, E-1);

    // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;

    // add edge 1-2
    graph->edges[1].src = 1;
    graph->edges[1].dest = 2;

    // add edge 0-2
 //   graph->edges[2].src = 0;
   // graph->edges[2].dest = 2;

    if (isCycle(graph))
        printf( "Graph contains cycle" );
    else
        printf( "Graph doesn't contain cycle" );

    return 0;
}
