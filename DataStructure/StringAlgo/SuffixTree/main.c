#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct suffixTree suffix;

struct suffixTree{

    int index;
    char *suff;
};

int comp(suffix a, suffix b){

    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}

int * createSuffixTree(char * str){

    int n = strlen(str);
    int i;
    suffix *suffixList = (suffix *) malloc(n*sizeof(suffix));

    assert(suffixList!=NULL);

    for(i=0;i<n;i++){
        suffixList[i].index=i;
      //  suffixList[i].suff = NULL;
       // suffixList[i].suff = malloc((n-i)*sizeof(char));
        //assert(suffixList[i].suff!=NULL);
        suffixList[i].suff = (str+i);
        printf("%d %s\n",suffixList[i].index, suffixList[i].suff);
    }

    assert(i==n);
    qsort((suffix *)suffixList,n,(sizeof(suffix)),comp);

    int * suffArray = (int *)malloc(n*sizeof(int));

    assert(suffArray!=NULL);

    for(i=0;i<n;i++){
        suffArray[i] = suffixList[i].index;
        printf("%d %s\n",suffixList[i].index, suffixList[i].suff);
    }

    return suffArray;
}

void printArray(int a[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}

int search(char * pattern, char * str,  int *suffixArray, int n){

    int l,r, mid;
    int m = strlen(pattern);
    l=0;
    r = n-1;

    while(l<=r){

        mid = l + (r-l)/2;

        printf("%s\n",str+suffixArray[mid]);
        int res = strncmp(pattern,str+suffixArray[mid],m);

        if(res == 0){
            printf("pattern found at %d\n",suffixArray[mid]);
        }

        if(res<0){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }

    printf("Pattern not found\n");

}

int main()
{
    char * str = "BANANA";

    char * pat = "NAN";

    int * strarray =  NULL;
    strarray = createSuffixTree(str);

    printArray(strarray,6);
    search(pat,str,strarray,6);



    return 0;
}
