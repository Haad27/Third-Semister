#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 5

class Stack
{
public:
    int arr[MAX];
    int top;

    Stack()
    {
         top = -1;
    }
    bool Isempty()
    {
        return top == -1;
    }
    bool Isfull()
    {
        return top == MAX - 1;
    }
    void POP(){
        cout <<"the value " <<arr[top]<<"ïs removedd";
        arr[top--];

    } void insert(int value){
        cout <<"the value " <<arr[top]<<"ïs added";
        arr[++top]=value;
        
    }
    void display(){

        for (int i = top; i > 0; i--)
        {
            cout <<endl<<arr[i]<<" ";
        }
        
    }
};

int main()

{
    Stack s;
    s.insert(100);
    s.insert(200);
    s.insert(300);
    s.insert(400);
    s.display();
    s.POP();
    s.POP();
    s.POP();
    s.display();

    return 0;
}
