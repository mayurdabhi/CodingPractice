#include <stdio.h>
#include <stdlib.h>

int negate(int b){

    int d;
    int ans=0;

    d = (b<0)?1:-1;

    while(b!=0){
        ans += d;
        b += d;
    }
    return ans;
}

// a-b = a+ (-1)*b
int subtract(int a, int b){
    b = negate(b);
   // printf("%d\n",b);
    return a+b;
}

int absolute(int b){

    if(b<0){
        return negate(b);
    }
    else{
        return b;
    }
}

int multipication(int a, int b){

    if(a<b){
        return multipication(b,a);
    }

    if(a==0 || b==0){
        return 0;
    }

    int ans=0,i;

    int tempb = absolute(b);
    for(i=0;i<tempb;i++){
        ans += a;
    }

    if(b<0 && a<0 || a>0 && b>0)
        return ans;
    else
        return negate(ans);

}

int division(int a, int b){

    if(b==0){
        return -1;
    }

    int tempb = negate(b);
    int tempa = negate(a);

    if(a==0){
        return 0;
    }

    int d=1;

    while(tempa<=tempb+negate(b)){
        tempb += negate(b);
        d++;
    }

    if(a<0 && b<0 || a>0 && b>0){
        return 0;
    }
    else{
        return negate(d);
    }
}

int main()
{

    printf("Sub : %d - %d : %d\n",-15,8,subtract(-15,8));
    printf("Mul : %d * %d : %d\n",-15,8,multipication(-15,8));
    printf("Div : %d / %d : %d\n",-15,8,division(-15,8));
    return 0;
}
