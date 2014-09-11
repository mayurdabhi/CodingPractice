#include <stdio.h>
#include <stdlib.h>


int checkAnagram(char * str1, char * str2){

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    //length is not same , not a anagram
    if(len1 != len2){
        return 0;
    }

    int i;
    char check[256];
    for(i=0;i<256;i++){
        check[i]=0;
    }

    for(i=0;i<len1;i++){
        check[str1[i]]++;
        check[str2[i]]--;
    }

    for(i=0;i<256;i++){
        if(check[i]){
            return 0;
        }
    }
    return 1;
}


int main()
{

    char * str1 = "abcsfds";
    char * str2 = "abfssec";

    if(checkAnagram(str1,str2)){
        printf("Strings are anagram\n");
    }
    else{
        printf("Strings are not an anagram\n");
    }
    return 0;
}
