#include <iostream>
#include <string>
#include <vector>

using namespace std;


void sort (int size,char arr[]){
    for (int i = 0; i < size; i++)
    {
        for (int j = i+1; j < size; j++)
        {
            if (arr[i]>arr[j])
            {
                swap(arr[i],arr[j]);
            }
            
        }
        
    }
    
}
int main()
{
    char arr[100];
    string s;
    cout << "enter a string ";
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        arr[i]=s[i];
    }
    sort(s.length(),arr);
    for (int i = 0; i < s.length(); i++)
    {
        cout <<arr[i];
    }
    

    return 0;
}
