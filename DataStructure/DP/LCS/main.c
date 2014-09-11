#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int LCS[100][100] = {0};

int max(int a,int b){

    return (a>b)?a:b ;
}

//With Recursion

int LCSLength (char* a, char * b, int m, int n){


        if(m==0 || n== 0){
            return 0;
        }
        else if(*(a+m)==*(b+n)){
            return 1+ LCSLength(a,b,m-1,n-1);
        }
        else{

            return max(LCSLength(a,b,m,n-1),LCSLength(a,b,m-1,n));
        }
}

//With Memorization DP

void printLCS(char a[], char b[],int m, int n){

    int i=m, j = n, index = LCS[m][n];

    char result[index+1];

    result[index] = '\0';

    while(i>0 && j>0){

        if(a[i]==b[j]){
            result[index-1] = a[i-1];
            index--;
            i--;
            j--;
        }
        else if(LCS[i-1][j]>LCS[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }

    printf("%s\n",result);
}

int LCS_DP(char *a, char* b, int m, int n){

    int i,j;

    for(i=0;i<=m;i++){

        for(j=0;j<=n;j++){

            if(i==0||j==0)
            {
                LCS[i][j] = 0;
            }
            else if(*(a+i-1)== *(b+j-1))
            {
                LCS[i][j] = LCS[i-1][j-1]+1;
            }
            else{

                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }

    printf("LCS String :: ")
    printLCS(a,b,m,n);

    return LCS[m][n];
}




int main()
{

    char * str1 = "AABCDEAB";
    char * str2 = "ABCDEBABD";

    int m,n;
    int ans;

    m = strlen(str1);
    n = strlen(str2);


    ans = LCSLength(str1,str2,m,n);

    printf("LCS(Recursion) of %s and %s : %d\n",str1,str2,ans);

    ans = LCS_DP(str1,str2,m,n);

    printf("LCS(DP) of %s and %s : %d\n",str1,str2,ans);


    return 0;
}
