#include <iostream>
using namespace std;

#define MAX 5

int queue[MAX];
int front=-1;
int rear =-1;
bool isEMpty(){
    return (front==-1||front>rear);
}
bool isFull(){
    return rear == MAX-1;
}
void Enqueue(int value){
   
    if (isFull())
    {
        cout <<"full ";
    }
    cout << "inserting\n";
    if (front==-1)
    {
        front =0;
    }
    
    queue[++rear]=value;
}
void Dequene(){
    if (isEMpty())
    {
        cout <<"empty";
        return;
    }

    queue[front++];
}

void peek() {
    if (!isEMpty())
        cout << "Front element: " << queue[front] << endl;
}
void display(){
    for (int i = front; i <= rear; i++)
    {
      cout << queue[i]<<" ";
    }
    
}

int main(){
Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    display();
    Dequene();
    display();
    Enqueue(40);
    Enqueue(50);
    Enqueue(60); // should print "full"
    display();
}