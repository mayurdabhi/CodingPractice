/*
============================================================================
Author         : James Chen
Email          : a.james.chen@gmail.com
Description    : Calculate (x^y)%z without pow()
Created Date   : 27-July-2013
Last Modified  :
===========================================================================
*/

#include <iostream>
#include <iomanip>

using namespace std;

int CalculateNonRecursive(int x, int y, int z)
{
    int t = 1;
    for(int j = 0; j < y; j++)
    {
        t = (t * x);// % z;
    }

    return t%z;
}


int Calculate(int x, int y, int z)
{
    if(y == 1){
        return x % z;
    }

    return Calculate(x, y - 1, z) * (x ) % z;
}

void DoTest(int x, int y, int z)
{
    cout << "Calculate (" << x;
    cout << "^" << y <<") %" << z;
    cout <<" = " << Calculate(x, y, z) << endl;
    cout << "Calculate (" << x;
    cout << "^" << y <<") %" << z;
    cout <<" = " << CalculateNonRecursive(x, y, z) << endl;
    cout << "-----------------------" << endl;
}

int main(int argc, char* argv[])
{
//    DoTest(3, 1, 4);
//    DoTest(3, 2, 4);
//    DoTest(3, 3, 4);
    DoTest(3, 4, 4);

    DoTest(5, 1, 3);
   // DoTest(5, 2, 3);
   // DoTest(5, 3, 3);
   // DoTest(5, 4, 3);

    return 0;
}
