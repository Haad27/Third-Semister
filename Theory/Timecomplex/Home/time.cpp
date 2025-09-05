#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    int arr[10];

    // Generate random numbers
    for (int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 1000;
    }

    // Check for repeated elements using two loops (time complexity O(n^2))
    for (int i = 0; i < 10; i++)
    {
        for (int j = i + 1; j < 10; j++)
        {
            if (arr[i] == arr[j])
            {
                cout << "Element repeated: " << arr[i] << " at indices " << i << " and " << j << endl;
            }
        }
    }

    return 0;
}
