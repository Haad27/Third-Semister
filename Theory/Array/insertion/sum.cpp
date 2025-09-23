#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{

    int arr[100] = {12, 7, 8, 15, 10};

    int size = 5;

    for (int i = 0; i < size; i++)
    {
int value;
int sum =0;
        if (arr[i] %= 2)
        {
            for (int j = size; j > 0; j--)
            {
                arr[j] = arr[j - 1];
            }
            if (arr[i] < 10)
            {
                arr[i] = arr[i];
            }
            if (arr[i]>=10)
            {
                arr[i]= value;
                while (value<0)
                {
                    int digit = value%10 ;
                    value;
                    sum = value;
                    value = value / 10 ;

                }
                arr[i]=sum;
            }
            
            size++;
            i++;
        }
    }

    return 0;
}
