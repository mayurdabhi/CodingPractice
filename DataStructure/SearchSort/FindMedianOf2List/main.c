#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max (int a, int b){

    return (a<b)?b:a;
}

int min (int a, int b){

    return (a<b)?a:b;
}


int FindMedianOf2List(int a[], int b[], int n){

    int i1,i2,j1,j2;
    int temp1, m2,m1, t1,t2;

    i1=i2=0;
    j1=j2=n-1;
    temp1=n;
    m1=m2=-1;

    if(n<=0){
        return -1;
    }

    while(1){

        if(temp1==1){
            return (a[i1]+b[i1])/2;
        }

        if(temp1==2){

            int m = max(a[i1],b[i2]);
            int n = min (a[j1],b[j2]);
            return (m+n)/2;
        }

        t1 = (-i1+j1)/2 + i1;
        t2 = (-i2+j2)/2 + i2;
        printf("i1:%d %d, i2 = %d %d\n",i1,j1,i2,j2);
        if(temp1%2==0){
            m1 = (a[t1] + a[t1+1])/2;
            m2 = (b[t2] + b[t2+1])/2;
            temp1 = temp1/2;
        }
        else{
            m1 = a[t1];
            m2 = b[t2];
            temp1 = temp1/2;
        }

        printf("m1: %d m2: %d \n",m1,m2);
        printf("temp1 = %d\n",temp1);
        printf("t1: %d t2: %d \n",t1,t2);
        if(m1==m2){
            return m1;
        }

        //if(temp%2==0)
        {
            if(m1<m2){
                i1 = t1+1;
                j2 = t2-1;
            }
            else if(m1>m2){
                j1 = t1-1;
                i2 = t2+1;
            }
        }

        printf("i1:%d %d, i2 = %d %d\n",i1,j1,i2,j2);
    }

}

int getMedian(int ar1[], int ar2[], int n)
{
    int m1; /* For median of ar1 */
    int m2; /* For median of ar2 */

    /* return -1  for invalid input */
    if (n <= 0)
        return -1;

    if (n == 1)
        return (ar1[0] + ar2[0])/2;

    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;

    m1 = median(ar1, n); /* get the median of the first array */
    m2 = median(ar2, n); /* get the median of the second array */

    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;

     /* if m1 < m2 then median must exist in ar1[m1....] and ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        else
            return getMedian(ar1 + n/2, ar2, n - n/2);
    }

    /* if m1 > m2 then median must exist in ar1[....m1] and ar2[m2...] */
    else
    {
        if (n % 2 == 0)
            return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
        else
            return getMedian(ar2 + n/2, ar1, n - n/2);
    }
}

/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int main()
{

    int a[] = {1,3,5,7,9,11};
    int b[] = {2,4,6,8,10,12};
  //  int ans = FindMedianOf2List(a,b,5);
    int ans = getMedian(a,b,6);
    printf("Median of 2 List : %d\n",ans);
    return 0;
}
