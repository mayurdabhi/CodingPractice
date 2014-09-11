#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Brute force Algorithms
int matchSubString(char a[], int n, char s[], int m){

    int i,j,k,flag;
    flag =0;

    // here we need to check for n-m+1 times, as substring length is m.
    for(i=0;i<n-m+1;i++){

        for(j=0;j<m;j++){
            if(a[i+j]!=s[j]){
                break;
            }
        }
        if(j==m){
            flag =1;
            break;
        }
    }

    if(flag){
        //printf("Sub String Exists\n");
        return 1;
    }

    return 0;
}

//Robin Karp String Matching Algorithm
//Input string need to be have value such that it can be represent between 0..9
int RobinKarpSubString(char a[],int n, char s[], int m){

    int i, valSub, valStr, flag;

    valSub=0;
    valStr=0;
    flag = 0;

    for(i=0;i<m;i++){
        valSub *=10;
        valSub += (s[i]-48);
    }


    for(i=0;i<m;i++){
        valStr *=10;
        valStr += (a[i]-48);
    }

    for(i=0;i<n-m+1;i++){

        if(i>0){
            int temp  = 10*(valStr - pow(10,(m-1))*(a[i-1]-48));

            valStr = temp+(a[i+m-1]-48);
        }

        if(valStr == valSub){
            flag =1;
            break;
        }
    }

    if(flag){
        return 1;
    }
    else{
        return 0;
    }
}
//Robin Karp Algo (GeeksforGeeks Solution)

#define d 256
void searchPattern(char *pat, char *txt, int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int i, j;
    int p = 0;  // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M-1; i++)
        h = (h*d)%q;

    // Calculate the hash value of pattern and first window of text
    for (i = 0; i < M; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++)
    {

        // Chaeck the hash values of current window of text and pattern
        // If the hash values match then only check for characters on by one
        if ( p == t )
        {
            /* Check for characters one by one */
            for (j = 0; j < M; j++)
            {
                if (txt[i+j] != pat[j])
                    break;
            }
            if (j == M)  // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            {
                printf("Pattern found at index %d \n", i);
            }
        }

        // Calulate hash value for next window of text: Remove leading digit,
        // add trailing digit
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it to positive
            if(t < 0)
              t = (t + q);
        }
    }
}

//KMP algorithm

int computePrefixFun(char *pat,int m, int *lps){

    int i,len;

    len=0;
    lps[0]=0;
    i=1;

    while(i<m){

        if(pat[i]==pat[len]){
            lps[i]=len++;
            i++;
        }
        else{
            if(len!=0){
                len =lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
}

int KMPAlgo(char *pat, char * str){

    int m= strlen(pat);
    int n = strlen(str);
    char * lps = malloc(m*sizeof(char));

    int i ,j;

    j=0;i=0;

    computePrefixFun(pat,m,lps);

    while(i<n){
        if(pat[j]==str[i]){
            i++;
            j++;
        }

        if(j==m){
            printf("Substring Pattern found at %d\n",i-j);
            j=lps[j-1];
        }
        else if(pat[j]!=str[i])
        {

            if(j!=0){
                j = lps[j-1];
            }
            else{
                i++;
            }
        }
    }

    return 0;
}

int main()
{
    int ans;

    //char * str = "may mayur hello";
    //char * subStr = "mayrr";

    char * str = "ASDSAASSDA";
    char * subStr = "SAAS";

    //ans = matchSubString(str,15,subStr,5);
/*
    ans = RobinKarpSubString(str,6,subStr,3);
    if(ans){
        printf("Substring Exists\n");
    }
    else{
        printf("Substring doesn't exists\n");
    }

    searchPattern(subStr,str,101);
*/

    KMPAlgo(subStr,str);

    return 0;
}
