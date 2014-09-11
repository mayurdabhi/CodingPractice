#include <stdio.h>
#include <stdlib.h>

#define M 6
#define N 5

int maximum(int a, int b){
    return (a>b)?a:b;
}

int minimum(int a, int b, int c){

    c = min(b,c);
    return (a<c)?a:c;
}

int min(int a, int b){
    return (a<b)?a:b;
}

//Complexity O(M*N)
int printMaxSubSquare(int a[][N]){

    int i, j;
    int max, max_i, max_j;
    int t[M][N];

    //Copy first col
    for(i=0;i<M;i++){
            t[i][0]= a[i][0];
            if(t[i][0]){
                max=1;
                max_i = i;
                max_j = 0;
            }
    }

    //copy first row
    for(j=0;j<N;j++){
            t[0][j]= a[0][j];
            if(t[0][j]){
                max=1;
                max_i = 0;
                max_j = j;
            }
    }

    for(i=1;i<M;i++){
        for(j=1;j<N;j++){

            t[i][j] = 0;

            if(a[i][j]){
                t[i][j] = minimum(t[i-1][j],t[i][j-1],t[i-1][j-1])+1;
                //keep track of element
                if(max<=t[i][j]){
                    max = t[i][j];
                    max_i = i;
                    max_j = j;
                }
            }
        }
    }

    //Print from bottom most corner

    for(i=max_i;i>max_i - max;i--){
        for(j=max_j;j>max_j - max ;j--){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }


}

int main()
{
    int Mat[M][N] =  {{0, 1, 1, 0, 1},
                   {1, 1, 0, 1, 0},
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};

  printMaxSubSquare(Mat);

    return 0;
}
