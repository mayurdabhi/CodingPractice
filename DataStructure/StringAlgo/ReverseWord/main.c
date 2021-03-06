#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int reverseString(char *str, int start, int end){

    while(start<end){
        str[start] ^=str[end];
        str[end] ^= str[start];
        str[start] ^= str[end];
        start++;
        end--;
    }
}

void printString(char str[], int i, int j){
    int k;
    for(k=i;k<=j;k++){
        printf("%c",str[k]);
    }
    printf("\n");
}


int reverseWord(char *str, int start, int end){

    int len = end - start +1;
    char *rev = malloc(len*sizeof(char));
    printString(str,0,end);
    rev = strcpy(rev,str);
    reverseString(rev,0,len-1);
    int i, wStart, wEnd;
    wStart =wEnd = 0;

    for(i=0;i<len;){

        if(rev[i]!=' '){
            wStart = i;
            wEnd = i;
            while(rev[++i]!=' ' && i<len){
                wEnd++;
            }
            i++; // to avoid space
            if(i==len){
                wEnd = len-1;
            }
            reverseString(rev,wStart,wEnd);
        }
    }

    printString(rev,0,end);
}

int main()
{

    char * str = "Hello World ! How are you ?";
    reverseWord(str,0,strlen(str)-1);
    return 0;
}
