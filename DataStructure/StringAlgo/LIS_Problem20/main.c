#include <stdio.h>
#include <stdlib.h>

#define size 10
int max(int a, int b){

    return (a>b)?a:b;
}

// Problem 20  Using DP O(n^2)
int FindLIS(int a[], int n){

    int LIS[size] ;
    int str[size][size];
    int i,j,k, max;

    for(i=0;i<size;i++){
        LIS[i] = 1;
        //str[i] = a[i];
        str[i][0] = a[i] ;
    }

    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            if(a[j]<a[i] && LIS[i] < LIS[j]+1){

                //To copy previous string and append new a[i] tp string
                for(k=0;k<LIS[j];k++){
                    str[i][k] = str[j][k];
                }

                str[i][LIS[i]]=a[i];
                LIS[i] = LIS[i]+1;

            }
        }
    }

    max =0;
    for(i=1;i<n;i++){
        if(LIS[i]>LIS[max]){
            max =i;
        }
    }

    for(i=0;i<LIS[max];i++){
        printf("%d ",str[max][i]);
    }
    printf("\nLIS Length : %d\n", LIS[max]);
}

//PRoblem 21 DP O(n^2)
int FindLISFromBack(int a[], int n){

    int LIS[size] ;
    int i,j, max;

    for(i=0;i<size;i++){
        LIS[i] = 1;
    }

    for(i=n-1;i>=0;i--){
        for(j=i+1;j<n;j++){
            if(a[i]<a[j] && LIS[i] < LIS[j]+1){
                LIS[i] = LIS[j]+1;
               // printf("a[%d] : %d\n",j,a[j]);
            }
        }
    }

    max =0;
    for(i=1;i<n;i++){
        if(LIS[i]>LIS[max]){
            max =i;
        }
    }

    printf("%d\n", LIS[max]);
}
int main()
{
    int a[]={1,5,11,2,7,4,1,8,9,5};
    FindLIS(a,10);
//    FindLISFromBack(a,10);
    return 0;
}
