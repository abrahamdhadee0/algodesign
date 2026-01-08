// user defined data structure
#include <bits/stdc++.h>
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
    int size=0;
    linkedlist(){
        head=NULL;
        tail=NULL;
    }
    void insertatend(int value){
        node *newnode=new node(value);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        size++;
        tail->next=NULL;
    }
};
int main(){
    linkedlist l;
    l.insertatend(10);
    l.insertatend(20);
    l.insertatend(30);
    l.insertatend(40);
    node *temp=l.head;
    while(temp!=NULL){
        cout<<temp->value<<endl;
        temp=temp->next;
    }
}