//using new node method
#include <iostream>
using namespace std;        
class node{
     public:
    int value;
    node *next;
    node(int value){
        this->value=value;
        next=NULL; 
    }
};

int main() {
  node *n1=new node(10);
  node *n2=new node(20);
  node *n3=new node(233);
  node *n4=new node(200);
  n1->next=n2;
    n2->next=n3;    
    n3->next=n4;
  node *temp=n1;
  while(temp!=NULL){
    cout<<temp->value<<endl;
    temp=temp->next;
  }
}