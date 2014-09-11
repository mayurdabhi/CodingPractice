#include <iostream>

using namespace std;

int operation(long int A[],int B[], int C[], int M, int N){

  for(int i = 1;i<=M;i++){

    C[i] = C[i]%(1000000007);
   // for(int j = B[i];j<= N;)
    {
        //if(j % B[i] == 0 )
        {
           // A[j] = A[j]%(1000000007);
            A[j] = A[j] * C[i] * (N/B[i]);
            A[j] = A[j]%(1000000007);
            j = j+B[i];
//            cout<<"A["<<j<<"]"<<A[j]<<endl;
        }
    //    else{
          //  j++;
       // }
    }

  }
    return 0;
}


int main()
{

    int n,m,b[100001],c[100001];
    long int a[100001];

    cin>>n;
    cin>>m;

    int ans = 0;
    for(int i=1;i<=n;i++){
            cin>>a[i];//%(1000000007);
    }

    for(int i=1;i<=m;i++){
            cin>>b[i];
    }

    for(int i=1;i<=m;i++){
            cin>>c[i];//%(1000000007);
    }

    operation(a,b,c,m,n);
    int i;
    for(i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}
