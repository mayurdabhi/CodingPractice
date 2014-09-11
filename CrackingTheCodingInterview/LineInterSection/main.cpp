#include <iostream>
#include <limits>
using namespace std;

class Line{

public:
        int x1,y1,x2,y2;

        Line(int x11, int y11, int x22, int y22){
            x1= x11;
            y1= y11;
            x2= x22;
            y2= y22;
        }

        double getSlop(){

            if(x1!=x2){
                return((y2-y1)/(x2-x1));
            }
            else{
                return -9999;
            }
        }
};


int main()
{
    /*
    Example 1:
    line1: points (–1, –2) and (1, 2)
    line2: points (–2, 0) and (0, 4)
    Answer => "Lines are Parallel!!"

    Example 2:
    line1: points (0, –4) and (–1, –7)
    line2: points (3, 0) and (–3, 2)
    Answer => "Lines are Perpendicular!!"

    Example 3:
    line1: points (–4, 2) and (0, 3)
    line2: points (–3, –2) and (3, 2)
    Answer => "Lines Intersects!!"
*/
    Line l1(-1,-2,1,2);
    Line l2(-2,0,0,4);

    double m1,m2;

    m1 = l1.getSlop();
    m2 = l2.getSlop();

    if(m1==m2){
        cout<<"Lines are parallel\n";
    }
    else if((1/m1)==(-m2)){
        cout<<"Lines are perpendicular\n";
    }
    else{
        cout<<"Lines would intersect\n";
    }


    return 0;
}
