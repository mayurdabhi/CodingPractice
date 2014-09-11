#include<iostream>
using namespace std;
#define n 4
#define INT_MAX 100000

struct element{
    int value;
    int index;
    int arrIndex;
};

void swap(struct element *a, struct element *b ){

    struct element temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(struct element a[], int size, int i){

    int l = 2*i;
    int r= 2*i+1;
    int smallest =i;

    if(l<size && a[l].value<a[smallest].value){
        smallest = l;
    }

    if(r<size && a[r].value<a[smallest].value){
        smallest = r;
    }

    if(smallest != i){
        swap(a[smallest], a[i]);
        minHeapify(a,size,smallest);
    }

}

void buildMinHeap(struct element a[], int size){

    for(int i = size/2;i>=0;i--){
        minHeapify(a,size,i);
    }
}

//complexity : O(nklogk)
int * mergesortedArrays(int arr[][n], int k){

    int *ans = new int[n*k];

    struct element minheap[k];// = new struct element[k];

    for(int i=0;i<k;i++)
    {
        minheap[i].value = arr[i][0];
        minheap[i].index = i;
        minheap[i].arrIndex = 1;
    }

    buildMinHeap(minheap,k);

    for(int i = 0;i<n*k;i++){

        struct element temp = minheap[0];

        ans[i] = temp.value;

        if(temp.arrIndex>=n){
            temp.value = INT_MAX;
        }
        else
        {
            temp.value = arr[temp.index][temp.arrIndex++];
        }

        minheap[0] = temp;
        minHeapify(minheap,k,0);

    }

    return ans;
}

void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        cout << arr[i] << " ";
}

int main()
{
    int a[][n]={{3, 5, 15, 30},{1, 8, 21, 56},{6, 25, 50,108}};
    int k = sizeof(a)/sizeof(a[0]);
    int *ans = mergesortedArrays(a, k);
    cout<< "Merged sorted array : " << endl;
    printArray(ans,n*k);
    return 0;
}
//<strong>Time Complexity</strong>: O(nklogk)
