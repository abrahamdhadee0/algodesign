// in this lecture we leant about linked list and how to create a linked list and using node what we head.
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
class linkedlist{
    public:
    node *head;
    node *tail;
    linkedlist(){
        head=NULL;
}
};
int main() {
  node n1(10);
  node n2(20);
  node n3(233);
  node n4(200);
  n1.next=&n2;
    n2.next=&n3;    
    n3.next=&n4;
  cout<<n1.next->next->next->value<<endl;
  node temp=n1;

}