#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 16

//fun to validate ip
//argument : IP Address
int validateIP(char ip[]){

	char buf[4]; //buffer to keep single block
	int num;
	int count=0;
	int n = strlen(ip);
	int i,j;
	j=0;
	for(i=0;i<n;i++){

		if(ip[i]!='.' && ip[i]>47 && ip[i]<58){
			buf[j++]=ip[i];
		}
		else{

			if(j>3 || ip[i]!='.'){

				return 0;
			}
		}

		if(i==n-1 || ip[i]=='.')
		{
				buf[j]='\0';
				num = atoi(buf);
				printf("%d ",num);

				if(num >255){
					return 0;
				}
				count++;
				j=0;
			}

	}

	if(count==4)
		return 1;
	else
		return 0;
}



int main(){

	char ip[SIZE];

	gets(ip);
	//validate fun call
	if(validateIP(ip)){
		printf("VALID:%s\n",ip);
	}
	else{
		printf("INVALID:%s\n",ip);
	}

    return 0;
}

