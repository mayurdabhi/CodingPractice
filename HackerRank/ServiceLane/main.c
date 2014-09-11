#include <stdio.h>
#include <stdlib.h>

void findMinSegment(int lane[],int i, int j){

    int k,min= 3;

     for(k=i;k<=j;k++){

        if(lane[k]<min){
            min = lane[k];
        }
     }

     printf("%d\n",min);

}

int main()
{
    int size,testcase, k,j,i;
    int lane[100000] = {0};
    scanf("%d %d",&size,&testcase);

    for(i=0;i<size;i++){
        scanf("%d",&lane[i]);
        //printf("%d ",lane[i]);
    }// scanf("%d",&lane[i]);

    for(k=0;k<testcase;k++){
        scanf("%d %d",&i, &j);
        findMinSegment(lane,i,j);

    }

    return 0;
}
