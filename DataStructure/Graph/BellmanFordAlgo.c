/*
Input :

8 8
0 1
1 2
2 3
1 6
2 4
4 5
4 7

*/

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 1000

struct graph {

    int v;
    int e;
	int **adj;
};

struct graph* createGraph(){

	struct graph * g = (struct graph *) malloc(sizeof(struct graph));

	if(!g){
		printf("Memory Error\n");
	}

    printf("Enter Vertices and Edges :");
	scanf("%d %d",&g->v, &g->e);

 //   scanf("Enter Vertices and Edges :%d %d",&g->v, &g->e);

	int** a = malloc(g->v * sizeof(int*));
    int k,l;
    for (k = 0; k < g->v; k++) {
        a[k] = calloc(g->v , sizeof(int));
        for(l=0;l<g->v;l++){
            a[k][l] = INT_MAX;
        }
    }

    g->adj = a;

	if(!g->adj){
		printf("Memory Error\n");
	}

	int v,u,j,weight;


	/*
	//normal BFS DFS traversal
	for(j=0;j<g->e;j++){

		printf("Enter Edges :\n");
		scanf("%d %d", &v,&u);
    //    scanf("Enter Edges :%d %d", &v,&u);
		g->adj[v][u] = 1;
		g->adj[u][v] =1;
	}
	*/
	//To assign weight to each edge

    printf("Enter Edges :\n");
	for(j=0;j<g->e;j++){

		scanf("%d %d %d", &v,&u,&weight);
		g->adj[v][u] = weight;

	}



	return g;

}


int visited[20]={0};

void DFS(struct graph *g, int vertex){

	visited[vertex]=1;
	printf("Visiting node %d \n",vertex);
	int v,u,i;
	v= vertex;

	for(u=0;u<g->v;u++)
	{
		if(!visited[u] && g->adj[v][u]){

			DFS(g,u);

		}
	}

}

void DFSTraversal(struct graph *g){
	int u;
	for(u=0;u<g->v;u++)
	{
		visited[u]=0;
	}

	for(u=0;u<g->v;u++)
	{
		if(!visited[u])
			DFS(g,u);
	}

}

int BellmanFordAlgorithm(struct graph* g,int start){

    int v = g->v;
    int e = g->e;

    int i,j, node, srcNode,destNode;
    int* distance = malloc(sizeof(int)*v);

    for(i=0;i<v;i++){

            distance[i] = INT_MAX;

    }



    distance[start] = 0;

    for(node=0;node<v;node++){

        for(srcNode=0;srcNode<v;srcNode++){

            for(destNode=0;destNode<v;destNode++){
                if(g->adj[srcNode][destNode]!=INT_MAX){
                    if(distance[srcNode]+g->adj[srcNode][destNode] < distance[destNode]){
                        distance[destNode] = distance[srcNode]+g->adj[srcNode][destNode];
                    }
                }
            }
        }

    }


        for(srcNode=0;srcNode<v;srcNode++){

            for(destNode=0;destNode<v;destNode++){
                if(distance[node]!=INT_MAX){
                    if(distance[srcNode]+g->adj[srcNode][destNode] < distance[destNode]){
                            printf("NegativeEdge Exist : Cycle\n");
                            return;
                    }
                }
            }
        }

        for ( i = 0; i < v; i++)
        {
              printf("distance of source  %d to %d is %d",start, i, distance[i]);

        }

}



int main(){

	struct graph* gTest = createGraph();
	DFSTraversal(gTest);
    BellmanFordAlgorithm(gTest,1);
return 0;
}
