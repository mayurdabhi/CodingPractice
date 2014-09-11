#include <stdio.h>
#include <stdlib.h>

#define N 4
#define FOR(e,a,b) for(e=a;e<b;e++)

int findBooleanParenthesis(char syml[],char oper[],int n){

    int i,j,k,g, gap, Tik,Tkj;
    int t[N][N], f[N][N];

    FOR(i,0,n){

        FOR(j,0,n){
            t[i][j]=0;
            f[i][j] = 0;
        }
    }



    FOR(i,0,n){

        t[i][i] = (syml[i]=='T')?1:0;
        f[i][i] = 1 - t[i][i];
       // f[i][i] = (syml[i]=='F')?1:0;
    }

    //Complexity O(n^3)
    FOR(gap,1,n){

        for(i=0,j=gap;j<n;j++,i++){

            t[i][j] = f[i][j] = 0;
            FOR(g,0,gap){

                k = i + g;

                Tik = t[i][k] + f[i][k];
                Tkj = t[k+1][j] + f[k+1][j];

                if(oper[k]=='&'){
                    t[i][j] += t[i][k]*t[k+1][j];
                    f[i][j] += Tik*Tkj - t[i][k]*t[k+1][j];
                }
                else if(oper[k]== '|'){
                    t[i][j] += Tik*Tkj - f[i][k]*f[k+1][j];
                    f[i][j] += f[i][k]*f[k+1][j];
                }
                else if(oper[k] == '^' ){
                    t[i][j] += t[i][k]*f[k+1][j] + f[i][k]*t[k+1][j];
                    f[i][j] += t[i][k]*t[k+1][j] + f[i][k]*f[k+1][j];
                }

            }

        }
    }

    FOR(i,0,n){

        FOR(j,0,n){
            printf("%d ",t[i][j]);
        }
        printf("\n");
    }

    return t[0][n-1];

}

int main()
{

    char Syml[] = {'T','T','F','T'};
    char Oper[] = {'|','&','^'};

    int k =  findBooleanParenthesis(Syml,Oper,4);
    printf("Number of Boolean parenthesis : %d\n",k);
    return 0;
}
