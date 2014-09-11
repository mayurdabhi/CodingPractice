#include <iostream>
#include <list>
using namespace std;


int sumOfTwoNumber(list<int> n1,list<int> n2, list<int> sum1, int carry){
    int sum =0;
    list<int>::reverse_iterator it1,it0, it2 ;

    for(it1=n1.rbegin(), it2=n2.rbegin(); it1!=n1.rend() || it2!=n2.rend() ;){

            if(it2==n2.rend()){
                sum = *it1+carry;
                it1++;
            }
            else if(it1==n1.rend())
            {
                sum = *it2+carry;
                it2++;
            }
            else if(it1!=n1.rend() && it2!=n2.rend()){
                sum = *it1 + *it2 + carry;
                it1++;
                it2++;
            }


            if(sum>9){
                carry = sum/10;
                sum = sum%10;
            }
            else{
                carry=0;
            }
            cout<<sum<<" " <<carry<<endl;
            sum1.push_front(sum);
    }

    if(carry!=0){
        sum1.push_front(carry);
    }
    cout<<"Result:\n";
    list<int>::iterator it;
    for(it=sum1.begin(); it != sum1.end(); it++){
        cout<<*it;
    }
    cout<<endl;
}

int sumTwoNo(list<int> n1, list<int> n2, list<int> sum){
    sumOfTwoNumber(n2,n1,sum,0);
}

int main()
{
    list<int> n1;
    n1.push_back(3);
    n1.push_back(7);
    n1.push_back(5);

    list<int> n2;
 //   n2.push_back(2);
 //   n2.push_back(8);
 //   n2.push_back(2);

    list<int>n3;

    sumTwoNo(n1,n2,n3);
    list<int>::iterator it;
    for(it=n3.begin(); it != n3.end(); it++){
        cout<<*it;
    }

    return 0;
}
