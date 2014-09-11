#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printString(char str[], int len){
    int k;
/*    for(k=0;k<len;k++){
        printf("%c",str[k]);
    }
    */
    printf("%s",str);
    printf("\n");
}

char * removeAdjacentChar(char b[]){

    int i,j,len;

    len =  strlen(b);
    char * a = malloc(len*sizeof(char));
   // char a[len];
    strcpy(a,b);
    printf("%s",a);
    j=0;

    for(i=1;i<len;i++){

        while(*(a+i)==*(a+j) && (j>=0)){
            i++;
            j--;
        }
      //  printf("%c %c\n",a[j++],a[i]);
         j++;
        *(a+j) = *(a+i);
       //a[j]=a[i];
    }
//    a[j+1]='\0';
    *(a+j+1)= '\0';

    printf("%s\n",a);
   // return a;
}

int main()
{
    char *str = "abbacd";
    printString(str,8);
   str =  removeAdjacentChar(str);
    printString(str,8);
    return 0;
}
