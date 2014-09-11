#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

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
    suffix *suffixList = new suffix[n];//(suffix *) malloc(n*sizeof(suffix));

    //assert(suffixList!=NULL);

    for(i=0;i<n;i++){
        suffixList[i].index=i;
      //  suffixList[i].suff = NULL;
       // suffixList[i].suff = malloc((n-i)*sizeof(char));
        //assert(suffixList[i].suff!=NULL);
        suffixList[i].suff = (str+i);
       cout<<suffixList[i].index<<" "<<suffixList[i].suff<<endl;
    }

//    assert(i==n);
    sort(suffixList,suffixList+n,comp);

    int * suffArray = (int *)malloc(n*sizeof(int));

  //  assert(suffArray!=NULL);

    for(i=0;i<n;i++){
        suffArray[i] = suffixList[i].index;
       cout<<suffixList[i].index<<" "<<suffixList[i].suff<<endl;
    }

    return suffArray;
}

void printArray(int a[], int n){
    int i;
    for(i=0;i<n;i++){
    //    printf("%d ",a[i]);
        cout << a[i] << " ";
    }
    cout<<endl;
//    printf("\n");
}

int search(char * pattern, char * str,  int *suffixArray, int n){

    int l,r, mid;
    int m = strlen(pattern);
    l=0;
    r = n-1;

    while(l<=r){

        mid = l + (r-l)/2;

        int res = strncmp(pattern,str+suffixArray[mid],m);

        if(res == 0){
                cout<<"Found"<<endl;
            return 0;
  //          printf("pattern found at %d\n",suffixArray[mid]);
        }

        if(res<0){
            r = mid-1;
        }
        else{
            l=mid+1;
        }
    }
                cout<<"Not Found"<<endl;
//    printf("Pattern not found\n");

}

int main()
{
    char * str = "BANANA";

    char * pat = "BAAN";

    int * strarray =  NULL;
    strarray = createSuffixTree(str);

    printArray(strarray,6);
    search(pat,str,strarray,6);



    return 0;
}
