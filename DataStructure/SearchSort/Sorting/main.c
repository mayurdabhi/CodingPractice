#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b){

    int temp;

    temp = *a;
    *a= *b;
    *b= temp;
    return;
}


void heapify(int* a, int length, int ind){

    int i,j,maxTemp;

    maxTemp = ind;

    i=ind*2+1;
    j=(ind+1)*2;

    if(i<length && *(a+i)>*(a+maxTemp)){
        maxTemp=i;
    }

    if(j<length && *(a+j)>*(a+maxTemp)){
        maxTemp = j;
    }

    if(maxTemp!=ind){
        printf("Swapping %d %d\n",*(a+maxTemp),*(a+ind));
        swap(&a[maxTemp], &a[ind]);
       // printArray(a,length);
        heapify(a,length,maxTemp);
    }

   // printArray(a,length);
}

int insert(int a[], int count, int capacity int data){

    if(count==capacity){
        return 0;
    }

    else{
        count++;
        int i= count-1;

        while(i>=0){

            if(i%2==0 && data>a[(i-2)/2]){

                a[i] = a[(i-2)/2];
                i = (i-2)/2;
            }
            else if(i%2==1 && data>a[(i-1)/2]){
                a[i] = a[(i-1)/2];
                i = (i-1)/2;
            }
            else{
                break;
            }
        }

        a[i] = data;
    }

}

void heapSort(int a[], int length){

    int i;
    //for(i=0;i<(length-1)/2;i++){
    for(i=(length-1)/2;i>=0;i--){
        heapify(a,length,i);
    }

    int tempLength = length;
    for(i=length-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,--tempLength,0);

    }
    printArray(a,length);
}

void printArray(int a[], int length)
{
    int i;
    printf("\n****Array*****\n");
    for(i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    printf("\n**************\n");
}

void countingSort(int input[], int output[], int length, int count){

    int i, buffer[count];

    for(i=0;i<count;i++){
        buffer[i]=0;
    }

    for(i=0;i<length;i++){
//        output[i]=-1;
        buffer[input[i]] += 1;
    }

    for(i=1;i<count;i++){
        buffer[i]=buffer[i]+buffer[i-1];
    }

    printArray(buffer,count);
  //  printArray(output,length);
    for(i=0;i<length;i++){
        output[buffer[input[i]]-1] = input[i];
        buffer[input[i]] -=1;
    }

}

int countMaxVote(int a[],int length){


    heapSort(a,length);

    int maxCount=0, maxCandidate=0;

    int i,currentCand, cnt;
    currentCand = a[0];
    cnt=1;
    for(i=1;i<length;i++)
    {
            if(a[i]==currentCand){
                cnt++;
            }
            else{
                if(maxCount<cnt){
                    maxCount=cnt;
                    maxCandidate=currentCand;
                }
                currentCand=a[i];
                cnt=1;
            }
    }

    printf("Winning Candidate :%d  votes:%d\n",maxCandidate,maxCount);
}

/*
int main()
{
//    printf("Hello world!\n");


    int array[10] = {4,3,7,6,5,1,2,9,8,0};
   // heapSort(array,10);

    int votes[20] = {3,4,5,2,3,4,5,3,5,4,4,4,3,2,4,2,4,5,4,3};
    int temp[20] =  {3,0,2,2,1,2,1,2,3,2,2,2,3,2,2,2,1,2,1,0};
  // countMaxVote(votes,20);
    countingSort(temp,votes,20,4);
    printArray(votes,20);
    return 0;
}
*/
