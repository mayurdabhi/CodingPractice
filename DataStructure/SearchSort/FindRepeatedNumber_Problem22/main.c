#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int findMultiplication(int n){
    int ans=1,i=1;

    for(i=2;i<=n;i++){
        ans *=i;
    }
    return ans;
}

int findSum(int n){

    int ans =1;
    ans= n*(n+1)/2;
    return ans;
}



int main()
{
    int a[7] ={4,2,4,5,3,2,1};

    int n= findMultiplication(5);
    int s = findSum(5);


    int i=1;
    int p=1, t=0;
    // t = sum of all elemnt of array
    // p = multi of all elemnt of array
    for(i=0;i<7;i++){
        t+=a[i];
        p*=a[i];
    }

    s = t-s; //contains x+y
    n = p/n; // contains xy


    int d = sqrt(s*s - 4*n);  // (x-y)^2 = (x+y)^2 - (4xy);

    int x = (s+d)/2; //x = ((x+y) + (x-y))/2;
    int y =  s-x;


    printf("%d %d\n",x,y);
    return 0;
}
