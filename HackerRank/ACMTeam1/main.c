#include <stdio.h>
#include <stdlib.h>

int comp(long long int a, long long int b){

    return a-b;
}

/*
int numberOfOnes(long long int n){
    int count=0;
    /*while(n!=0){
        n = n&(n-1);
        count++;
    }
//    for(i=0;)
    return count;
}
*/


int numberOfOnes(char * str1, char * str2, int m){
    int i, count=0;
    for(i=0;i<m;i++){
        if(str1[i]=='1' || str2[i] == '1')
            count++;
    }
    return count;
}

int main() {

    int n,m;

    scanf("%d %d",&n, &m);

    long long int * skills = malloc(n*(sizeof(long long int)));
    long long parsed;
    int i,j;
    char str[500][500];

    for(i=0;i<n;i++){
        char * ptr;
        scanf("%s",str[i]);

        //parsed = strtoll(str, & ptr, 2);
        // printf("%llX\n", parsed);
        //skills[i] = parsed;
    }

//    qsort(skills,n,sizeof(skills[0]),comp);

    long long maxteam=0;
    long long maxskill=0;
    long long  temp;
    for(i=0;i<n;i++){

        for(j=i+1;j<n;j++){

            temp = numberOfOnes(str[i],str[j],m);
            if(temp>maxskill){
                maxskill=temp;
                maxteam =1;
            }
            else if(temp == maxskill){
                maxteam++;
            }

        }
    }

  //maxskill = numberOfOnes(maxskill);
    printf("%lld\n%lld\n",maxskill,maxteam);

    return EXIT_SUCCESS;
}
