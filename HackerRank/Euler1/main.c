#include <stdio.h>
#include <stdlib.h>

long long int calculateDivisiorSum(long int n){
    long long int temp1, temp2, temp3;

    temp1 = n/3;
    temp2 = n/5;
    temp3 = n/15;

    temp1 = (temp1*(temp1+1)*3)/2;
    temp2 = (temp2*(temp2+1)*5)/2;
    temp3 = (temp3*(temp3+1)*15)/2;

    return (temp1+temp2-temp3);

}

int main()
{
    int t,i;
    long int n;



    scanf("%d",&t);

    for(i=0;i<t;i++){
        scanf("%ld",&n);
        printf("%lld\n",calculateDivisiorSum(n-1));
    }
    return 0;
}
