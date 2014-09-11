#include <iostream>
#include <list>

using namespace std;

class Graph{

    private :
	int v;
	list<int> *adj;
	//std::map<int,int> mySal;
	int *mySal;
	Graph * gTrans;
	public:

	Graph(int ind){

		v= ind;
		mySal = new int [v+1];
		adj = new list<int>[v+1];
		/*
		for(i=0;i<=v;i++){
            mySal[i]=0;
		}
		*/
	}

	void addEdge(int u, int v1){

		adj[u].push_back(v1);
	//	gTrans->adj[v1].push_back(u);
	}

    void addSalary(int u, int s){

        mySal[u]=s;

    }

	void DFS_Sal(int visited[],int u, int inc){

        list<int>::iterator i;
        visited[u]=1;
        mySal[u] += inc;
/*
        if(*flag && mySal[u]>pSal){
            *flag=0;
        }
        */
//        cout<<"DSF SAL visiting flag "<<*flag<<" "<<u << "Sal " <<mySal[u]<<" " <<inc<<endl;
        for(i = adj[u].begin();i!=adj[u].end();i++){
            if(visited[*i] == 0){
               DFS_Sal(visited,*i,inc);//,mySal[u],flag);
            }
        }
	}

	int DFS_Chk( int visited[],int u, int pSal){

        visited[u]=1;
//        cout<<"visiting "<<u << "Sal " <<mySal[u]<<" " <<pSal<<endl;
        if(mySal[u]>=pSal){
            return 0;
        }
        list<int>::iterator i;
        for(i = adj[u].begin();i!=adj[u].end();i++){
            if(visited[*i] == 0){
               if(DFS_Chk(visited,*i,mySal[u])==0){
                    return 0;
               }
            }
        }

        return 1;
	}

    void getTranspose()
    {
        gTrans = new Graph(v);
/*        for (int v1 = 0; v1 < v; v1++)
        {
            // Recur for all the vertices adjacent to this vertex
            list<int>::iterator i;
            for(i = adj[v1].begin(); i != adj[v1].end(); ++i)
            {
                gTrans->adj[*i].push_back(v1);
            }
        }
*/      //  return gTrans;
    }

    int PerformCheck(int start){

       	int visited[v+1];// = {0};

		for(int i=0;i<=v;i++)
		{
			visited[i]=0;
		}
        visited[0]=1;
        return DFS_Chk(visited,start,mySal[start]+1);

    }

    int PerformOperation(int parent, int increment){


       	int visited[v+1];// = {0};

		for(int i=0;i<=v;i++)
		{
			visited[i]=0;
		}
        visited[0]=1;
  //      int flag=1;
//        int pSal=mySal[parent]+increment;
        DFS_Sal(visited,parent,increment);

        int ans = -1;
/*
        if(flag==0){
            cout<<"BAD"<<endl;
            return 0;
        }*/
    //    if(parent==1){
        ans = PerformCheck(1);
      //  }
        //else{
          //ans = PerformCheck(gTrans,parent);
       // }
        //cout<<ans;
        if(ans==1){
            cout<<"GOOD"<<endl;
        }
        else{
            cout<<"BAD"<<endl;
        }
        return 1;
    }


};


int main()
{
    // Create a graph given in the above diagram

    int N,Q,p,sal,e,v;

    cin>>N;
    cin>>Q;

    Graph g(N);

//    g.getTranspose();
    for(int k=2;k<=N;k++){
        cin>>p;
        g.addEdge(p,k);
    }

    for(int k=1;k<=N;k++){
        cin>>sal;
        g.addSalary(k,sal);
    }


    for(int k=1;k<=Q;k++){
        cin>>e;
        cin>>v;
      //  cout << e << " "<< v<<endl;
        g.PerformOperation(e,v);
    }

    return 0;
}
