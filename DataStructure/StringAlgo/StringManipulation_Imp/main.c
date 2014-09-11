#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    //Scannign with space
    /*
    char str1[80];
    gets(str1);

    printf("%s\n",str1);
    printf("%d %d\n",sizeof(str1),strlen(str1));
    //free extra memory
    char * sCopy;
    sCopy = malloc((strlen(str1))*sizeof(char));
    strcpy(sCopy,str1);
    printf("\n%s\n",sCopy);
    printf("%d %d\n",sizeof(sCopy),strlen(sCopy));
    */
    //Scanning string with space
    /*
    char str[80];
    scanf("%[^\n]",str);
    printf("\n%s\n",str);
    printf("%d %d\n",sizeof(str),strlen(str));
    int i;
    for(i=0;i<sizeof(str);i++){

        printf("%c\n",*(str+i));
    }

*/

    //Sprintf()

    char * str = "Pilani ";
    int pin = 333031;
    char output[20];
    sprintf(output,"%s = %d",str,pin);

    puts(output);

    //RunLength Encoding

    char *input1 = "mmmaaayyyyyyuuuuuuuuuuuuuuuuuuuuuur";

    int n =  strlen(input1);
    char *result1 = malloc(sizeof(char)*(n+1)*2);
   // result1 = '\0';
    char temp[50];
    int i=0,j=0, count = 0;;

    while(i<n){
        printf("i : %d\n",i);
        result1[j++] = input1[i];
        count=1;
        result1[j] = '\0';
        while((i<n) && (input1[i]==input1[i+1])){
            i++;
            count++;
        }
        printf("count :%d\n",count);
        sprintf(result1, "%s%d",result1,count);
        //strcat(result1,temp);
        i++;
        count=0;
        printf("%s\n",result1);
        j = strlen(result1);


    }

    puts(result1);


    //Program to insert string at desired position

    char input[50];
    char subString[50];
    char result[100];
    int position=0;

    printf("Insert 1st String :\n");
    gets(input);
    printf("Insert 2nd String :\n");
    gets(subString);

    printf("\nInsert desired position to insert\n");
    scanf("%d",&position);
    strncpy(result,input,position);
    result[position]='\0';
    printf("Result String : %s\n",result);
    strcat(result,subString);
    printf("Result String : %s\n",result);
    int k = strlen(input)-position;
    strncpy(input,strrev(input),k);
    input[k]='\0';
    strcat(result,strrev(input));
    printf("Result String : %s\n",result);



    return 0;
}
