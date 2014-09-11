#include <iostream>
#include <queue>

using namespace std;

int printQueue(queue<int> q)
{
    while(!q.empty()){

        cout<<q.front()<<endl;
        q.pop();
    }
}

int ReverseQueue(queue<int> &q){

    if(!q.empty()){

        int temp = q.front();
        q.pop();
        cout<<"Dequeue : "<<temp<<endl;
        ReverseQueue(q);
        cout<<"Enqueue : "<<temp<<endl;
        q.push(temp);
        return 1;
    }
    return 0;
}
int main()
{

    queue<int> q;
    q.push(3);
    q.push(4);
    q.push(6);
    q.push(2);
    q.push(8);
    printQueue(q);
    ReverseQueue(q);
    printQueue(q);

    return 0;
}
