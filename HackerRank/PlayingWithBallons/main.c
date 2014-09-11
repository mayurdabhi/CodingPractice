#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int bucket[1000000] = {0};

long int totalCount(int pos1, int pos2){

    long int i;
    long long int sum=0;

    for(i=pos1;i<=pos2;i++){
        sum += bucket[pos1];
    }
    printf("%lld\n",sum);
}

void Update(int pos,int M,int plus)
{
    int N=1000000;  //1 million
    int i,j,k;
    for (i=1;i<=50;i++)
    {
        int back = pos;
        for(j=1;j<=1000;j++)
        {
            //add M water ballons at bucket pos
            if(pos>=0){
                bucket[pos] += M;
            }
            int s,in=__builtin_popcount(pos);
            for(k=0;;k++)
            {
                s=pos+pow(2,k);
                if( __builtin_popcount(s) <= in )
                {
                    in = __builtin_popcount(s);
                    pos = s;
                    if(pos>N)
                        break;

                    //add M water ballons at bucket pos
                    bucket[pos] += M;
                }
            }
            pos = pos - N;
        }
        pos = back+plus;
        if(pos>N) pos-=N;
    }
}

int main()
{

    long int q, pos1, pos2, pos, plus;
    long int i;
    int m;
    char op;

    scanf("%ld",&q);
   // op = getchar();
    for(i=0;i<q;i++){
     //   op = getchar();

            scanf("%c %ld %d %ld",&op,&pos,&m,&plus);
            Update(pos,m,plus);
       // if(op=='R'){
            scanf("%c %ld %ld",&op,&pos1,&pos2);

            totalCount(pos1,pos2);
        }
        //else{





    return 0;
}
