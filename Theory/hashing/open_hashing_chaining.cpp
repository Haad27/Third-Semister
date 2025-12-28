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
    int collisions(int key)
    {
        int index = hashFunction(key);
        return table[index].size(); // returns # elements already there
    }
    int totalCollisions()
    {
        int total = 0;
        for (int i = 0; i < size; i++)
        {
            if (table[i].size() > 1)
                total += table[i].size() - 1; // each extra element is a collision
        }
        return total;
    }

    int maxInChain(int key)
    {
        int index = hashFunction(key);
        int maxVal = 0;
        for (int x : table[index])
            maxVal = max(maxVal, x);
        return maxVal;
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