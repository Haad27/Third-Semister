#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MAX 5

class Stack
{
public:
    char arr[MAX];
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
    char POP(){
        cout <<"the value " <<arr[top]<<"ïs removedd";
        return arr[top--];

    } void insert(char value){
        cout <<"the value " <<arr[top]<<"ïs added";
        arr[++top]=value;
        
    }
    void display(){

        for (int i = 0; i <= top; i++)
        {
            cout <<endl<<arr[i]<<" ";
        }
        
    }
};

int main()

{
    Stack s;
    // s.insert(100);
    // s.insert(200);
    // s.insert(300);
    // s.insert(400);
    // s.display();
    // s.POP();
    // s.POP();
    // s.POP();
string x;
    cout<<"enter";
    cin>>x;

    for (int i = 0; i < x.length(); i++)
    {
        s.insert(x[i]);
    }
    string reverse="";
    while (!s.Isempty())
    {
        reverse += s.POP();
    }
 
    cout<<"\n\n";
    cout << reverse;
    return 0;
}
