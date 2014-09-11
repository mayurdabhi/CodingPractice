#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include<cstdlib>
using namespace std;


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
    char *rev = (char *)malloc(len*sizeof(char));
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

    string str;
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0;i<n;i++){

        getline(cin,str);

//
        char * cstr = new char [str.length()+1];
        std::strcpy (cstr, str.c_str());
        reverseWord(cstr,0,strlen(cstr)-1);
        delete cstr;

    }

    return 0;
}
