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
//		adj[v].push_back(u);
	}

    int Depth(){

       int visited[v];// = {0};
        int ans = 0,max=0;
		for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}


		for(int i=0;i<v;i++)
		{
			if(!visited[i]){
                ans = DepthUtil(visited,i);
                if(ans>max){
                    max=ans;
                }
			}

		}

		cout<<"Max Depth"<<max-1<<endl;
		return max;
    }

	int DepthUtil(int visited[],int start){

		list<int> queue;
		list<int>::iterator i;
		queue.push_back(start);
		queue.push_back(-1);
		int u,v,level=0;

		while(!queue.empty()){

			u = queue.front();
          	queue.pop_front();

            if(u==-1){
                level++;

                if(!queue.empty()){
                    queue.push_back(-1);
                }
            }
            else{
                visited[u]=1;
                cout<<"Visited Node "<<u<<endl;

                for( i = adj[u].begin();i!=adj[u].end();i++){
                    if(visited[*i] == 0){
                        queue.push_back(*i);
                    }
                }
            }
		}

        cout<<"Levels : "<<level<<endl;
        return level;
	}

};


int main()
{
    //Directed Graph
    // Create a graph given in the above diagram

    Graph g1(9);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.addEdge(7, 8);
    g1.addEdge(8, 6);
    g1.addEdge(6, 5);

    g1.Depth();
 /*
    Graph g2(5);
    g2.addEdge(1, 0);
    g2.addEdge(0, 2);
    g2.addEdge(2, 1);
    g2.addEdge(0, 3);
    g2.addEdge(3, 4);
    g2.addEdge(4, 0);
    g2.testEulerian();

    Graph g3(5);
    g3.addEdge(1, 0);
    g3.addEdge(0, 2);
    g3.addEdge(2, 1);
    g3.addEdge(0, 3);
    g3.addEdge(3, 4);
    g3.addEdge(1, 3);
    g3.testEulerian();

    // Let us create a graph with 3 vertices
    // connected in the form of cycle
    Graph g4(3);
    g4.addEdge(0, 1);
    g4.addEdge(1, 2);
    g4.addEdge(2, 0);
    g4.testEulerian();

    // Let us create a graph with all veritces
    // with zero degree
    Graph g5(3);
    g5.testEulerian();

    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
   */

    return 0;
}
