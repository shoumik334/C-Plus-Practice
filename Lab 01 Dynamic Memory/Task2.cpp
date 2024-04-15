#include <iostream>

using namespace std;

int main()

{
    int r,c;
    cout<<"Enter the size of row: "<<endl;
    cin>> r;

    cout<<"Enter the size of column: "<<endl;
    cin>>c;

    char**arr2d=new char*[r];

    for(int i=0;i<r;i++){
        arr2d[i]=new char [c];
    }

    cout<<"Now enter string input: "<<endl;

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr2d[i][j];
        }
    }
    cout<<"Printed array: "<<" "<<endl;
    for (int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cout<<arr2d[i][j];
        }
        cout<<endl;
    }

    for(int i=0;i<r;i++)
        delete[] arr2d[i];


    delete[] arr2d;


}
