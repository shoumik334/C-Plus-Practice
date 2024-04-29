#include <iostream>
#include "unsortedtype.cpp"

using namespace std;
class StudentInfo {
private:
    int studentID;
    std::string name;
    double cgpa;

public:
    StudentInfo() {}
    StudentInfo(int id, std::string n, double g) : studentID(id), name(n), cgpa(g) {}

    void PrintInfo() const {
        std::cout << studentID << ", " << name << ", " << cgpa << std::endl;
    }
    bool operator==(const StudentInfo& other) const {
        return studentID == other.studentID;
    }

    bool operator!=(const StudentInfo& other) const {
        return !(*this == other);
    }
};

int main() {

    UnsortedType<int>intList;

    intList.InsertItem(5);
    intList.InsertItem(7);
    intList.InsertItem(6);
    intList.InsertItem(9);

    int item;
    intList.ResetList();
    cout << "Integer list: ";
    for (int i = 0; i < intList.LengthIs(); ++i) {
        intList.GetNextItem(item);
        cout << item << " ";
    }
    cout << std::endl;


    cout<<"Length of the list is :"<<intList.LengthIs()<<endl;
    intList.InsertItem(1);

    int item2;
    intList.ResetList();
    for (int i=0;i<intList.LengthIs();i++){
        intList.GetNextItem(item2);
        cout<<item2<<" ";
    }
    cout<<endl;

    bool found2;

    int itemToRetrieve = 4;
    intList.RetrieveItem(itemToRetrieve, found2);

    cout<<"Item 4 found status: "<<(found2 ? "Item is found":"Item is not found")<<endl;

    itemToRetrieve = 5;

    intList.RetrieveItem(itemToRetrieve,found2);
    cout<<"Item 5 found status: "<<(found2 ? "Item is found":"Item is not found")<<endl;

    itemToRetrieve = 9;

    intList.RetrieveItem(itemToRetrieve,found2);
    cout<<"Item 9 found status: "<<(found2 ? "Item is found":"Item is not found")<<endl;

    itemToRetrieve = 10;

    intList.RetrieveItem(itemToRetrieve,found2);
    cout<<"Item 10 found status: "<<(found2 ? "Item is found":"Item is not found")<<endl;


    cout<<"List is "<<(intList.IsFull() ?"Full":"not Full" )<<endl;

    intList.DeleteItem(5);
    cout<<"List is "<<(intList.IsFull() ?"Full":"not Full" )<<endl;

    intList.DeleteItem(1);

    intList.ResetList();
    for(int i=0;i<intList.LengthIs();i++){
        intList.GetNextItem(item);
        cout<<item;
    }
    cout<<endl;


    intList.DeleteItem(6);
    intList.ResetList();
    for(int i=0;i<intList.LengthIs();i++){
        intList.GetNextItem(item);
        cout<<item;
    }
    cout<<endl;

    UnsortedType<StudentInfo> studentsList;

    // Inserting student records
    studentsList.InsertItem(StudentInfo(15234, "Jon", 2.6));
    studentsList.InsertItem(StudentInfo(13732, "Tyrion", 3.9));
    studentsList.InsertItem(StudentInfo(13569, "Sandor", 1.2));
    studentsList.InsertItem(StudentInfo(15467, "Ramsey", 2.3));
    studentsList.InsertItem(StudentInfo(16285, "Arya", 3.1));

    // Deleting the record with ID 15467
    StudentInfo recordToDelete(15467, "", 0);
    studentsList.DeleteItem(recordToDelete);

    // Retrieving the record with ID 13569 and printing
    StudentInfo searchItem(13569, "", 0.0);
    bool found = false;
    StudentInfo foundItem;
    studentsList.RetrieveItem(foundItem, found);
    if (found) {
        std::cout << "Item is found" << std::endl;
        foundItem.PrintInfo();
    } else {
        std::cout << "Item not found" << std::endl;
    }
    // Printing the list
    std::cout << "List:" << std::endl;
    StudentInfo currentItem;
    for (int i = 0; i < studentsList.LengthIs(); ++i) {
        studentsList.GetNextItem(currentItem);
        currentItem.PrintInfo();
    }








    return 0;
}
