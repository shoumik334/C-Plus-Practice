#include <iostream>
#include "Box.hpp"
using namespace std;

int main()
{

    Box obj;
    obj.getvalue();
    Box obj2(4.0, 5, 3.1);
    obj2.getvalue();
    obj2.setvalue(12.5, 10, 7);
    obj2.getvalue();
    cout << obj2.volume() ;
    return 0;
}
