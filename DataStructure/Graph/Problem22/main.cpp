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
		adj[v].push_back(u);
	}

	void BFS(int start){

		int visited[v];// = {0};
		int inQueue[v]; // Check weather element was in queue or not
                        // It will help in us to not to push same element two time in queue., and hence no cycle possiblity
		for(int i=0;i<v;i++)
		{
			visited[i]=0;
			inQueue[i] = 0;
		}

		list<int> queue;

		list<int>::iterator i;
		queue.push_back(start);
		inQueue[start] = 1;
		int u,v;

		while(!queue.empty()){

			u = queue.front();
            queue.pop_front();

			visited[u]=1;
//			cout<<"Visited Node "<<u<<endl;

			for( i = adj[u].begin();i!=adj[u].end();i++){
				if(!visited[*i] && !inQueue[*i])
                {
					queue.push_back(*i);
                    cout<<"Visited Edge: "<<u << " "<<*i<<endl;
					inQueue[*i] = 1;
				}
			}
		}

	}

};


int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);

    return 0;
}
