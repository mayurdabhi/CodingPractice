#include <stdio.h>
#include <stdlib.h>

void printingArray(int a[], int length)
{
    int i;
    printf("\n****Array*****\n");
    for(i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    printf("\n**************\n");
}

void ShellSort(int a[], int size){

    int h, i, j,k;

    for(h=1;h<=(size/3);h=h*3+1){}

    for(;h>0;h=h/3){

        for(i=h+1;i<size;i+=1){
            j=i;
            k = a[i];

            while(j>h && a[j-h]>k){
                a[j]=a[j-h];
                j-=h;
            }
            a[j] = k;
        }

    }

    printingArray(a,size);
}




int main()
{
    int a[8]={3,5,7,1,2,4,9,6};
    ShellSort(a,8);
    return 0;
}
