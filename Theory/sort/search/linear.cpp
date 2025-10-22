#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
  
int size =5;
int arr[5]={4,7,2,9,3};
int n = 9;
int pos ;
for (int i = 0; i < size; i++)
{
    if (arr[i]==n)
       {
           pos = i+1;
    }
    
}
    cout <<pos;

  
    return 0;
}
