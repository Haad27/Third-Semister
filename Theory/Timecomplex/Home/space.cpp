#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
     srand(time(0));
    int arr[10];
    int temp[10] = {0};
    for (int i = 0; i < 12; i++)
    {
        arr[i] = rand()%1000;
    }
    for (int i = 0; i < 10; i++)
    {
        temp[arr[i]] = 1;
        if (temp[arr[i]] == 1)
        {
           cout <<"element repeated i == " << arr[i] << endl;
        }
        
    }

    return 0;
}
