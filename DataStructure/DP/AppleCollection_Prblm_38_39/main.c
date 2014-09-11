#include <stdio.h>
#include <stdlib.h>

#define R 4
#define L 3

int maximum(int a, int b){
    return (a>b)?a:b;
}

//Problem 39
//Complexity O(mn)
int FindAppleCount_Diag(int a[][R]){

    int count[L][R];
    int i,j, temp1, temp2,temp3, max;

    //
    for(i=0;i<L;i++){
        for(j=0;j<R;j++){
            count[i][j] = 0;
        }
    }

    //copy initial point value
    count[0][0] = a[0][0];

    for(i=0;i<L;i++){

        for(j=0;j<R;j++){
            count[i][j] =  a[i][j];
            temp1=0;
            temp2=0;
            temp3=0;
            if(i>0){
                temp1 = count[i-1][j];
            }
            if(j>0){
                temp2 = count[i][j-1];
            }
            if(i>0 && j >0)
            {
                temp3 = count[i-1][j-1];
            }
            max = maximum(temp1,maximum(temp2,temp3));

            count[i][j] +=max;
        }
    }

    printf("Maximum Apple (diagonal Travesal allowed) : %d \n",count[L-1][R-1]);
    return 0;
}


//Problem 38
//Complexity O(n*m)
int FindAppleCount(int a[][R]){

    int count[L][R];
    int i,j, temp1, temp2, max;

    //
    for(i=0;i<L;i++){
        for(j=0;j<R;j++){
            count[i][j] = 0;
        }
    }

    //copy initial point value
    count[0][0] = a[0][0];

    for(i=0;i<L;i++){

        for(j=0;j<R;j++){
            count[i][j] =  a[i][j];
            temp1=0;
            temp2=0;
            if(i>0){
                temp1 = count[i-1][j];
            }
            if(j>0){
                temp2 = count[i][j-1];
            }

            max = maximum(temp1,temp2);

            count[i][j] +=max;
        }
    }

    printf("Maximum Apple : %d \n",count[L-1][R-1]);
    return 0;
}

int main()
{

        int apples[L][R] ={
                            {1, 2, 5, 4},
                            {9, 14, 1, 2},
                            {8, 0, 1, 5}
                        };
        FindAppleCount(apples);
        FindAppleCount_Diag(apples);

       return 0;
}
