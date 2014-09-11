#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a[11] = {1,1,2,3,4,4,4,3,2,3,1};

    int i,ans=0,n =11, range =4;

    for(i=0;i<n;i++){
        ans ^= a[i];
    }
    for(i=1;i<=range;i++){
        ans^=i;
    }

    printf("Twice Repeated Number : %d\n",ans);

    return 0;
}
