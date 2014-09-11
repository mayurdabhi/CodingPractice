#include <iostream>
#include <stack>
#include <list>

using namespace std;

class Graph{


private:
	int v;
	list<int> *adj;

public:

	Graph(int v){
		this->v= v;
		adj = new list<int>[v];
	}

	void addEdge(int u, int v){

		adj[u].push_back(v);
	}

	void DFSUtil(int v, int visited[], stack<int> &Stack){

		visited[v]= 1	;
		list<int>::iterator i;


		for(i = adj[v].begin();i!=adj[v].end();i++){

			if(visited[*i] == 0){
				DFSUtil(*i,visited,Stack);
			}
		}
		Stack.push(v);
	}

	void topologicalSort(){

		int visited[this->v];
		stack<int> Stack;

		for(int i=0;i<this->v;i++){
			visited[i]=0;
		}

		for(int i=0;i<this->v;i++){

                if(visited[i]==0){
                    DFSUtil(i,visited,Stack);
                }

		}

		cout<<"Topological Sort"<<endl;

		while(!Stack.empty()){
			cout<<Stack.top()<<" ";
			Stack.pop();
		}
		cout<<endl;

	}
};


int main()
{
     Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout << "Following is a Topological Sort of the given graph \n";
    g.topologicalSort();

    return 0;

}
