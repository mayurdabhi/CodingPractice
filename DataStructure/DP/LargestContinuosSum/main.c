#include <stdio.h>
#include <stdlib.h>


//Time complexity : O(n)
int LargestContinuousSum(int a[], int n){

    int max_so_far, max_here,i;

    max_so_far = a[0];
    max_here = a[0];

    for(i=1;i<n;i++){
        max_here += a[i];

        if(max_here < 0 ){
            max_here= 0;
        }
        else if(max_here>max_so_far){
            max_so_far = max_here;
        }
    }


    //To handle case when all element are negative:

    if(max_so_far<0){
            max_so_far = a[0];
         for(i=1;i<n;i++){
            if(a[i]>max_so_far){
                max_so_far = a[i];
            }
         }
    }

    printf("MaxSUM : %d\n", max_so_far);
    return max_so_far;
}


//Using DP
int maximum(int a, int b){
    return (a>b)?a:b;
}

int maxContiniousSum(int a[], int n){

    int curr_max,i,  max;
    curr_max= a[0];
    max = a[0];

    for(i=1;i<n;i++){
        curr_max = maximum(curr_max,curr_max + a[i]);
        max = maximum(max,curr_max);
    }

    return max;
}
int main()
{

   int a[] = {-2, -3, -4, -1, -2, -1, -5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   int max_sum = LargestContinuousSum(a, n);
   printf("Maximum Conti sum: %d\n",max_sum );
   max_sum = maxContiniousSum(a,n);
   printf("Maximum Conti sum (DP) : %d\n",max_sum );
    return 0;
}
