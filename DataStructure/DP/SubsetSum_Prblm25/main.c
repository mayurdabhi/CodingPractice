#include <stdio.h>
#include <stdlib.h>


int SubSetSum(int a[], int n,int t){

    int i,j;
    int **dpMap = (int **)malloc((n+1)*sizeof(int *));

    for(i=0;i<=t;i++){
        dpMap[i] = (int *)malloc((t+1)*sizeof(int));
    }

   for(i=0;i<=n;i++){
     dpMap[i][0]=1;
     for(j=1;j<=t;j++){
           dpMap[i][j] = 0;
      }
   }

     for(i=0;i<=n;i++){
        for(j=0;j<=t;j++){
            printf("%d ",dpMap[i][j]);
      }
      printf("\n");
    }

    for(i=1;i<=n;i++){
        for(j=1;j<=t;j++){
            //Easy to under stand from here
            //https://www.youtube.com/watch?v=hi-Ec4jYyII
            dpMap[i][j] = dpMap[i-1][j]|| ((j-a[i-1]>=0) && dpMap[i-1][j-a[i-1]]);
        }
    }

    printf("\n\n");

    for(i=0;i<=n;i++){
        for(j=0;j<=t;j++){
            printf("%d ",dpMap[i][j]);
      }
      printf("\n");
    }
    printf("%d\n",dpMap[n][t]);

}

int main()
{

    int a[] = {12,14,15};
    SubSetSum(a,3,27);
    return 0;
}


