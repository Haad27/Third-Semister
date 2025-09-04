#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int *arr = new int[5];

    for (int i = 0; i < 5; i++)
    {
         arr[i]=i;
    }
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    int x= 34;
    int *ptr = new int ;
    // *ptr = x; both ways work 
    ptr=&x;
    cout << *ptr << endl;   // prints 50

    return 0;
}
