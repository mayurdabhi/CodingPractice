#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

void printArray(int a[], int length)
{
    int i;
    printf("\n****Array*****\n");
    for(i=0;i<length;i++){
        printf("%d ",a[i]);
    }
    printf("\n**************\n");
}

void swap (int *a, int *b){

    int temp;

    temp = *a;
    *a= *b;
    *b= temp;
    return;
}


void heapify(int* a, int length, int ind){

    int i,j,maxTemp;

    maxTemp = ind;

    i=ind*2+1;
    j=(ind+1)*2;

    if(i<length && *(a+i)>*(a+maxTemp)){
        maxTemp=i;
    }

    if(j<length && *(a+j)>*(a+maxTemp)){
        maxTemp = j;
    }

    if(maxTemp!=ind){
        printf("Swapping %d %d\n",*(a+maxTemp),*(a+ind));
        swap(&a[maxTemp], &a[ind]);
       // printArray(a,length);
        heapify(a,length,maxTemp);
    }

   // printArray(a,length);
}

void heapSort(int a[], int length){

    int i;
    //for(i=0;i<(length-1)/2;i++){
    for(i=(length-1)/2;i>=0;i--){
        heapify(a,length,i);
    }

    int tempLength = length;
    for(i=length-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,--tempLength,0);

    }
    printArray(a,length);
}

//Problem 8

//add array size to each index
int FindMaxCount(int a[]){
    // a element value range[1.. n-1]
    int n=6;//sizeof(a)/sizeof(a[0]);
 printf("size of array :  %d %d\n",sizeof(a),sizeof(a[0]));
    int i,ind,max = -1;

    for(i=0;i<n;i++){
        a[a[i]%n]+=n;
    }

    printArray(a,n);

    for(i = 0; i<n;i++){

        if(a[i]/n > max){
            max= a[i]/n;
            ind=i;
        }
    }
    return ind;

}

//Problem 9

int findFirstRepeatedElement(int a[], int size, int range){

    int* hash = malloc((range+1)*sizeof(int));
    int i, max = -100, value;
    for(i=1;i<=range;i++){
        hash[i] = -100;
    }

    for(i=0;i<size;i++){
        if(hash[a[i]] == -100){
            hash[a[i]]=a[i];
        }
        else if(hash[a[i]]>0){
            hash[a[i]] = -hash[a[i]];
        }
    }

    value = 0;
    for(i=1;i<=range;i++){
        //find max negative value index
        if((hash[i]<0) && (hash[i]>max)){
            max = hash[i];
            value = i;
        }
    }

    printf("First Repeated Element : %d\n",value);
}


//Problem 16
int FindMissingNumber(int a[],int size){

    int sum = size*(size+1)/2;
    int i;
    for(i=0;i<size-1;i++)
    {
        sum -= a[i];
    }

    return sum;

}

//Problem 26
int findElementSum(int a[], int n,int sum){

    int l=0, h=n-1, i;

    heapSort(a,n);

    while(l<h){

        if(a[l]+a[h]==sum){
            printf("Found : %d + %d = %d\n",a[l],a[h],sum);
            return 1;
        }
        else if(a[l]+a[h]>sum){
            h--;
        }
        else{
            l++;
        }
    }
    return 0;
}

//Problem 29
int FindSqureSum(int a[], int n){

    heapSort(a,n);
    int i,j;

    for(i=0;i<n;i++){
        a[i]= a[i]*a[i];
    }

    int k;

    //
    for(i= n-1 ;i>0;i--){
       //printf("%d\n",a[i]);
        k = i-1;
        for(j=0;j<k;){

          //  printf("%d %d = %d \n",a[j],a[k],a[i]);
            if(a[j]+a[k]==a[i]){
                printf("%d %d = %d \n",a[j],a[k],a[i]);
                break;
            }
            else if(a[j]+a[k]<a[i]){
                j++;
            }
            else{
                k--;
            }
        }
    }
}

//Problem 31
int TwoElemWithMinSum(int a[], int size){

    int temp, minSum=INT_MAX,minSum1 =INT_MIN, i,j;

    heapSort(a,size);

    for(i=0,j=size-1;i<j;){

        temp = a[i]+a[j];

        if(temp>0){
            if(temp<minSum){
                minSum = temp;
            }
            j--;
        }
        else if(temp<0)
        {
            if(temp>minSum1){
                minSum1 = temp;
            }
            i++;
        }
        else{
            printf("Closest Sum : %d",temp);
            return;
        }
    }

    printf("Closest Sum : %d",(minSum<abs(minSum1)?minSum:minSum1));
    return;
}

//Problem 33
int Find3ElementSum(int a[], int n, int sum){

    heapSort(a,n);
    int i,j;

    int k;

    //
    for(i= n-1 ;i>0;i--){
       //printf("%d\n",a[i]);
        k = i-1;
        for(j=0;j<k;){

          //  printf("%d %d = %d \n",a[j],a[k],a[i]);
            if(a[j]+a[k]+a[i] == sum){
                printf("%d + %d + %d = %d \n",a[j],a[k],a[i], sum);
                break;
                //return 1;
            }
            else if(a[j]+a[k] + a[i] < sum ){
                j++;
            }
            else{
                k--;
            }
        }
    }
}

//Problem 37
int FindKthElement(int a[])
{

        int i, k,prev, ind;

        prev = a[0];
        ind = 0, i=1,k=1;

       while(1)
       {
                if(a[i]>0 && a[i+1]> 0){
                    if(a[i-1]<a[i] && a[i]>a[i+1]){
                        printf("Found Element at Index :%d\n",i);
                        return i;
                    }
                    else if(prev < a[i]){
                        prev = a[i];
                        ind = i;
                        i = i + k;
                        k *=2;
                    }
                    else{
                        k=1;
                        i = ind + k ;
                    }
                }
                else{
                    k=1;
                    i = ind + k ;
                }

        }
    return -1;
}


//Problem 39
int Find0thFirstOcuurance(int a[])
{

        int i, k,prev, ind;

        prev = a[0];
        ind = 0, i=1,k=1;

       while(1)
       {
                if(a[i]<2 && a[i]> -1){
                    if(a[i-1] == 1 && a[i]== 0){
                        printf("Found Element at Index :%d\n",i);
                        return i;
                    }
                    else if(a[i] == 1 && a[i+1]== 0){
                        printf("Found Element at Index :%d\n",i+1);
                        return i+1;
                    }
                    else if(prev == a[i]){
                        prev = a[i];
                        ind = i;
                        i = i + k;
                        k *=2;
                    }
                    else{
                        k=1;
                        i = ind + k ;
                    }
                }
                else{
                    k=1;
                    i = ind + k ;
                }

        }
    return -1;
}

//Problem 40
int FindFirstOcuurance(int a[], int n)
{

        int i, k,prev, ind;

        prev = a[0];
        ind = 0, i=1,k=1;

       while(i!=n-1)
       {
                if(a[i-1]<a[i] && a[i]>a[i+1]){

                    printf("Found Element at Index :%d Value :%d\n",i+1,a[i+1]);
                    return i;
                }
                else if(prev < a[i]){
                    prev = a[i];
                    ind = i;
                    i = i + k;
                    k *=2;
                }
                else{
                    k=1;
                    i = ind + k ;
                }


        }
    return -1;
}

//Problem 46
int FindRepeatedFirstOcuurance(int a[], int n, int test)
{

        int i, k,prev, ind;

        prev = a[0];
        ind = 0, i=1,k=1;

       while(i!=n-1)
       {
                if(a[i-1]<a[i] && a[i]== test){

                    printf("Found Element at Index :%d Value :%d\n",i,a[i]);
                    return i;
                }
                else if(a[i]<test){
                    prev = a[i];
                    ind = i;
                    i = i + k;
                    k *=2;
                }
                else{
                    k=1;
                    i = ind + k ;
                }


        }
    return -1;
}

int FindNby2OccuranceElement(int a[], int size){

    int i, elem=-1, count =0;
    for(i=0;i<size;i++){

        if(count==0){
            elem = a[i];
            count=1;
        }
        else if(elem == a[i]){
            count++;
        }
        else{
            count--;
        }
    }
    printf("count : %d ",count);
    return elem;

}

//Problem 73

int findZeroInFactorial(int n){

    int i,k,ans;

    ans =0;
    k = log(n)/log(5);

    for(i=1;i<=n;i++){
        ans += ceil(n/pow(5,i));
    }

    printf("Trailing Zero in %d! : %d\n",n,ans);
    return ans;
}

int main()
{
    printf("Hello world!\n");

 //   int a[10]={2,3,5,6,9,10,98,4,2,1};
    //int a[13]={3,4,3,5,4,5,6,5,5,6,7,7};
    //findFirstRepeatedElement(a,13,7);

    int elem[6] = {1,60, -10,70,-80,85};
   // TwoElemWithMinSum(elem,6);

    findZeroInFactorial(100);

    //int i = FindMaxCount(a);
    //printf("Element with max count : %d \n",(a[i]/6));
/*
    findElementSum(a,6,5);
    int test[6]={1,4,3,7,6,2};
    int i = FindMissingNumber(test,7);
    printf("Missing Element  : %d \n",i);
    */

//  FindSqureSum(a,6);
//  int a[6]={10,8,3,5,1,4};
//  Find3ElementSum(a,6,16);

//  FindKthElement(a);
    //FindFirstOcuurance(a,11);
//    FindRepeatedFirstOcuurance(a,13,5);

//    int i = FindNby2OccuranceElement(a,13);
//    printf("Value of Element: %d \n",i);

    return 0;
}
