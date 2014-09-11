#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50


void modifyString(char str[], int n){

	int i,j;
	i=0;

	//O(n)
	for(j=0;j<n;j++){
		//check here
		if(str[j]!= 'A' && str[j]!= 'I'){
           // printf("%c",str[j]);
			str[i++]=str[j];
		}
	}
	str[i]='\0';
	//printf("\n%s\n",str);
}

int main(){

	char inputString[SIZE];
	//length of string
	int n;

	//scan string from input
	//use gets as it will automatically assign null after reading string
	//scanf will put garbage values
	// scanf("%[^\n]",inputString);
	gets(inputString);

	n = strlen(inputString);
	//Call function to remove A and I from string
	modifyString(inputString,n);;
	printf("%s\n",inputString);


}
