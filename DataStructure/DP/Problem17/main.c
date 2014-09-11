#include <stdio.h>
#include <stdlib.h>

int maxVal(int a,int b){

    int c = (a>b)?a:b ;
    return c;
}


int result[6][7]= {0};

// create matrix to hold n items and m capacity


//Implemented to satisfy first 3 condition

int getValue(int i, int j){

    if(i==0 || j ==0){
        return 0;
    }
    else if(j<0){
        return -1000;
    }
    else{
        return result[i][j];
    }
}

//Knapsack Item Allowed only once to
int Knapsack(int w[],int v[], int n, int capacity){



    int i,j,temp1, temp2;

    if(capacity== 0)
        return 0;


    for(i=1;i<=n;i++){

        for(j=0;j<=capacity;j++){

            if(w[i]>j){
                result[i][j]=result[i-1][j];
            }
            else{

                temp1 = getValue(i-1,j);
                temp2 = getValue(i-1, j-w[i]);
                result[i][j] = maxVal(temp1,temp2+v[i] );
            }
        }

    }

    for(i=0;i<=n;i++){

        for(j=0;j<=capacity;j++){

            printf("%2d ",result[i][j]);
        }
        printf("\n");
    }


}


//Knapsack Item Allowed to take multiple times

int KnapsackMulti(int w[],int v[], int n, int capacity){

    int i,j,temp1, k, temp2;

    if(capacity== 0)
        return 0;


    for(i=1;i<=n;i++){

        for(j=0;j<=capacity;j++){

            if(w[i]>j){
                result[i][j]=result[i-1][j];
            }
            else{

                temp1 = 0;
                for(k=1; k<=i;k++){
                    temp2 = getValue(i-1, j-w[k]);

                    temp1 = maxVal(temp1,temp2+v[k]);
                }

                result[i][j] = maxVal(getValue(i-1,j),temp1);
            }
        }
    }

    for(i=0;i<=n;i++){

        for(j=0;j<=capacity;j++){

            printf("%2d ",result[i][j]);
        }
        printf("\n");
    }


}

int changeResult[5][11]={0};

int minVal(int a,int b){

    if(a!=0)
    {
      return (a<b)?a:b ;
    }
    return b;
}


int getChangeValue(int i, int j){

    if(i==0 || j ==0){
        return 0;
    }
    else{
        return changeResult[i][j];
    }
}


int MakingChange(int di[], int n, int change){

    int i,j,temp1, temp2;

    if(change== 0)
        return 0;

    for(i=1;i<=n;i++){

        for(j=0;j<=change;j++){

            if(j==0){
                changeResult[i][j] = 0;
            }
            else{
                temp1 = getChangeValue(i-1,j);
                temp2 = getChangeValue(i, j-di[i]);
                changeResult[i][j] = minVal(temp1,temp2+1 );
            }
        }
    }

    for(i=0;i<=n;i++){
        for(j=0;j<=change;j++){
            printf("%2d ",changeResult[i][j]);
        }
        printf("\n");
    }


}


int main()
{

    int w[5]={0,2,1,3,2};
    int v[5]={0,12,10,20,15};
    int capacity =5;

    printf("Knapsack 0-1\n");
    Knapsack(w,v,5,5);

    printf("\nKnapsack Duplicate Item alloed\n");

    KnapsackMulti(w,v,5,5);


    int coins[4]={0,1,4,6};

    printf("\nMaking Change using DP\n");

    MakingChange(coins,5,10);
    return 0;
}
