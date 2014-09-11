#include <iostream>
#include <queue>
using namespace std;


/*
* Amazon Interview
* print all the binary values of number from 1 to n , each number’s binary should be printed in 0(1).
* for eg: n = 6
* then print 1 10 11 100 101 110. printing 1, 10 ,11 ,100,101,110 should be in o(1) each
*/

int printBinary(int n){

    queue<string> binaryQueue;
    queue<string> resultQueue;
    binaryQueue.push("1");
    resultQueue.push("1");
    for(int i=2;i<=n;i=i+2){

        string temp = binaryQueue.front();
        binaryQueue.pop();
        string t1,t2;
        t1 = temp+'0';
        t2 = temp+'1';
        resultQueue.push(t1);
        resultQueue.push(t2);
        binaryQueue.push(t1);
        binaryQueue.push(t2);
        cout<<t1<<endl<<t2<<endl;
    }
}
int main()
{
    printBinary(9);
    return 0;
}
