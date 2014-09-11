#include <stdio.h>
#include <stdlib.h>


long int fibo[100]= {0};
long long int fact[100] = {0};


long long int factorial(int n){

    if(n==0){
       fact[n]=1;
       return 1;
    }
    else if(n==1){
        fact[n] = 1;
        return 1;
    }
    else if(fact[n] != 0){
        return fact[n];
    }
    else{
        fact[n] = n*factorial(n-1);
    }
    return fact[n];
}

long int fibonacci(int n){

    if(n==0){
        fibo[n] = 1;
        return 1;
    }
    else if(n==1){
        fibo[n]=1;
        return 1;
    }
    else if(fibo[n] != 0){
        return fibo[n];
    }
    else{
        fibo[n] = fibonacci(n-1)+fibonacci(n-2);
    }

    return fibo[n];
}


int main()
{
    //printf("Hello world!\n");

    long int ans = fibonacci(60);
    printf("Fibo of 16 :%ld\n",ans );

    long long int ans2 = factorial(40);
    printf("Fact of 16 :%lld\n",ans2 );
    return 0;
}
