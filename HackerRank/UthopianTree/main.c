#include <stdio.h>
#include <stdlib.h>

int FindHeight(int n){

    int height =1;
    int temp = 1;
    while(temp<=n){
        if(temp%2==1){
            height *=2;
        }
        else{
            height +=1;
        }
        temp++;
    }
    return height;
}

int main()
{
    int testcase, cycle,i;
    scanf("%d",&testcase);

    for(i=0;i<testcase;i++){
        scanf("%d",&cycle);
        printf("%d\n",FindHeight(cycle));
    }

    return 0;
}
