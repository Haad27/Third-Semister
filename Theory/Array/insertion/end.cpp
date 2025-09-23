#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
  
int arr[100]={4,5,6,8,9};
int size =5;
for (int i = size; i < 0; i++)
{
    arr[i]=arr[i+1];
}
arr[size]=222222;
size++;
for (int i = 0; i < size; i++)
{
    cout<<arr[i]<<" ";
}
  
    return 0;
}
