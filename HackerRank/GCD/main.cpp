#include <iostream>

using namespace std;

int GCD(int a,int b){
    int m;
    while (b != 0)
    {
        int m = a % b;
        a = b;
        b = m;
    }
    return a;
}


int main()
{

    int t,n,a[100000];

    cin>>t;

    int ans = 0;
    for(int i=0;i<t;i++){
            cin>>n;
            cin>>a[0];
            ans = a[0];
        for(int j=1;j<n;j++){
            cin>>a[j];
            if(ans<2){
                continue;
            }
            else{
                ans = GCD(ans,a[j]);
            }
        }

        if(ans>1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }

    }

    return 0;
}
