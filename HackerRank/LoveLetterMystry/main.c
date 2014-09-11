#include <stdio.h>
#include<stdlib.h>
#include <string.h>


int makePalindrom(char * str){

    char * a  = str;
    int length = strlen(a);
    int l,r,count,diff;
    l=0;r= length-1;
    count =0;

    while(l<r){
        if(*(a+l) > *(a+r)){
            diff = *(a+l) -  *(a+r);
            count +=diff;
            *(a+l) = *(a+r);
        }
        else if(*(a+r) > *(a+l)){
            diff = *(a+r) -  *(a+l);
            count +=diff;
            *(a+r) = *(a+l);
        }
        l++;
        r--;
    }
    return count;
}

int main(){

    int testCase,i, count;
    char *str = malloc(10000);

    scanf("%d",&testCase);

    for(i=0;i<testCase;i++){
        scanf("%s",str);
        count = makePalindrom(str);
        printf("%d",count);

    }


    return 0;
}
