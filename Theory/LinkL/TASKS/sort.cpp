#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct Node {
    int data;
    Node * next;
};
Node * head = NULL;
void insert (int num){
    Node * newnode=new Node() ;
    newnode->data= num;
    newnode->next = head;
    head= newnode;
}
void sort(){
    Node * temp1 = head;

    while(temp1!=NULL){
        Node * temp2 = temp1->next;

        while(temp2!=NULL){
              if (temp1->data > temp2->data)
              {
                  int temp = temp1->data;
                  temp1->data = temp2->data;
                  temp2->data = temp ;
              }
              temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

}
void reverse (){
    Node * curr = head;
    Node *next = NULL;
    Node *prev = NULL;

    while (curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr= next;

        
    }
    head = prev;
    
}
void duplicate(){
      Node * temp1 = head;

    while(temp1!=NULL && temp1->next!=NULL){
        Node * temp2 = temp1;

        while(temp2->next!=NULL){
              if (temp1->data == temp2->next->data)
              {
                  Node * todel;
                  todel=temp2->next;
                  temp2->next= temp2->next->next;
                  delete todel;
              }else
              temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

}
void display(){
    Node * temp = head;
    while (temp!=NULL)
    {
        cout << temp ->data<<" " ;
        temp = temp ->next;
    }
    
}
void FloyedCycle(){
    Node *fast = head;
    Node *slow = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            cout <<"it is a cycle detected";
            return;
        }
        else{
            cout <<"no cycle";
        }

        
    }
}
void FloyedCycle_removeloop(){
     Node *fast = head;
    Node *slow = head;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            cout <<"it is a cycle detected";
            break;
        }
        else if(fast == NULL || fast->next == NULL){
            cout <<"no cycle";
        }
      
        slow=head;
        while (slow->next!=fast->next)
        {
           slow= slow->next;
            fast= fast->next;
        }
        fast->next=NULL;
        
        
    }
}

bool palindrome(){
   Node * slow = head;
   Node * fast = head;

 
   
   while(fast!=NULL && fast->next != NULL){
    slow=slow->next;
    fast = fast->next->next;
   }
   //this will take to the middle now we need to reverse;
   Node *next =NULL;
   Node *curr= slow;
   Node*prev= NULL;

   while (curr!=NULL)
   {
    next=curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
   }

   Node*first = head;
   Node*last = prev;

   while (last!=NULL)
   {
     if (last->data!=first->data)
    {
      return false;
    }
    first=first->next;
    last=last->next;
    
   }
   return true;
}

int main() {
    insert(100);
    insert(200);
    insert(900);
    insert(900);
    insert(300);
    insert(700);
    sort();
    reverse();
    duplicate();
    display();


  
    return 0;
}
