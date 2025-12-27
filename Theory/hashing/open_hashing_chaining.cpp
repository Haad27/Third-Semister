#include <iostream>
#include <list>
using namespace std;

class HashTable
{
    int size;
    list<int> *table;

public:
    HashTable(int s)
    {
        size = s;
        table = new list<int>[size];
    }

    int hashFunction(int key)
    {
        return key % size;
    }

    void insert(int key)
    {
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    void remove(int key)
    {
        int index = hashFunction(key);
        table[index].remove(key); 
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        for (int x : table[index])
        {
            if (x == key)
                return true;
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << i << ": ";
            for (int x : table[i])
                cout << x << " -> ";
            cout << endl;
        }
    }
};

int main()
{
    HashTable ht(5);
    ht.insert(12);
    ht.insert(22);
    ht.insert(28);
    ht.insert(32);
    ht.display();
}