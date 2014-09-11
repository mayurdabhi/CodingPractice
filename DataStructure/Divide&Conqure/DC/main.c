#include <stdio.h>
#include <stdlib.h>

int FindMedianIndex(int list[],int start, int end){

    return (end-start)/2+start;
}

int findMax(int a, int b){

    return (a>b)?a:b;
}


int findMin(int a, int b){

    return (a<b)?a:b;
}

int computeMedian(int list1[],int start1, int end1, int list2[],int start2, int end2){

    int s1,e1,s2,e2,m1,m2;

    s1=start1;
    s2=start2;
    e1=end1;
    e2=end2;

    if((e1-s1==1)&&(e2-s2==1))
    {
        int medianSum =  findMax(list1[0],list2[0])+findMin(list1[1],list2[1]);

        return medianSum/2;
    }

    m1 = FindMedianIndex(list1,s1,e1);
    m2= FindMedianIndex(list2,s2,e2);

    if(list1[m1]== list2[m2]){
        return list1[m1];
    }
    if(m1>m2){
        return computeMedian(list1,s1,m1,list2,m2,e2);
    }
    else{
        return computeMedian(list1,m1,e1,list2,s1,m2);
    }

}

void StockStrategy(int price[], int start, int end){

    return;
}

int main()
{

/*
    int a[5], b[10];
    int ind;

    printf("Enter A[5] Sorted: \n");
    for(ind=0;ind<5;ind++){
        scanf("%d",&a[ind]);
    }

    printf("Enter B[10] Sorted: \n");
    for(ind=0;ind<8;ind++){
        scanf("%d",&b[ind]);
    }

    int ans =  computeMedian(a,0,5,b,0,8);
    ans = StockStrategy(b,0,8);
    printf("Median of Two list : %d :: Time :O(log n)\n", ans);

    */

    char c=48;
    int i, mask=01;
    for(i=1; i<=5; i++)
    {
        printf("%c", c|mask);
        mask = mask<<1;
    }

    return 0;



    return 0;
}
