#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 15

#define MAX(a,b) (a>b)?a:b
#define MIN(a,b) (a<b)?a<b


int LongestPalindromSubSequenceDP(char str[], int n){

    int table[N][N];
    int i,j,k, max = 1;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            table[i][j] = 0;
        }
    }

    for(i=0;i<n;i++){
        table[i][i] = 1;

        if(str[i] == str[i+1]){
            table[i][i+1] = 2;
            max =2;
        }
    }

    for(k=3;k<=n;k++){
        for(i=0;i<n-k+1;i++){
            j = i+k-1;

             if(str[i]==str[j]){
                table[i][j] = 1;
            }
            else{
                table[i][j] =  0 ;
            }

            if(max<table[i][j]){
                max = table[i][j];
            }

        }
    }

    printf("Longest Palindrom SubSequence : %d\n",max);

    return table[0][n-1];
}
int LongestPalindromSubStringDP(char str[], int n){

    int table[N][N];
    int i,j,k, max = 1;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            table[i][j] = 0;
        }
    }

    for(i=0;i<n;i++){
        table[i][i] = 1;

        if(str[i] == str[i+1]){
            table[i][i+1] = 1;
            max =2;
        }
    }

    for(k=3;k<=n;k++){
        for(i=0;i<n-k+1;i++){
            j = i+k-1;

            if(str[i]==str[j] && table[i+1][j-1]){
                table[i][j] = 1;
                max = k;
            }
            else{
                table[i][j] =  0 ;
            }
        }
    }

    printf("Longest Palindrom Substring : %d\n",max);

    return table[0][n-1];
}


int main()
{
    char *str ="AGCTCBABCTGGAM";
    int n = strlen(str);
    printf("Size : %d\n",n);
    LongestPalindromSubStringDP(str,n);
}
