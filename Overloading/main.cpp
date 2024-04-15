#include <iostream>
#include "Complex.h"
#include "cmake-build-debug/Complex.h"

using namespace std;

int main() {
    Complex c1(2,3);
    Complex c2(2,1);
    Complex c3=c1+c2;
            c3.Print();
    return 0;

}
