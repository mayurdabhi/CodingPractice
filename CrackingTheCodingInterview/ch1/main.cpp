#include <iostream>
#include <string>
#include <list>

using namespace std;


int rotatePic(int a[][4], int n){

    for(int i=0;i<n/2;i++){
        int first = i;
        int last = n-1-i;
        for(int j=first;j<last;j++){
            int offset = j-first;
            int top = a[first][j];
            a[first][j] = a[last-offset][first];
            a[last-offset][first] = a[last][last-offset];
            a[last][last-offset] = a[j][last];
            a[j][last] = top;
        }
    }


    cout<<"New MAtrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int modifyMatrix(int a[][4], int n, int m){

    list<int> nRow;// = new list<int>();
    list<int> nCol;// =new list<int>();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                nRow.push_back(i);
                nCol.push_back(j);
            }
        }
    }

    list<int>::iterator it;

    for(it= nRow.begin();it!=nRow.end();++it){
        for(int i =0;i<n;i++){
            a[*it][i]=0;
        }
    }

    for(it= nCol.begin();it!=nCol.end();++it){
        for(int i =0;i<m;i++){
            a[i][*it]=0;
        }
    }

    cout<<"New MAtrix\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}


int checkIsSubString(string s1, string s2){

   size_t index =  s1.find(s2);

   if(index == string::npos){
    return 0;
   }
   else{
    return 1;
   }
}

int main()
{

    //1.6 Rotate MAtrix 90 degree

    int pic[4][4] = {{1,2,4,5},{9,0,5,6},{7,2,1,0},{6,9,3,5}};
    rotatePic(pic,4);

    //1.7
    int a[3][4] = {{1,2,4,5},{9,0,5,6},{7,2,1,0}};
    modifyMatrix(a,3,4);

    //1.8
    string s1, s2;
    s1 = "waterbottle";
    s2 = "erbottlewat";

    if(checkIsSubString(s1+s1,s2)){
        cout<<"It is a substring\n";
    }
    else{
        cout<<"It is not a substring\n";
    }
    return 0;
}
