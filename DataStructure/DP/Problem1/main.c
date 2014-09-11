#include <stdio.h>
#include <stdlib.h>

long int result[100] = {0};

long int findRecurrenceResult(int n){

    int i;
    long sum = 0;
    if(n==0 || n==1){
     //   result[1]=result[0]=2;
        return 2;
    }
    else if (result[n]!=0){
        return result[n];
    }

    for(i=1;i<n;i++){

        sum = sum + (2*findRecurrenceResult(i)*findRecurrenceResult(i-1));
    }
    result[n] = sum;

    return result[n];

}

int main()
{

    printf("Recurrence Result of 10 : %ld\n",findRecurrenceResult(4));

    printf("Recurrence Result of 8 : %ld\n",findRecurrenceResult(8));
    return 0;
}
