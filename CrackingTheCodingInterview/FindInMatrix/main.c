#include <stdio.h>
#include <stdlib.h>

#define M 5
#define N 6

int FindElemInMat(int mat[M][N], int elem){

    int i=M-1;
    int j=0;

    while(i>0 && j<N){
        while(mat[i][j]>elem){
            i--;
        }

        while(mat[i][j]<elem){
            j++;
        }

        if(mat[i][j] == elem){
            printf("Element %d Found at (%d, %d)\n",elem,i,j);
            return 1;
        }
    }
    printf("Element %d not found in Matrix\n",elem);
    return 0;
}

int main()
{
    int mat[M][N] = {
                        {1,2,3,4,5,6},
                        {3,5,6,7,8,9},
                        {4,5,7,8,9,10},
                        {6,8,11,15,16},
                        {9,12,13,17,18},
                    };

    FindElemInMat(mat,8);
    return 0;
}
