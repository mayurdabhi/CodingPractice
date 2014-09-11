#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int main()
{
   // printf("Hello world!\n");

    int r,c,h,w;

    int rc[500][500];
    int hw[500][500];
    int i,j,k,l;
    int minCol=500,minRow=500;
    long minSum=INT_MAX;

    scanf("%d %d",&r,&c);

    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&rc[i][j]);
           // rc[i][j] =1;
        }
    }

    scanf("%d %d",&h,&w);

    for(i=0;i<h;i++){
        for(j=0;j<w;j++){
            scanf("%d",&hw[i][j]);
            //hw[i][j] = 1;
        }
    }


    long int sumDiff = 0;
    int m = r-h;
    int n = c-w;
    int z=0;
    for(i=m;i>=0;i--){
        for(j=n;j>=0;j--){
            sumDiff = 0;
           // printf("\n%ld %ld\n%d %d\n",sumDiff,minSum,minRow,minCol);

            for(k=0;k<h;k++){
                for(l=0;l<w;l++){
                    z = rc[i+k][j+l]-hw[k][l];
                    sumDiff += z*z;//(rc[i+k][j+l]-hw[k][l]);
                   // printf("%d %d sum : %ld\n",rc[i+k][j+l],hw[k][l],sumDiff);
                }
            }

            if(sumDiff == 0){
                minSum = sumDiff;
                minRow = i;
                minCol = j;
                printf("%ld\n%d %d\n",minSum,minRow+1,minCol+1);
                return 0;
            }
            if(sumDiff<minSum){
                minSum = sumDiff;
                minRow = i;
                minCol = j;
            }
            else if(sumDiff==minSum)
            {
                if(minRow>i){
                    minRow = i;
                    minCol = j;
                }
                else if(minRow == i && minCol>j){
                    minCol = j;
                }
            }
           // printf("Final after iteration: %ld %ld\n%d %d\n",sumDiff,minSum,minRow,minCol);
        }
    }

    printf("%ld\n%d %d\n",minSum,minRow+1,minCol+1);
//    p
    return 0;
}
