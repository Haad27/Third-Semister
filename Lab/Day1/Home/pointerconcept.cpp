#include <iostream>
using namespace std;

void pointerDemo() 
{
    int var1 = 30;
    int *ptr1;
    int **ptr2;

    ptr1 = &var1;
    ptr2 = &ptr1;

    cout << "Value at ptr1 (address of var1) = " << ptr1 << endl;
    cout << "Value at var1 = " << var1 << endl;
    cout << "Value of variable using *ptr1 = " << *ptr1 << endl;
    cout << "Value at ptr2 (address of ptr1) = " << ptr2 << endl;
    cout << "Value stored at *ptr2 (which is ptr1) = " << *ptr2 << endl;
    cout << "Value of variable using **ptr2 = " << **ptr2 << endl;
}

int main() 
{
     int var = 30;
    // int *ptr1 = &var;

    // cout << "ptr1: " << ptr1 << endl;     // address of var
    // cout << "*ptr1: " << *ptr1 << endl;   // value at var (30)
    // cout << "&ptr1: " << &ptr1 << endl;   // address of the pointer itself
    pointerDemo();
    return 0;
}
