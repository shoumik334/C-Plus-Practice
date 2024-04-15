#include "Box.h"
#include <iostream>

using namespace std;

Box::Box()
{
    height=0;
    width=0;
    depth=0;

}
Box::Box(double h,double w,double d)
{
    height=h;
    width=w;
    depth=d;
}
void Box::setvalue(double h,double w,double d)
{
    height=h;
    width=w;
    depth=d;
}
void Box::getvalue()
{
    cout << height << " , " << width << " , "<< depth << endl;

}
double Box::volume()
{
    return height*width*depth ;
}