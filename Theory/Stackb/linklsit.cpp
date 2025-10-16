#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Stack{
    int data;
    Stack* next;
};

Stack * top = NULL;

bool isEmpty(){
    if (top==NULL)
    {
        return 0;
    }
    return 1;
}

void isnert (int num){
    Stack *newstruct = new Stack();


    newstruct->data= num;
    newstruct->next = top;
    top = newstruct;
}
void peek(){
    cout <<top->data;
}
void pop(){
    Stack *temp = top;
    top= top->next;
    delete temp;
}

void display(){
    Stack *temp = top;
    while (temp!= NULL)
    {
        cout << temp->data<<" ";
        temp = temp->next;
    }
    
}
int main() {
  

   isnert(100);
   isnert(200);
   isnert(300);
   pop();
   display();
    return 0;
}
