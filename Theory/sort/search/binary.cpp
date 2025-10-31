#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main() {
  
int size =10;
int arr[]={1,2,3,4,5,6,7,8,9,10};

    int low =0;
    int high = size-1;
    int pos=-1;
    int target = 9;
    while (low<=high)
    {
        int mid = (low+high)/2;

        if (arr[mid]==target)
        {
            pos = mid;
            break;
        }
        else if
        (arr[mid]<target){
            low = mid+1;
        }
        else{
            high= mid-1;
        }
        
    }
    cout << pos;
    


  
    return 0;
}
