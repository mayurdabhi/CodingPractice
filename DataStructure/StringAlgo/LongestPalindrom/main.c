#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Len 17

void printString(char str[], int i, int j){
    int k;
    for(k=i;k<j;k++){
        printf("%c",str[k]);
    }
    printf("\n");
}


//Complexit time O(n^2) space O(1)
int FindLongestPalindrom(char str[], int n){

    int maxLength = 1;
    int low, high, start;

    int i;

    for(i=1;i<n;i++){

        //Even Length Palindrom
        low = i-1;
        high =i;

        while(low>=0 && high <n &&(str[low]==str[high])){
            if(high-low+1 > maxLength){
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }

        //Odd Length Palindrom
        low = i-1;
        high = i+1;

        while(low>=0 && high <n &&(str[low]==str[high])){
            if(high-low+1 > maxLength){
                maxLength = high-low+1;
                start = low;
            }
            low--;
            high++;
        }
    }

    printString(str,start,start+maxLength);
    //printf("\n%d\n",maxLength);
    return maxLength;
}

//DP solution O(n^2) time & O(n^2) space complexity

int DPLongestPalindrom(char *str, int length){

    int dpMap[Len][Len];

    int i,j, maxLen, start, sLen;
    maxLen=1;
    for(i=0;i<Len;i++){
        for(j=0;j<Len;j++){
            dpMap[i][j] = 0;
        }
    }

    for(i=0;i<Len;i++){
        //single char length
        dpMap[i][i] = 1;

        //two char length
        if(str[i]==str[i+1]){
            dpMap[i][i+1] = 1;
            maxLen=2;
        }
    }

    for(sLen=3;sLen<=Len;sLen++){
        for(i=0;i<Len-sLen+1;i++){
            j=i+sLen-1;

            if(str[i]==str[j] && dpMap[i+1][j-1]==1){
                dpMap[i][j] =1;
                start = i;
                maxLen = sLen;
            }
        }
    }

    //printf("%d\n",maxLen);
    printString(str,start,maxLen+start);
}

int main()
{

    char * str = "sfrorgeekskeegrofg";

    FindLongestPalindrom(str,strlen(str));
    DPLongestPalindrom(str,strlen(str));

    return 0;
}
