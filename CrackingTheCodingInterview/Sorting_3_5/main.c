#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findElement(int a[], int n, int elem){

        int low = 0;
        int high = n-1;
        int mid;
        while(low<=high){

            mid = (high-low)/2 + low;
            printf("mid : %d %d\n",mid, a[mid]);
            if(a[mid]==elem){
                printf("Found at :%d\n",mid);
                return mid;
            }
            else if(high<low){
                return -1;
            }
            else if(a[mid]>=a[low]){

                if(elem>=a[low] && elem<=a[mid]){
                    high = mid-1;
                }
                else {
                    low = mid + 1;
                }
            }
            else if(a[mid]<=a[low] ){
                if(elem>=a[mid] && elem <= a[high] ){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
        }
        printf("Element Not found\n");
        return -1;
}


int findLocationOfString(char *str[], int low, int high, char *data){

    if(low<=high){

       int mid = (high-low)/2 + low;
       int temp;
        /*
        if(str[mid]==""){
            temp = mid;
            while(str[temp]==""){
                temp--;
        }
        */
        if(str[mid]==""){
            temp = mid;
            while(str[temp]==""){
                temp--;
            }

            int temp2 = strcmp(str[temp],data);
            if(temp2==0){
                printf("Found at :%s %d\n",str[temp],temp);
                return temp2;
            }
            if(temp2>0){
                return findLocationOfString(str,low, temp2-1,data);
            }
            else{
                return findLocationOfString(str,mid+1,high,data);
            }
        }
        else if(str[mid]!=""){
            temp = strcmp(str[mid],data);

            if(temp==0){
                printf("Found at :%s %d\n",str[mid],mid);
                return mid;
            }
            if(temp>0){
                return findLocationOfString(str,low, mid-1,data);
            }
            else{
                return findLocationOfString(str,mid+1,high,data);
            }
        }


    }
}
int main()
{
    int a[] = {2,2,2,3,4,2}; //{15,16,19,20,25,1,3,4,5,7,10,14};
    int n = 6;
    findElement(a,n,5);

    int *str[] = {
                    "at",
                    "",
                    "",
                    "",
                    "ball",
                    "",
                    "",
                    "car",
                    "",
                    "",
                    "dad",
                    "",
                    ""
                };
    findLocationOfString(str,0,11,"at");
    return 0;
}
