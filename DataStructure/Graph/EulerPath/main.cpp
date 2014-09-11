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
		//adj[v].push_back(u);
	}

    void DFS(int visited[],int start){

        visited[start]=1;


        list<int>::iterator i;
        for(i=adj[start].begin();i!=adj[start].end();i++){

            if(!visited[*i]){
                DFS(visited,*i);
            }
        }
    }

    bool isConnected(){

        int visited[v], i;

        for(i=0;i<v;i++){
            visited[i] = 0;
        }

        for(i=0;i<v;i++){

            if(adj[i].size()!=0){
               // DFS(visited,i);

                break;
            }
        }

        if(i==v){
            return true;
        }

        DFS(visited,i);

        for(i=0;i<v;i++){
            if(visited[i]==0 && adj[i].size()>0){
                return false;
            }
        }

        return true;
    }

    int isEulerian(){

        if(isConnected()==false){
            return 0;
        }

        int odd=0;

        for(int i=0;i<v;i++){
            if(adj[i].size() & 1){
                odd++;

                /*
                list<int>::iterator i1;
                for(i1=adj[i].begin();i1!=adj[i].end();i1++){
                    cout<<i<<":"<<*i1<<endl;

                }
                cout <<endl;
                */
            }
        }

        if(odd>2){
            return 0;
        }

        if(odd==1){
            return 0;
        }
        return (odd)?1:2;
    }

    void testEulerian(){

        int i = isEulerian();

        if(i==0){
            cout<<"Not a Eulerian"<<endl;
        }
        else if(i==1){
            cout<<"Eulerian Path"<<endl;
        }
        else{
            cout<<"Eulerian Cycle"<<endl;
        }
    }

	void BFS(int start){

		int visited[v];// = {0};

		for(int i=0;i<v;i++)
		{
			visited[i]=0;
		}

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
    g.testEulerian();

    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.testEulerian();

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
 /*
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
   */

    return 0;
}
