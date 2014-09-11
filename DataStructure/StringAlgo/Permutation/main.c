#include <stdio.h>
#include <stdlib.h>

void swap(char *a, char *b){

    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

//Recursive O(n*n!)
int permutation(char *str, int i, int n){

    int j;

    if(i==n-1){
        printf("%s\n",str);
    }
    else{

        for(j=i;j<n;j++){
            //To avoid multiple occurance of same string when char r repeated
            // wont work in case like 1122
            if(*(str+i)==*(str+j) && i!=j)
                continue;

            swap((str+i),(str+j));
            permutation(str,i+1,n);
            swap((str+i),(str+j));
        }
    }
}

void permut(int depth, char * perm, int * used, char * original){

    int length = strlen(original);
    //printf("%d\n",length);
    if(depth == length){
        printf("%s\n",perm);
    }
    else{
        int i;
        for(i=0;i<length;i++){
            if(!used[i]){
                used[i]=1;
                perm[depth] = original[i];
                permut(depth+1,perm,used,original);
                used[i]=0;
            }
        }
    }
}

int main()
{
  //  printf("Hello world!\n");
   char a[] = "123";
   //permutation(a, 0, 4);
   char perm[4];
   int used[4];
   int i;
   for(i=0;i<4;i++){
        perm[i]='0';
        used[i]=0;
   }
   permut(0,perm,used,a);

    return 0;
}
