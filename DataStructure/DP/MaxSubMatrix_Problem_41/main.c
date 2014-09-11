#include <stdio.h>
#include <stdlib.h>

#define M 4
#define N 5

//Kadane's algorithm for 1D array.
int maxContinuousSumCalc(int a[], int *start, int * end)
{
    int curr, max_end, i;

    curr = 0;
    max_end = 0;
    int local = 0;
    *start = 0;
    *end  = 0;

    for(i=0;i<M;i++){

        curr += a[i];

        if(curr <= 0 || a[i]==0){ //change condition for max sub matrix
            curr= 0;
            local = i+1;
        }
        else if(curr>max_end){
            max_end = curr;
            *start = local;
            *end = i;
        }
    }

    if(max_end <0){
        curr = a[0];
        max_end = a[0];
        *start = 0;
        *end = 0;

        for(i=1;i<M;i++){
            if(a[i]>max_end){
                max_end = a[i];
                *start = i;
                *end = i;
            }
        }
    }

    return max_end;
}

int maxContinuousSum(int a[], int *start, int * end)
{
    int curr, max_end, i;

    curr = 0;
    max_end = 0;
    int local = 0;
    *start = 0;
    *end  = 0;

    for(i=0;i<M;i++){

        curr += a[i];

        if(curr < 0){
            curr= 0;
            local = i+1;
        }
        else if(curr>max_end){
            max_end = curr;
            *start = local;
            *end = i;
        }
    }

    if(max_end <0){
        curr = a[0];
        max_end = a[0];
        *start = 0;
        *end = 0;

        for(i=1;i<M;i++){
            if(a[i]>max_end){
                max_end = a[i];
                *start = i;
                *end = i;
            }
        }
    }

    return max_end;
}


int maxMatrixSum(int a[M][N]){

    int left, right, temp[M],i,sum, start, finish;
    int maxSum, maxleft,maxright, maxtop, maxbottom;

    maxSum=0;
    for(left = 0;left<N;left++){
        memset(temp,0,sizeof(temp));

        /*
        for(i=0;i<M;i++){
            printf("%d ",temp[i]);
        }
        */

        printf("\n");
        for(right = left; right<N;right++){

            for(i=0;i<M;i++){
                    temp[i] += a[i][right];
            }
            /*
            for(i=0;i<M;i++){
                printf("temp : %d ",temp[i]);
            }
            */

            sum = maxContinuousSum(temp,&start, &finish);
            printf("\nsum : %d maxSum:%d \n%d %d\n%d %d\n",sum,maxSum,left,start, right,finish);
            if(sum>maxSum){
                maxSum=sum;
                maxleft = left;
                maxright = right;
                maxtop = start;
                maxbottom = finish;
            }
        }
    }

    printf("(Top, Left) (%d, %d)\n", maxtop, maxleft);
    printf("(Bottom, Right) (%d, %d)\n", maxbottom, maxright);
    printf("Max sum is: %d\n", maxSum);
}


int maxSubRactangle(int a[M][N]){

    int left, right, temp[M],i,sum, start, finish;
    int maxSum, maxleft,maxright, maxtop, maxbottom;

    maxSum=0;
    for(left = 0;left<N;left++){

        //set here with -1 so that we can know its new column.
        memset(temp,-1,sizeof(temp));
        /*
        for(i=0;i<M;i++){
            printf("%d ",temp[i]);
        }
        */

        printf("\n");
        for(right = left; right<N;right++){

            for(i=0;i<M;i++){

            //Change here to get sub matrix
                if(temp[i]==0 || a[i][right]==0){
                    temp[i]=0;
                }
                else if(temp[i] == -1){
                    temp[i] = a[i][right];
                }
                else{
                    temp[i] += a[i][right];
                }
            }
          /*  for(i=0;i<M;i++){
                printf("temp : %d ",temp[i]);
            }
        */
            //New function with little chage
            sum = maxContinuousSumCalc(temp,&start, &finish);
            printf("\nsum : %d maxSum:%d \n%d %d\n%d %d\n",sum,maxSum,left,start, right,finish);
            if(sum>maxSum){
                maxSum=sum;
                maxleft = left;
                maxright = right;
                maxtop = start;
                maxbottom = finish;
            }
        }
    }

    printf("(Top, Left) (%d, %d)\n", maxtop, maxleft);
    printf("(Bottom, Right) (%d, %d)\n", maxbottom, maxright);
    printf("Max sum is: %d\n", maxSum);
}


int main()
{

    int Mat1[M][N] = {{1, 2, -1, -4, -20},
                     {-8, -3, 4, 2, 1},
                     {3, 8, 10, 1, 3},
                     {-4, -1, 1, 7, -6}
                      };

    int Mat2[M][N] ={
                        {1,1,0,0,1},
                        {0,1,1,1,1},
                        {1,1,1,1,0},
                        {1,1,1,1,0}
                    };

    printf("Matrix with max Sum : \n");
    maxMatrixSum(Mat1);
    printf("\nMatrix with Max continious 1's :\n");
    maxSubRactangle(Mat2);
    return 0;
}
