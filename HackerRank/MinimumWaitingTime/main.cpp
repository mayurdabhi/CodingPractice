#include <iostream>
#include <list>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

using namespace std;

/*
class Order{

public:
    long long int t,l;

    void SetOrder(long long int t1,long long int l1 ){
            t = t1;
            l = l1;
    }


    void GetOrderTime(){
            return t;
    }

    void GetCookTime(){
        return l;
    }

};
*/

typedef struct order Order;

struct order{
    long long int l,t;
    order(long long int t1, long long int l1) : l(l1), t(t1) {}
};

struct sortOrder
{
    inline bool operator() (const Order& struct1, const Order& struct2)
    {
        return (struct1.t < struct2.t);
    }
};

int main()
{
    //cout << "Hello world!" << endl;

    int n;
    long long int l,t;
    cin>>n;
    vector<Order> vec;
   // Order o;//  = new Order();

    for(int i =0;i<n; i++){
        cin>>t;
        cin>>l;
        //order.SetOrder(t,l);
        vec.push_back(order(t,l));
    }

    sort(vec.begin(), vec.end(),sortOrder());

    vector<Order>::iterator it = vec.begin();
    long long int last = it->t;
    long long int waitingTime = 0;
    long long int executiontime;
    long long int wtime[n];
    long long int min;
    int element=-1;
    int flag =0;
    while(!vec.empty()){
        min= LLONG_MAX;
        element = -1;
        for(it=vec.begin();it!=vec.end();++it)
        {
           // cout<<"last "<<last<<" it->t "<<it->t<<" lt->l "<<it->l<< " "<<min<<endl;
            if(it->t<=last && it->l<min){
                min = it->l;
                element++;
                //flag=1;
            }
            else if(it->t>last){
                break;
            }
        }
        it = vec.begin()+element;

        if(element!= -1)
        {
           // cout <<"wt b "<<waitingTime<<endl;
            waitingTime += it->l + (last - it->t);
           // cout <<"wt a "<<waitingTime<<endl;
            last += it->l;
           // cout<<"lst "<<last<<endl;
            vec.erase(vec.begin()+element);
        }
        else{
            last++;
        }
    }

    waitingTime = waitingTime/n;

    cout<<floor(waitingTime)<<endl;
    return 0;
}
