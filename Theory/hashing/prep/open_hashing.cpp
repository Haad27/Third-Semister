#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;
class Hashtable
{
public:
    int size;
    list<int> *table;

    Hashtable(int s)
    {
        size = s;
        table = new list<int>[size];
    }

    int hashfunction(int key)
    {
        return key % size;
    }
    void insert(int key)
    {
        int index = hashfunction(key);
        table[index].push_back(key);
    }

    void display (){
        for (int i = 0; i < size; i++)
        {
           for (int x : table[i])
           {
            cout << x;
           }
           cout <<endl;
           
        }
        
    }
};

int main()
{

    return 0;
}
