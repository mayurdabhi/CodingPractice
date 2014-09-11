#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10

int compChar(const void *c1, const void *c2){

    //printf("%c %c\n",*(char *)c1,*(char *)c2);
    return (*(char *)c1 - *(char *)c2);
 //   return ;
}
int min(int a, int b){
    return (a<b)?a:b;
}

int compStr(const void *s1, const void *s2){

    int l1,l2;
    l1 = strlen(s1);
    l2=strlen(s2);

    if(l1!=l2){
        return  (l1 == min(l1,l2))?-1:1;
    }

    char t1[M];
    char t2[M];
    strcpy(t1,s1);
    strcpy(t2,s2);
    //As here another time nlogn time will taken by qsort,
    //which increase time complexity

    //qsort(t1,strlen(t1),1,compChar);
    //qsort(t2,strlen(t2),1,compChar);

    //to reduce timecomplexity to n
    //assume that only alphabets r in words, no special symbol (when using c, as no hashmap is present)
    int map[26]={0};
    int i;

    for(i=0;i<l1;i++){
       map[t1[i]-97] +=1;
       map[t2[i]-97] -=1;
       //printf()
    }
    printf("comparing %s , %s\n",s1,s2);
    for(i=0;i<26;i++){

        if(map[i]!=0){
            //printf("returning %d\n",map[i]);
            return map[i];
            //return strcmp(t1,t2);
        }
    }

    return 0;
  //  return strcmp(t1,t2);
}

int sortAnagram(char str[][M],int n){

    qsort(str,n,M*sizeof(char),compStr);
    int i;
    for(i=0;i<n;i++){
        printf("%s\n",str[i]);
    }
}

int main()
{
    char str[][M] = {
                        "cat", "let","bat","tab","tac","act","tel","hi","ih"
                    };

    sortAnagram(str,9);
    return 0;
}
