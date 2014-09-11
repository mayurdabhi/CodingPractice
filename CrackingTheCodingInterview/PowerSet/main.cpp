#include <iostream>
#include <string.h>

using namespace std;

int findCombination(string a, string c){

    if(a.length()==0){
        cout<<"{"<<c<<"}"<<endl;
        return 0;
    }
    else{

        findCombination(a.substr(1),c + a.substr(0,1));
        findCombination(a.substr(1),c);
    }
}

int findPermutation(string a, int i, int n){

    if(i==n){
        cout<<a<<endl;
    }
    else{
        for(int k=i;k<=n;k++){
            swap(a.at(i),a.at(k)) ;
            findPermutation(a,i+1,n);
            swap(a.at(i),a.at(k));
        }
    }
}

int main()
{
    int n = 3;
    string a = "123";//{'1','2','3'};
    string b;//
    cout<<"Combination of "<<a<<endl;
    findCombination(a,b);

    cout<<"Permutation of "<<a<<endl;
    findPermutation(a,0,2);
    return 0;
}
