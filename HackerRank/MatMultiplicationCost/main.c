#include <stdio.h>
#include <stdlib.h>

#define M 10
#define N 10


int mul[M][N] = {0};


//Arguments : p0,p1,p2..pn values, length of array
int findMatMulCost(int p[],int length)
{
    int tempCost=0, minCost = 0,i,j,k;
    int n,l;
    int s[M][N] = {0};// malloc(sizeof(int)*m*n);

    n = length-1;
    for(i = 1; i<=n;i++){
        mul[i][i] = 0;
    }

    for(l=2;l<=n;l++){
        for(i=1;i<=n-l+1;i++){
                j= i+l-1;
                mul[i][j] = 10000;
            for(k=i;k<j;k++){
                tempCost = mul[i][k] + mul[k+1][j] + p[i-1]*p[k]*p[j];

                if(tempCost<mul[i][j]){
                    mul[i][j] = tempCost;
                    s[i][j]= k;
                }
            }
        }
    }

    printf("%d\n", mul[1][3]);
}
int main()
{

    int p[]= {3,100,2,2};
    findMatMulCost(p,4);
    return 0;
}
