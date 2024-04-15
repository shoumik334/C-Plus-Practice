#include <iostream>
#include "unsortedtype.cpp"

using namespace std;

int main() {

    UnsortedType<int>intList;

    intList.InsertItem(5);
    intList.InsertItem(7);
    intList.InsertItem(6);
    intList.InsertItem(9);

    int item;
    intList.ResetList();
    std::cout << "Integer list: ";
    for (int i = 0; i < intList.LengthIs(); ++i) {
        intList.GetNextItem(item);
        std::cout << item << " ";
    }
    std::cout << std::endl;

    return 0;
}
