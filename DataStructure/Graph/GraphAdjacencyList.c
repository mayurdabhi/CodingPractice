#include <stdio.h>
#include <stdlib.h>


struct ListNode{

	int key;
	struct ListNode * next;
};

struct adjList{

	struct ListNode * head;
};

struct Queue {
     int size;
     struct ListNode* front;
     struct ListNode* rear;
};

int isQueueEmpty(struct Queue * q){

    if(q->front==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

struct Queue* createQueue()
{
    struct Queue* q =  (struct Queue *)malloc(sizeof(struct Queue));

    q->size = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
};

void EnQueue(struct Queue *q, struct ListNode *newNode){


    if(q->rear != NULL)
        newNode->next = q->rear->next;
    else
    {
        newNode->next = NULL;
    }
    q->rear = newNode;
    q->size +=1;
    if(isQueueEmpty(q)){
        q->front = q->rear;
        q->size =1;
    }

}

struct ListNode* DeQueue(struct Queue *q){

    struct ListNode * temp = q->front;

    if(q->front!=NULL)
    {
        q->front = q->front->next;
        q->size -=1;
    }
    else{
        q->size = 0;
    }
   // temp->next = NULL;
    return temp;
}


struct Graph{

	int v;
	struct adjList* array;
};


struct Graph* CreateGraph(int vertex){

	struct Graph* g = (struct Graph *) malloc(sizeof(struct Graph));

	if(!g){
		printf("Memory Error\n");
	}

	int i;

	g->v = vertex;

	g->array = (struct adjList*)malloc(vertex * sizeof(struct adjList));

	for(i=0;i<vertex;i++){

		//Look how the value is assigned
		g->array[i].head = NULL;

	}

	return g;

}

struct ListNode *  createListNode(int data){

	struct ListNode * newNode = (struct ListNode *)malloc(sizeof(struct ListNode));

	newNode->key = data;
	newNode->next = NULL;

	return newNode;


}

void printList(struct ListNode * head){

	struct ListNode* temp= head;

	while(temp){
		printf("%d ->",temp->key);
		temp = temp->next;
	}
	printf("\n");

}

void printGraph(struct Graph *g){

	int i;
	for(i=0;i<g->v;i++){

		printf("Adjacency List for %d :\n ",i);
		printList(g->array[i].head);

	}
}

int addEdge(struct Graph * g, int src, int dest)
{

	//for undirectional graph add node to both list;

	struct ListNode * destNode = createListNode(dest);

	destNode->next = g->array[src].head;
	g->array[src].head = destNode;

	struct ListNode * srcNode = createListNode(src);

	srcNode->next = g->array[dest].head;
	g->array[dest].head = srcNode;

}

void BFSTraversal(struct Graph *g , int start){

        int* visited = malloc((g->v)*sizeof(int));
        int i,j;

        for(i=0;i<g->v;i++){

                visited[i] =0;
        }

        struct Queue* q =  createQueue();

        EnQueue(q,createListNode(start));

        while(!isQueueEmpty(q)){
            struct ListNode *temp= DeQueue(q);
            int index = temp->key;
            visited[index] =1;
            struct ListNode *itr = g->array[index].head;
            printf("Visiting Node : %d\n",index);
            while(itr){

                index = itr->key;
                //    printf("Visiting Node 11: %d\n",index);
                if(visited[index] == 0){
                    EnQueue(q,itr);//temp->next);
                }
                itr = itr->next;
            }
        }
}

int main(){


	struct Graph* graph = CreateGraph(5);

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

    // print the adjacency list representation of the above graph
    printGraph(graph);
    BFSTraversal(graph,0);

	return 0;
}
