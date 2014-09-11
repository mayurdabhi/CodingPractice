#include <iostream>
#include <list>

using namespace std;

int sort(list<int> stack, int size){

    int n = size;
    int swappedElement = n;
    list<int> auxStack;
    int top;
    int min;

    while(n){
        cout<<"No element remaining to sort :" <<n<< " SE "<<swappedElement<<endl;
        //take first elemnt as min
        min= stack.back();
        stack.pop_back();
        swappedElement--;

        //Swap element from stack to auxstack and compare with min.
        //SwappedElement used to count how much pop operation to perform.
        while(swappedElement){

            top  =  stack.back();
           // cout<<"top" << top << " min "<<min<<endl;
            stack.pop_back();

            if(top<min){
                auxStack.push_back(min);
                 min = top;
            }
            else{
                auxStack.push_back(top);
            }
            swappedElement--;
        }

        cout<<"MinElement :"<<min<<endl;
        stack.push_back(min);

//        cout<<" SE "<<swappedElement<<endl;
        swappedElement=0;
        while(!auxStack.empty()){

            swappedElement++;
            stack.push_back(auxStack.back());
            auxStack.pop_back();
        }
  //      cout<<" SE "<<swappedElement<<endl;
        n--;
    }

    list<int>::iterator it;

    for(it=stack.begin();it!=stack.end();++it){
        cout<<*it<<" ";
    }
    cout<<endl;
}

class Animal{
    public:
        char c;
        int time;

    Animal(){};

    Animal(char c1, int t){
        c = c1;
        time = t;
    }

    int compareArrivalTime(Animal a){
        if(time<a.time){
            return 1;
        }
        else{
            return 0;
        }
    }

    void printDetails(){
        cout<<"Type : " <<c<<" Arrival Time :"<<time<<endl;
    }

    char getType(){
        return c;
    }
};

class AnimalQueue{

public:
        list<Animal> catQueue;
        list<Animal> dogQueue;

        void enQueue(Animal a){

            if(a.getType()=='C'){
                cout<<"cat in queue"<<endl;
                catQueue.push_back(a);
            }
            else{
                cout<<"dog in queue"<<endl;
                dogQueue.push_back(a);
            }
        }

        Animal* deQueueAny(){
            Animal temp;
            if(!catQueue.empty())
            {
                 temp = catQueue.front();
            }
            else if(!dogQueue.empty())
            {
                temp = dogQueue.front();
                dogQueue.pop_front();
                return &temp;
            }
            else
            {
                cout<<"No dog or cat left\n";
                return NULL;
            }


            if(!dogQueue.empty()) {
                if(temp.compareArrivalTime(dogQueue.front())){
                    catQueue.pop_front();
                    return &temp;
                }
                else{
                    temp = dogQueue.front();
                    dogQueue.pop_front();
                    return &temp;
                }
            }
            else{
                    catQueue.pop_front();
                    return &temp;
            }
        }

        Animal* DeQueueDog(){
            Animal temp;
            if(!dogQueue.empty()){
                temp = dogQueue.front();
                dogQueue.pop_front();
                return &temp;
            }
            else{
                cout<<"No dog left\n";
                return NULL;
            }
        }

        /*
        Animal TempFun(){
            return no_such_attribute_error;
        }
        */
        Animal* DeQueueCat(){
            Animal temp;
            cout<<catQueue.empty()<<endl;
            if(!catQueue.empty())
            {
                 temp = catQueue.front();
                 catQueue.pop_front();
                 return &temp;
            }
            else{
                cout<<"No cat left\n";
                return NULL;
            }

        }

};



int main()
{

    //Problem 3.6
    /*
    list<int> stack;

    stack.push_back(3);
    stack.push_back(7);
    stack.push_back(4);
    stack.push_back(8);
    stack.push_back(1);
    stack.push_back(2);
    stack.push_back(6);
    sort(stack,7);

*/
    //Problem 3.7

    AnimalQueue keeper;

    Animal* buff;
    keeper.enQueue(Animal('C',5));
    keeper.enQueue(Animal('D',6));
    keeper.enQueue(Animal('C',7));
    keeper.enQueue(Animal('C',8));

    buff = keeper.DeQueueCat();//printDetails();
    if(buff!=NULL)
    buff->printDetails();
    buff = keeper.deQueueAny();
    if(buff!=NULL)
    buff->printDetails();

    buff = keeper.DeQueueDog();
    if(buff!=NULL)
    buff->printDetails();

    buff = keeper.DeQueueDog();
    if(buff!=NULL)
    buff->printDetails();

    buff = keeper.DeQueueCat();
    if(buff!=NULL)
    buff->printDetails();

    return 0;
}
