#include <stdio.h>
#include <stdlib.h>
typedef struct box Box;

struct box{
    int h,w,d;
};

int min(int a, int b){
    return (a<b)?a:b;
}

int max(int a, int b)
{
    return (a>b)?a:b;
}

int comp(void *a, void *b){

    return ((*(Box *)a).w * (*(Box *)a).d) - ((*(Box *)b).w*(*(Box *)b).d);
}
int findMaxHeight(Box b[], int n){

    //create all 3 rotation
    Box rev[n*3];
    int i,j;
    int index = 0;

    for(i=0;i<n;i++){

        rev[index] = b[i]; // 1st rotation as it is
        index++;

        rev[index].h = b[i].d;
        rev[index].d = max(b[i].h,b[i].w);
        rev[index].w = min(b[i].h,b[i].w);
        index++;

        rev[index].h = b[i].w;
        rev[index].d = max(b[i].h,b[i].d);
        rev[index].w = min(b[i].h,b[i].d);
        index++;
    }

    qsort(rev,3*n,sizeof(rev[0]),comp);

    n= 3*n;
    int maxHeight[n];

    for(i=0;i<n;i++){

        maxHeight[i] = rev[i].h;
    }

    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if( (rev[i].w > rev[j].w) && (rev[i].d > rev[j].d) &&(maxHeight[i]<maxHeight[j]+rev[i].h )){
                maxHeight[i] = maxHeight[j]+rev[i].h;
            }
        }
    }
    int maxH=1;
    for(i=0;i<n;i++){
        if(maxH<maxHeight[i]){
            maxH = maxHeight[i];
        }
    }

    printf("Max Height : %d\n",maxH);
}

int main()
{

    Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(arr)/sizeof(arr[0]);
    findMaxHeight(arr,n);
    return 0;
}
