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

        void ShortestPath(int start)
        {

            int distance[v];// = {0};
            int path[v];
            for(int i=0;i<v;i++)
            {
                distance[i]=-1;
            }


            list<int> queue;
            list<int>::iterator i;
            int u,v;

            queue.push_back(start);
            distance[start]=0;
              path[start]=start;
            while(!queue.empty()){

                u = queue.front();
                queue.pop_front();



                for( i = adj[u].begin();i!=adj[u].end();i++){
                        if(distance[*i] == -1){
                            distance[*i] = distance[u] + 1;
                            queue.push_back(*i);
                        }
                    }
            }

            for(int i=0;i<this->v;i++){

                cout<<"From : "<<start<< " To : "<<i <<"==> "<< distance[i]<<endl;

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
   g.ShortestPath(2);

   return 0;
}
