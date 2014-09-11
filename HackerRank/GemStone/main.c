#include <stdio.h>
#include <stdlib.h>

int findGemStone(char *str, int output[], int i){

    char *temp  = str;
    int k;
    while(*temp!='\0'){
      k = (*temp) - 97;

      if(output[k] == i)
      {
        output[k]++;
      }
      temp++;

    }
    return 0;
/*
    for(k=0;k<26;k++){
        printf("%d ",output[k]);
    }
    printf("\n");
    */
}

int main()
{

    //printf("Hello world!\n");
    char *inputStone;// = (char*)malloc(sizeof(char)*100*100);
    int stone,i,count=0;

    int outputHash[26]={0};

    scanf("%d",&stone);

    for(i=0;i<stone;i++){
        scanf("%s",inputStone);
        //printf("%s",inputStone);
        findGemStone(inputStone,outputHash,i);
    }

    for(i=0;i<26;i++){
        if(outputHash[i]==stone){
            count++;
        }
    }

    printf("%d\n",count);
    return 0;
}
