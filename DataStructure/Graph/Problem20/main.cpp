#include <iostream>
#include <list>

using namespace std;

class Graph{

    private :
	int v;
	list<int> *adj;
	public:
	Graph(int i){

		v= i;
		adj = new list<int>[v];

	}

	void addEdge(int u, int v){

		adj[u].push_back(v);
	}

	void BFS(int visited[],int start){


		list<int> queue;
		list<int>::iterator i;
		queue.push_back(start);
		int u,v;

		while(!queue.empty()){

			u = queue.front();
          		queue.pop_front();

			visited[u]=1;
			cout<<"Visited Node "<<u<<endl;

			for( i = adj[u].begin();i!=adj[u].end();i++){
				if(visited[*i] == 0){
					queue.push_back(*i);
				}
			}
		}

	}


    int BFSUtil(){

       	int visited[v];// = {0};

		for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}

		int count=0;

		for(int i=0;i<v;i++){
            if(!visited[i]){
                BFS(visited,i);
                count++;
            }
		}
        return count;
    }

    Graph getTranspose()
    {
        Graph g(v);
        for (int v1 = 0; v1 < v; v1++)
        {
            // Recur for all the vertices adjacent to this vertex
            list<int>::iterator i;
            for(i = adj[v1].begin(); i != adj[v1].end(); ++i)
            {
                g.adj[*i].push_back(v1);
            }
        }
        return g;
    }

    void FillOrder(int k, int visited[], list<int> &Stack){

        visited[k] = 1;
        list<int>::iterator itr;
        list<int> Queue;

        Queue.push_back(k);

        while(!Queue.empty()){

            int i = Queue.front();
            Queue.pop_front();
            for(itr = adj[i].begin();itr!=adj[i].end();itr++){
                if(!visited[*itr]){
                        Queue.push_back(*itr);
                }
            }

        }
        Stack.push_back(k);
    }

    int CheckSCC(){

        int visited[v];
        for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}
        list<int> Stack;
		int count=0;

        for(int i=0;i<v;i++)
		{
			if(!visited[i]){
                FillOrder(i,visited,Stack);
			}
		}

        for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}

        Graph gNew = getTranspose();

        while(!Stack.empty()){
            int top = Stack.back();
            Stack.pop_back();
            if(!visited[top])
             {
                 BFS(visited,top);
                 count++;
             }
        }
        return count;
    }
};


int main()
{
    // Create a graph given in the above diagram
   Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(0, 2);
    g.addEdge(2, 1);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout << "Following is Strongly Connected Component using BFS \n";
    cout << g.CheckSCC();

    return 0;
}
