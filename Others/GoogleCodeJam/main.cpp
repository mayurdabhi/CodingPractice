#include <iostream>

using namespace std;

#define N 20

void process2014(int a[][N], int n, string dir, int testcase){

    if(dir=="right"){

        for(int i=n-1;i>=0;i--){
            int cur=n-1;
            int ans;
            for(int j=n-1;j>=0 && cur>=0;){

                if(a[i][j]==0){
                    j--;
                }
                else{
                    a[i][cur--]=a[i][j--];
                }
            }

            while(cur>=0){
                a[i][cur--]=0;
            }

            ans=n-1;
            cur=n-1;
            for(int j=n-1;j>=0 && cur>=0;j--){

                if(cur>0&&a[i][cur]==a[i][cur-1]){
                    a[i][ans--]=a[i][cur]+a[i][cur-1];
                    cur= cur-2;
                }
                else if(cur>0&&a[i][cur]!=a[i][cur-1]){
                    a[i][ans--]=a[i][cur];
                    a[i][ans]=a[i][cur-1];
                    cur--;
                }
                else if(cur==0 && cur+1==ans){
                    a[i][ans--] = a[i][cur];
                }
            }
            while(ans>=0){
                a[i][ans--]=0;
            }
        }
    }
    else if(dir=="down")
    {

        for(int i=n-1;i>=0;i--){
            int cur=n-1;
            int ans;
            for(int j=n-1;j>=0 && cur>=0;){

                if(a[j][i]==0){
                    j--;
                }
                else{
                    a[cur--][i]=a[j--][i];
                }
            }

            while(cur>=0){
                a[cur--][i]=0;
            }
            ans=n-1;
            cur=n-1;
            for(int j=n-1;j>=0 && cur>=0;j--){

                if(cur>0&&a[cur][i]==a[cur-1][i]){
                    a[ans--][i]=a[cur][i]+a[cur-1][i];
                    cur= cur-2;
                }
                else if(cur>0&&a[cur][i]!=a[cur-1][i]){
                    a[ans--][i]=a[cur][i];
                    a[ans][i]=a[cur-1][i];
                    cur--;
                }
                else if(cur==0 && cur+1==ans){
                    a[ans--][i] = a[cur][i];
                }
            }
            while(ans>=0){
                a[ans--][i]=0;
            }
        }
    }
    else if(dir=="left"){

        for(int i=0;i<n;i++){
            int cur=0;
            int ans;
            for(int j=0;j<n && cur<n;){

                if(a[i][j]==0){
                    j++;
                }
                else{
                    a[i][cur++]=a[i][j++];
                }
            }

            while(cur<n){
                a[i][cur++]=0;
            }

            ans=0;
            cur=0;
            for(int j=0;j<n && cur<n;j--){

                if(cur<n-1 &&a[i][cur]==a[i][cur+1]){
                    a[i][ans++]=a[i][cur]+a[i][cur+1];
                    cur= cur+2;
                }
                else if(cur<n-1 &&a[i][cur]!=a[i][cur+1]){
                    a[i][ans++]=a[i][cur];
                    a[i][ans]=a[i][cur+1];
                    cur++;
                }
                else if(cur==n-1 && cur-1==ans){
                    a[i][ans++] = a[i][cur];
                }
            }
            while(ans<n){
                a[i][ans++]=0;
            }
        }
    }
    else if(dir=="up")
    {
        for(int i=0;i<n;i++){
            int cur=0;
            int ans;
            for(int j=0;j<n && cur<n;){

                if(a[j][i]==0){
                    j++;
                }
                else{
                    a[cur++][i]=a[j++][i];
                }
            }

            while(cur<n){
                a[cur++][i]=0;
            }

            ans=0;
            cur=0;
            for(int j=0;j<n && cur<n;j--){

                if(cur<n-1 &&a[cur][i]==a[cur+1][i]){
                    a[ans++][i]=a[cur][i]+a[cur+1][i];
                    cur= cur+2;
                }
                else if(cur<n-1 &&a[cur][i]!=a[cur+1][i]){
                    a[ans++][i]=a[cur][i];
                    a[ans][i]=a[cur+1][i];
                    cur++;
                }
                else if(cur==n-1 && cur-1==ans){
                    a[ans++][i] = a[cur][i];
                }
            }
            while(ans<n){
                a[ans++][i]=0;
            }
        }
    }
    cout<<"Case #"<<testcase<<":\n";
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
    }


}

int main()
{

    int t;
    int n;
    string direction;
    cin>>t;
    int a[N][N];

    for(int k=0;k<t;k++){

            cin>>n;
            cin>>direction;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cin>>a[i][j];
                }
            }
            process2014(a,n,direction,k+1);
    }

    return 0;
}
