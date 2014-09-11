#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define size 100000

int A[size];
long int find(long int x,long int y)
{
    printf("x y :%ld %ld\n",x,y);
    int ans,temp;
    if(x>y) return 1;

    if(A[x-1]==0){
        return 0;
    }

    temp = find(x+1,y);
    ans = pow(A[x-1],temp);

    if(ans%2==0){
        return 2;
    }
    else{
        return 1;
    }

/*    ans = pow(A[x-1],find(x+1,y));
        printf("ans : %ld\n",ans);
    return ans;
    */
}

int main()
{

    long int q;
    long int i,n, x,y;
    long int temp;
    scanf("%ld",&n);

    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        printf("%d\n",A[i]);
       // scanf("%c",)
    }
    scanf("%ld",&q);

    for(i=0;i<q;i++){
        scanf("%ld %ld",&x,&y);
        printf("%ld %ld\n",x,y);
        temp = find(x,y);
        printf("%ld \n",temp);

        if(temp == 2||temp==0){
            printf("Even\n");
        }
        else{
            printf("Odd\n");
        }
    }

    return 0;
}
