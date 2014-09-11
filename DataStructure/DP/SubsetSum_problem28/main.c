#include <stdio.h>
#include <stdlib.h>

int HalfSumofSubSet(int a[], int n){

    int sum, i,j;
    sum = 0;
    for(i=0;i<n;i++){
        sum+= a[i];
    }

    if(sum%2 != 0 ){
        printf("Not able to subset elemnt in half sum\n");
        return 0;
    }
    int k = sum/2 +1;
    int **part = (int **)malloc(k*sizeof(int *));

    for(i=0;i<k;i++){
        part[i] = (int *)malloc((n+1)*sizeof(int));
    }

    for(i=0;i<n+1;i++){
        part[0][i] = 1;
    }

    for(i=0;i<k;i++){
        part[i][0] = 0;
    }

    for(i=1;i<k;i++){
        for(j=1;j<=n;j++){

            part[i][j] = part[i][j-1];

            if(i>=a[j-1]){
                part[i][j] = part[i][j]||part[i-a[j-1]][j-1];
            }
        }
    }

    printf("Ans : %d\n",part[k-1][n]);
    return 1;

}


int main()
{

    int a[] = {6,2};
    HalfSumofSubSet(a,2);
    return 0;
}
