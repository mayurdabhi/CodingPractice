#include <stdio.h>
#include <stdlib.h>

#include <assert.h>


struct edge {

    int src, dest;
    int weight;
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

    if(subsets[x].parent == x){
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


int compareElem(const void *a, const void *b){

    struct edge *a1 =  (struct edge *)a;
    struct edge *b1 =  (struct edge *)b;

    return (a1->weight - b1->weight);
}

int printMST(struct edge *path, int vertex){
    int i=0;

    for(i=0;i<vertex-1;i++){
        printf("Edge : %d -> %d : %d\n",path[i].src,path[i].dest,path[i].weight);
    }
}
int kruskalAlgo(struct graph *g){

    int v = g->v;
 //   int e = g->e;
    int i;
    struct subset *subsets = (struct subset*)malloc(v*sizeof(struct subset));
    struct edge *path = (struct edge *)malloc((v-1)*sizeof(struct edge));

    qsort(g->edges, g->e,sizeof(g->edges[0]),compareElem);

    for(i=0;i<g->e;i++){
        printf("Edge : %d -> %d : %d\n",g->edges[i].src,g->edges[i].dest,g->edges[i].weight);
    }
    for(i=0;i<v;i++){
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }
    int e=0;
     i=0;

    while(e<v-1)
    {
        struct edge nextEdge = g->edges[i++];
        int x = Find(subsets,nextEdge.src);
        int y = Find(subsets,nextEdge.dest);

        if(x!=y){
             Union(subsets,x,y);
             path[e++] = nextEdge;
        }
    }
    printf("\nMinimum Spanning Tree : \n");
    printMST(path,v);
    return 0;
}

int main()
{
    int V = 4, E = 5;
    struct graph* graph = createGraph(V, E);

   // add edge 0-1
    graph->edges[0].src = 0;
    graph->edges[0].dest = 1;
    graph->edges[0].weight = 10;

    // add edge 0-2
    graph->edges[1].src = 0;
    graph->edges[1].dest = 2;
    graph->edges[1].weight = 6;

    // add edge 0-3
    graph->edges[2].src = 0;
    graph->edges[2].dest = 3;
    graph->edges[2].weight = 5;

    // add edge 1-3
    graph->edges[3].src = 1;
    graph->edges[3].dest = 3;
    graph->edges[3].weight = 15;

    // add edge 2-3
    graph->edges[4].src = 2;
    graph->edges[4].dest = 3;
    graph->edges[4].weight = 4;

    kruskalAlgo(graph);

    return 0;
}
