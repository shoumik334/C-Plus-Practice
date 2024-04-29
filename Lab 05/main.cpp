#include <iostream>
#include "sortedtype.cpp"
using namespace std;

class timeStamp{
public:
    int seconds;
    int minutes;
    int hours;

    timeStamp(){
        seconds=0;
        minutes=0;
        hours=0;
    }

    timeStamp(int s,int m,int h){

        seconds=s;
        minutes=m;
        hours=h;
    }

    void printTime(){
        cout<< seconds <<":"<<minutes<<":"<< hours<<endl;

    }
    bool operator<(const timeStamp& other) const {
        if (hours != other.hours)
            return hours < other.hours;
        if (minutes != other.minutes)
            return minutes < other.minutes;
        return seconds < other.seconds;
    }

    // Overload > operator
    bool operator>(const timeStamp& other) const {
        if (hours != other.hours)
            return hours > other.hours;
        if (minutes != other.minutes)
            return minutes > other.minutes;
        return seconds > other.seconds;
    }

    // Overload == operator
    bool operator==(const timeStamp& other) const {
        return (hours == other.hours && minutes == other.minutes && seconds == other.seconds);
    }
    bool operator!=(const timeStamp& other) const {
        return !(*this == other);
    }

};


int main() {

    SortedType<int> List;

    cout << "Length of the list : " << List.LengthIs() << endl;

    List.InsertItem(5);
    List.InsertItem(7);
    List.InsertItem(4);
    List.InsertItem(2);
    List.InsertItem(1);

    cout << "List : " << endl;
    for (int i = 0; i < List.LengthIs(); i++) {
        int item;
        List.GetNextItem(item);
        cout << item << " ";

    }
    cout << endl;

    int item2 = 6;
    bool found;

    List.RetrieveItem(item2, found);
    cout << "Item 6 is " << (found ? "found" : "not found") << endl;

    item2 = 5;
    List.RetrieveItem(item2, found);
    cout << "Item 5 is " << (found ? "found" : "not found") << endl;

    List.DeleteItem(1);

    List.ResetList();
    for (int i = 0; i < List.LengthIs(); i++) {
        int item3;
        List.GetNextItem(item3);
        cout << item3;

    }
    cout << endl;

    cout << (List.IsFull() ? "full" : "not full")<<endl;

   //Time stamp

   SortedType<timeStamp>timeList;

   timeList.InsertItem(timeStamp(15,34,23));
   timeList.InsertItem(timeStamp(13,13,02));
   timeList.InsertItem(timeStamp(43,45,12));
    timeList.InsertItem(timeStamp(25,36,17
    ));
    timeList.InsertItem(timeStamp(52,02,30));

    timeList.DeleteItem(timeStamp(25,36,27));

    timeList.ResetList();
    for(int i=0;i<timeList.LengthIs();++i){

        timeStamp time;
        timeList.GetNextItem(time);
        time.printTime();
    }








    return 0;
}
