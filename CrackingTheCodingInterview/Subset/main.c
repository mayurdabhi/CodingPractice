#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findCombination(char a[], int n, char c[], int i){

    if(n==0){
        printf("%s\n",c);
        return;
    }
    else{

        findCombination(a,n-1,c,i+1);
        findCombination(a,n-1,c,i);
    }


}


int main()
{
    int n = 3;
    char a[] = {'1','2','3'};
    char b[3] = {'\0'};// =  malloc(sizeof(char)*3);
    findCombination(a,3,b,0);
    return 0;
}
