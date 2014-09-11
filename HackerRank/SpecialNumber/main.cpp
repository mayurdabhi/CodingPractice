#include <iostream>
#include <cmath>
#include <list>

#define INT_MAX 10000

using namespace std;

int minimum(int a, int b,int c){

    if(a<b && a<c){
        return a;
    }
    else if(b<c && b<a){
        return b;
    }
    else{
        return c;
    }
}
int main()
{
    int n,sum, diff,temp1,temp2,temp3, prev1, prev2, prev3, minAns;
    int *a;
     cin>>n;

    a = new int [n];

    minAns = INT_MAX;
    //Scan number

    int ans = 1;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sum=a[0];
    int t;
    for(int i=0;i<n-1;i++){
        t = a[i+1]-a[i];
        if(t>0){
            sum += t;
        }
//        sum += abs(a[i]-a[i+1]);
    }

    int sum1 = sum;

    if(n<3){
        cout<<-1<<endl;
        return 0;
    }


    for(int i=0;i<n-1;i++)
    {
        //if(abs(a[i]-a[i+1])==1){
            if(i>0 && i<n-2){
                    /*
                temp1 = abs(a[i]-a[i+2]);
                //temp2 = abs(a[i]-a[i+1]);
                temp2 = abs(a[i-1]-a[i+1]);
                prev1 = abs(a[i+1]-a[i+2]);
                prev2 = abs(a[i-1]-a[i]);
                */
                temp1 = a[i+2]-a[i];
                temp3 = a[i]-a[i+1];
                temp2 = a[i+1]-a[i-1];
                prev1 = a[i+2]-a[i+1];
                prev2 = a[i]-a[i-1];
                prev3 = a[i+1]-a[i];

                diff=0;
                if(temp1>0)
                {
                    diff += temp1;
                }
                if(temp2>0){
                    diff += temp2;
                }
                if(temp3>0){
                    diff+=temp3;
                }
                if(prev3>0){
                    diff -= prev3;
                }
                if(prev1>0){
                    diff-=prev1;
                }
                if(prev2>0){
                    diff -= prev2;
                }
               // diff = temp1+temp2-prev2-prev1;

                if(sum1 > sum+diff){
                    sum1 = sum+diff;
                    ans = minimum(a[i],a[i+1],a[i+2]);
                   /* if (ans<minAns){
                        minAns = ans;
                    }*/
                }
                else if(sum1 == sum+diff){
                     minAns = minimum(a[i],a[i+1],a[i+2]);
                     if (ans>minAns){
                        ans = minAns;
                    }
                }
            }
            else if(i==0){
                temp1 = a[i+1];
                temp2 = a[i+2]-a[i];
                prev1 = a[i];
                prev2 = a[i+2]-a[i+1];
                prev3 = a[i+1] - a[i];
                temp3 = a[i] - a[i+1];
                //diff = temp1+temp2-prev2-prev1;

                diff=0;
                if(temp1>0)
                {
                    diff += temp1;
                }
                if(temp2>0){
                    diff += temp2;
                }
                if(prev1>0){
                    diff-=prev1;
                }
                if(prev2>0){
                    diff -= prev2;
                }
                if(temp3>0){
                    diff+=temp3;
                }
                if(prev3>0){
                    diff-=prev3;
                }

                if(sum1 > sum+diff){
                    sum1 = sum+diff;
                    ans = minimum(a[i],a[i+1],a[i+2]);
                    /*if (ans<minAns){
                        minAns = ans;
                    }
                    */
                }
                  else if(sum1 == sum+diff){
                     minAns = minimum(a[i],a[i+1],a[i+2]);
                     if (ans>minAns){
                        ans = minAns;
                    }
                }
            }
            else if(i==n-2){

               // temp1 = abs(a[i]);
                temp3 = a[i+1]-a[i];
                temp2 = a[i-1]-a[i+1];
                prev3 = a[i]-a[i+1];
                prev2 = a[i-1]-a[i];
                //prev3=abs()
                diff = temp2-prev2;

                diff=0;
                if(temp2>0){
                    diff += temp2;
                }
                if(prev2>0){
                    diff -= prev2;
                }
                if(temp3>0){
                    diff+=temp3;
                }
                if(prev3>0){
                    diff-=prev3;
                }
                if(sum1 > sum+diff){
                    sum1 = sum+diff;
                    ans = minimum(a[i],a[i+1],a[i-1]);
                   /* if (ans<minAns){
                        minAns = ans;
                    }
                    */
                }
                  else if(sum1 == sum+diff){
                     minAns = minimum(a[i],a[i+1],a[i-1]);
                     if (ans>minAns){
                        ans = minAns;
                    }
                }

            }
                //minAns = (temp1>temp2)?temp2:temp1;
                //t1 = (prev1>a[i])?a[i]:prev1;
     //  }
    }

    if(sum1!=sum)
    {
       cout<<ans<<endl;
    }
    else
        cout <<-1<<endl;

    //cout<<ans<<endl
    return 0;
}
