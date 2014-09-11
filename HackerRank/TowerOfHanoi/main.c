#include <stdio.h>
#include <stdlib.h>

int toh(int n, char src, char dest, char aux){

    if(n==1){
        printf("Move disk 1 from %c to %c\n",src,dest);
        return 0;
    }

    toh(n-1,src,aux,dest);
    printf("Move disk %d from %c to %c\n",n,src,dest);
    toh(n-1,aux,dest,src);

    return 0;

}
int main()
{
    toh(4,'A','B','C');

    return 0;
}
