#include <iostream>
#include "quetype.cpp"
using namespace std;

int main() {
    QueType<int> myQueue(5);


    cout << "Is the queue empty? " << (myQueue.IsEmpty() ? "Yes" : "No") << std::endl;

    return 0;
}
