#include <stdio.h>
#include <stdlib.h>

int clearBit(int num, int k){

    int temp = ~(1<<k-1);
    num = num & temp;
    printf("Num : %d\n",num);
    return num;
}

int setBit(int num, int k){
    int temp = (1<<(k-1));
    num = num|temp;
    printf("Num : %d\n",num);
    return num;
}

int checkBit(int num, int k)
{
    int temp = (1<<k-1);
    num = num & temp;
    printf("Num : %d\n",num);
    return num;
}

int toggleBit(int num, int k){
    int temp = (1<<k-1);
    num = num ^ temp;
    printf("Num : %d\n",num);
    return num;
}

int toggleLSB(int num, int k){

    int temp = num+1;
    num = num & temp;
    printf("Num : %d\n",num);
    return num;
}

unsigned int reverseBits(unsigned int num)
{
    unsigned int count = sizeof(num) ;//* 8 - 1;

    unsigned int reverse_num = 0;
    //num >>= 1;

    //
    while(num)
    {
       reverse_num <<= 1;
       reverse_num |= num & 1;
       num >>= 1;
       count--;
    }
    reverse_num <<= count;

    printf("Reverse of number : %u\n",reverse_num);
    return reverse_num;
}

int ReverseNumber(unsigned int n){

    unsigned int temp=0;
    unsigned int s = sizeof(n)-1;
    /*

    //Log(n)
    for(;n;){
        temp = temp<<1;
        printf("%u %u\n",temp,n&1 );
        temp = temp|n&1;
        s--;
        n >>=1;
    }
    temp<<=s;
    */

    //Log(n)

    int  i ;

    //travers through all bit, if ith bit is set, set (s-i) bit in output
    for(i=0;i<=s;i++){
        if(n& (1<<i)){
            temp |= (1<<(s-i));
        }
    }

    printf("Reverse of number : %u\n",temp);
    return temp;
}

int countOnes(int num){

    int count=0;
    int temp = num;
    //O(n)
    /*
    while(num){

        if(num&1)
            count++;

        num>>=1;
    }
    */

    //O(n)
    /*
    while(num){
        if(num%2==1){
            count++;
        }
        num/=2;
    }
    */

    //O(k)  k=number of 1

    while(num){

        count++;
        num &=num-1;
    }
    printf("No of 1's in %d : %d\n",temp,count);
    return count;
}

int MaskingTrailingZero(int n){

    unsigned int twoComp = ~n + 1;

    printf("%d\n",twoComp);
    int temp =  (n&twoComp)-1;

    printf("Trailing Zero : %d\n",temp);
    return temp;
}

int main()
{
    unsigned int num=4;
    setBit(num,2);
    toggleLSB(num,1);
    reverseBits(num);
    ReverseNumber(num);
    countOnes(num);
    MaskingTrailingZero(num);

     int i = 0;
    do
    {
        printf("GeeqsQuiz ");
        i = i++;
    }
    while (i < 5);

    return 0;
}
