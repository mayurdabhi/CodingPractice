#include <stdio.h>
#include <stdlib.h>

#define N 4

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b){
    return (a>b)?a:b;
}

int optimalStrategyOfGame(int a[], int n){

    int table[N][N];

    int i,j,x,y,z,gap;

    //To travers dialonally
    for(gap=0;gap<n;gap++){

        for(i=0,j=gap;j<n;j++,i++){

            x = (i+2<=j)?table[i+2][j]:0;
            y = (i+1<=j-1)?table[i+1][j-1]:0;
            z = (i<=j-2)?table[i][j-2]:0;

            table[i][j] = max( a[i] +  min(x,y), a[j] + min(y,z));

        }
    }

    printf("%d\n",table[0][n-1]);

    return table[0][n-1];
}

int main()
{
    int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));
    return 0;
}
