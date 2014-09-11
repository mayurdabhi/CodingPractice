#include <stdio.h>
#include <stdlib.h>


//Find Possible Binary Trees
int catalal[100]={0};

int CatalalNumber(int n){

    int i;
    if(n==0){
        return 1;
    }

    if(catalal[n]!=0){
        return catalal[n];
    }
    int sum = 0;
    for(i=1;i<=n;i++){
        sum += CatalalNumber(i-1)*CatalalNumber(n-i);
    }
    catalal[n] = sum;
    return sum;
}


int findNumberOfBinaryTree(int n){

    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }

    int left,sum,right,i;
    left =sum= right = 0;
    for(i=1;i<=n;i++){
        left = findNumberOfBinaryTree(i-1);
        right = findNumberOfBinaryTree(n-i);
        sum += left*right;
    }
    return sum;
}
int main()
{
//    printf("Hello world!\n");

    printf("BST (Catalal No.) using %d node : %d\n",6,CatalalNumber(3));

    printf("BST (Recursion) using %d node : %d\n",6,findNumberOfBinaryTree(3));
    return 0;
}
