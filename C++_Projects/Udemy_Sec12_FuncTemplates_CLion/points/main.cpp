#include <iostream>
#include "point.h"

using namespace std;
/* function templates generalization*/

void operationOnPoints();

template<typename T, typename T2>
T add(T var1, T2 var2)
{
    return var1 + var2;
}
/*
template<>
Point2D add(Point2D var1, Point2D var2)
{
    Point2D tmp;

    tmp.setX(var1.getX() + var2.getX());
    tmp.setY(var1.getY() + var2.getY());

    return tmp;
}
*/
int main()
{
    operationOnPoints();

    //cout << add<double, double>(2, 5.6) << endl;


   // cout << static_cast<int>(6.5) << endl;

    return 0;
}
void operationOnPoints()
{
    Point2D p1(10, 67);
    Point2D p2(50, 3); // 60,70

    Point2D sum = add(p1,p2);

    cout << sum.getX() << endl;
    cout << sum.getY() << endl;


}
