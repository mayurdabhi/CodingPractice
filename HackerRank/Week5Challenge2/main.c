#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int FindClosestNumber( long int a,  long int b,  long int x){

 /*   if(b<=0){
        return 0;
    }
*/

    long int temp, mod ;

    temp = pow(a,b);
    mod = temp%x;
    printf("%ld %ld %ld %ld ", a, b, temp, mod);

    if(mod<=(x/2)){
            return temp - mod;
    }
    else{
        return temp+x-mod;

    }

}

int main()
{

    int testcases,i;
    long int x,a,ans;

    long int b;

    scanf("%d",&testcases);

    for(i=0;i<testcases;i++){
        scanf("%ld %ld %ld",&a,&b,&x);

        ans = FindClosestNumber(a,b,x);
      //  printf("%ld\n",ans);
    }
    return 0;
}
