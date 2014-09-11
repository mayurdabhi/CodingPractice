#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned int_to_int(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;                       /* optional */
    return (k % 2) + 10 * int_to_int(k / 2);
}

int insertMtoN(unsigned int m, unsigned int n, int i, int j){

    unsigned int allOne = ~0;
    //printf("%u\n",allOne);
    int temp = int_to_int(allOne);
    //printf("%d\n",temp);
    unsigned int rightMask;
    unsigned int leftMask, mask;

    rightMask = (allOne<<(j+1));

    leftMask = ((allOne<<i)-1);

//    printf("%d\n",rightMask);
 //   printf("%d\n",leftMask);

    mask = rightMask|leftMask;

   // mask = ~(((1 << (j - i + 1))-1)<<i);
   // printf("%d\n",mask);
    rightMask = (n&mask);
    leftMask = m<<i;
    n = rightMask|leftMask;

    printf("New Number : %d\n ",n);

    return n;
}


int getKthBit(int num, int k){

    num =  num &(1<<k);
    return num;
}

//list with numbers and n=last number
int FindMissingNumber(int list[], int n){

    int i,k,b,temp, Count1, Count0, ans=0;

    k=n;
    int even[k/2+1];
    int odd[k/2+1];
    int length = floor(log2(n));
    //printf("L:%d\n",length);
    for(b=0;b<=length;b++)
    {
        Count1=0;
        Count0=0;
//        printf("N : %d\n",n);
        for(i=0;i<n;i++){
            temp = getKthBit(list[i],b);
            printf("%dth bit of %d : %d\n",b,list[i],temp);
            if(!temp){
                even[Count0++] = list[i];
                //Count1++;
            }
            else{
                odd[Count1++] = list[i];
            }
        }
        printf("%d %d %d\n",Count0, Count1, ans);
        if(Count0<=Count1){

            list = even;
            n = Count0;

        }
        else{
                ans = ans|(1<<b);
//                printf("%d\n",ans);
                list = odd;
                n= Count1;
            //ans = ans&(~0<<b);
        }
    }
        printf("Missing Number : %d\n",ans);
}

int main()
{
    unsigned int n= 2048;
    unsigned int m = 19;
    //ans = 2124;
    insertMtoN(m,n,2,6);

    int i=2,j=6;
        int answer = n & ~(((1 << (j - i + 1)) - 1) << i);
        answer |= m << i;
        printf("%d\n", answer);

    int list[]={1,2,3,4,0,7,5,8};
    FindMissingNumber(list,8);
    return 0;
}
