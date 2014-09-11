#include <stdio.h>
#include <stdlib.h>

int min(int a, int b){

    return (a<b)?a:b;
}

int SubsetHalfSum(int a[], int n){

        int k,i,j;

        k=0;

        for(i=0;i<n;i++){
            k+=a[i];
        }
        printf("Sum : %d\n",k);

        //exactly half sum needed, so k must be even.
        if(k%2 != 0){
            return 0;
        }
        int *Table = malloc((k+1)*sizeof(int));

        Table[0]=1;
        for(i=1;i<=k;i++){
            Table[i] = 0;
        }


        //O(nk)
        for(i=0;i<n;i++){
            for(j=k-a[i];j>=0;j--){
                printf("%d %d\n",j, Table[j]);
                if(Table[j]){
                    Table[j+a[i]]=1;
                }

            }
        }

        /*
        //O(nk) but without any unnecessary loop iteration
        int r=0;
        for(i=0;i<n;i++){
            for(j=r;j>=0;j--){
                printf("%d %d\n",j, Table[j]);
                if(Table[j]==1){
                    Table[j+a[i]]=1;
                    r = min(k/2,j+a[i]);
                }

            }
        }
        */
        printf("Subset Half Sum Exists? : %d\n",Table[k/2]);
        return Table[k/2];

}


int main()
{
    int a[] = {1,2,3,4,5,7};
    SubsetHalfSum(a,6);
    return 0;
}
