#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int num, place;
    int arr[100] = {4, 5, 6, 8, 9};
    int size = 5;
    cout << "enter the place you want to insert";
    cin >> place;
    cout << "enter the number you wanrt to insert";
    cin >> num;
    for (int i = size; i <= place; i++)
    {
        arr[i] = arr[i + 1];
    }
    
    arr[place-1] = num;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i]<<" ";
    }

    return 0;
}
