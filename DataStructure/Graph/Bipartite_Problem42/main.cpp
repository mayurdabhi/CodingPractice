
#include <iostream>
#include<queue>

using namespace std;

#define V 5

bool checkBipartite(int adjMat[][V],int src){

    int u,v,i,colour[V];

    for(i=0;i<V;i++){
        colour[i] = -1;
    }

    queue<int> q;
    colour[src] = 1;
    q.push(src);

    while(!q.empty()){

        u=q.front();
        q.pop();

        for(v = 0; v< V; v++){
            if(adjMat[u][v] && colour[v] == -1){
                colour[v] = 1- colour[u];
                q.push(v);
            }
            else if(adjMat[u][v] && colour[u]==colour[v]){
                return false;
            }
        }
    }
    return true;

}
int main()
{
    int G[][V] = {{0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };

    checkBipartite(G, 0) ? cout << "Yes" : cout << "No";
    return 0;
    return 0;
}
