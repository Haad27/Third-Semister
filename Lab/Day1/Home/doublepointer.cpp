#include <iostream>
using namespace std;

int main()
{
    int var = 30;       // a normal int variable
    int *ptr1 = &var;   // ptr1 stores the address of var
    int **ptr2 = &ptr1; // ptr2 stores the address of ptr1

    // Print values and addresses
    cout << "Value of var: " << var << endl;
    cout << "Address of var (&var): " << &var << endl;

    //& will give addresss and simple will give value so a pointer will give a garbage value if not usong *
    cout << "\nValue of ptr1 (address of var): " << ptr1 << endl;
    cout << "Value pointed to by ptr1 (*ptr1): " << *ptr1 << endl;
    // simple value
    // & address
    //* thing at that address
    cout << "\nValue of ptr2 (address of ptr1): " << ptr2 << endl;
    cout << "Value pointed to by ptr2 (*ptr2): " << *ptr2 << endl;
    cout << "Double dereference (**ptr2): " << **ptr2 << endl;

    return 0;
}
