#include <iostream>
#include <string>
#include <vector>

using namespace std;
#define SIZE 5
int quene [SIZE];
int front = -1;
int rear = -1;

bool isfull(){
    return (rear == SIZE-1);

    
}
bool isempty(){
    return (front ==-1 || front>rear);
}
void enquene(int value){
    if (isfull())
    {
        cout <<"the quene is full";
    }
    else{
        if (front==-1)
        {
            front =0;
        }
        
        quene[++rear]=value;
    }
}
void dequene(){
    if (isempty())
    {
        return ;
    }else{
        cout<<quene[front]<<"removed\n";
        quene[front++];
    }
    
}
void showfront(){
    if(isempty()){
        return;
    }else{
    cout <<quene[front]<<" ";
}

}
void displat(){
    for (int i = front; i <= rear; i++)
    {
       cout << quene[i]<<" ";
    }
    
}
int main() {
    enquene(10);
    enquene(20);
    enquene(30);
    displat();
    dequene();
    displat();
    enquene(40);
    enquene(50);
    enquene(60);  // this will show "Queue is full"
    displat();

  
    return 0;
}
