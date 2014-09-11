#include <stdio.h>
#include <stdlib.h>


int checkAllUniqueChar(char * str){

	char * temp  =str;
//	temp = str;

	int n = strlen(temp);
	printf("%d\n",n);
	while(*str != '\0'){
		temp = str;
		//temp++;
		printf("%s\n", temp);

		while(*++temp != '\0'){
		//	printf("%c:%c\n",*str,*temp);
			if(*temp == *str){
				return 0;
			}

			//temp++;
		}
		str++;

	}
	return 1;
}

void compressString(char *str){

    int len = strlen(str);
	char *output = malloc(sizeof(char)*len+1);
    output[len+1]='\0';
	char *buff = str;
	char *temp ;
	char prevChar;
	int count = 0;
	int i=0;

	printf("%s\n",str);

	while(*str){

		prevChar = *str;
		str++;
		//printf("%c\n", prevChar);
		count++;
		while(prevChar == *str){
			//printf("%d\n", count);

			count++;
			str++;

		}

		output[i++]=prevChar;
        //output++;
		count;
		printf("%s\n",output);
		output[i++]=(char)temp;
		/*while(*temp){
            output[i++]= *temp++;
		}*/
		//strcat(output,(char *)prevChar);
		count = 0;
	}
	output[i]='\0';
	//*output = '\0';
	printf("%s\n",output);
	//strcat(*output,'\0');
	//++*output = '\0';

	if(strlen(output) > len)
		printf("%s\n",buff);
	else
		printf("%s\n",output);
}

int main (){

	char * testString = "HHHello World";
/*
	if(checkAllUniqueChar(testString) == 0 ){

		printf("String Contains Duplicate Characters\n");
	}
	else
	{
		printf("String Contains All Unique Characters\n");
	}
*/
	compressString(testString);
	//printf("%s\n", testString);
	return 0;
}
