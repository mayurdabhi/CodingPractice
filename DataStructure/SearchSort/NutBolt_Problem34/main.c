#include <stdio.h>
#include <stdlib.h>

int partition(int a1[],int pivot,int start, int end){

   // int pivot = a2[start];
    int i,j,temp;
    i=start;
    j= end;

    while(i<j){
        while(a1[i]<pivot){
            i++;
        }

        while(a1[j]>pivot){
            j--;
        }
//        printf("%d %d", i ,j);
        if(i<j){
            temp = a1[j] ;
            a1[j]= a1[i];
            a1[i] = temp;
        }
    }

    //a1[start] = a1[j];
   // a1[j] = pivot;

   return j;
}

int printArray(int a[], int size){

    int i;

    printf("******************\n");
    for(i=0;i<size;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int matchNutBolt(int nut[], int bolt[], int start, int end){

    if(start<end){

        //Normal (worstCase complexity : O(n^2) )
        // Use Randomised pivot = (start) + rand()%(end-start+1)
        //int pivot = (start) + rand()%(end-start+1);
        int pivot = start;
        int pivotNut = partition(nut,bolt[pivot],start,end);
        int pivotBolt = partition(bolt, nut[pivotNut],start,end);
     //   printf("\nNut Bolt : %d %d\n",pivotNut,pivotBolt);
        matchNutBolt(nut,bolt,start, pivotBolt-1);
        matchNutBolt(nut,bolt,pivotBolt+1,end);
    }
}

int main()
{

    int nut[6]= {3,2,5,4,1,6};
    int bolt[6] = {2,5,3,4,6,1};

    matchNutBolt(nut,bolt,0,5);
    printArray(nut,6);
    printArray(bolt,6);
    return 0;
}
