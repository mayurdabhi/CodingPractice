#include <stdio.h>
#include <stdlib.h>


//Maximum Sum contiguous sequence

//from continuouse sequence
int findMaxSum(int a[], int sum[], int n)
{


    int i, maxSum=0;

    if(a[0]>0){
        sum[0]=a[0];
    }
    else{
        sum[0] = 0;
    }

    for(i=1;i<n;i++){

        if(a[i]+sum[i-1]>0){
            sum[i]= a[i]+sum[i-1];
        }
        else{
            sum[i] = 0;
        }
    }

    for(i=0;i<n;i++){

        if(sum[i]>maxSum){
            maxSum = sum[i];
        }
    }

    return maxSum;
}

//sequence should not have two continuous data

int findMaxSum2(int a[], int sum[], int n)
{


    int i, maxSum=0;

    if(a[0]>0){
        sum[0]=a[0];
    }
    else{
        sum[0] = 0;
    }

    if(a[1]>sum[0]){
        sum[1]=a[1];
    }
    else{
        sum[1]=sum[0];
    }


    for(i=2;i<n;i++){

        if(a[i]+sum[i-2]>sum[i-1]){
            sum[i]= a[i]+sum[i-2];
        }
        else{
            sum[i] = sum[i-1];
        }
    }

    for(i=0;i<n;i++){

        if(sum[i]>maxSum){
            maxSum = sum[i];
        }
    }

    return maxSum;
}


//sequence should not have three continuous data

int findMaxSum3(int a[], int sum[], int n)
{


    int i, maxSum=0;

    if(a[0]>0){
        sum[0]=a[0];
    }
    else{
        sum[0] = 0;
    }

    if(a[1]>a[0]){
        sum[1]=a[1];
    }
    else{
        sum[1]=a[0];
    }

    if(sum[0]+a[2]>sum[1]){
        sum[2]=sum[0]+a[2];
    }
    else{
        sum[2] = sum[1];
    }
    for(i=3;i<n;i++){

        if(a[i]+a[i-1]+sum[i-3]>sum[i-1] && a[i]+a[i-1]+sum[i-3]>a[i]+sum[i-2]){
            sum[i]= a[i]+a[i-1]+sum[i-3];
        }
        else if(a[i]+sum[i-2]>sum[i-1]){
            sum[i]=a[i]+sum[i-2];
        }
        else{
            sum[i] = sum[i-1];
        }
    }

    for(i=0;i<n;i++){

        if(sum[i]>maxSum){
            maxSum = sum[i];
        }
    }

    return maxSum;
}

int main()
{

    int sum[7]={0};
    int a[7]={2,-2,4,6,-10,3,-9};
    printf("Max Sum : %d\n",findMaxSum(a,sum,7));
    printf("Max Sum : %d\n",findMaxSum2(a,sum,7));
    printf("Max Sum : %d\n",findMaxSum3(a,sum,7));
    return 0;
}
