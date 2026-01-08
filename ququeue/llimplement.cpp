#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next=NULL;
    }
}
class queue{
    node* front;
    node* rear;
    int size;
    public:
    queue(){
        front=NULL;
        rear=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
    void enqueue(int data){
        node* newnode=new node(data);
        if(rear==NULL){
            front=newnode;
            rear=newnode;
        }
        else{
            rear->next=newnode;
            rear=newnode;
        }
        size++;
    }
    void dequeue(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        node* temp=front;
        front=front->next;
        if(front==NULL){
            rear=NULL;
        }
        delete temp;
        size--;
    }
    int getfront(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return front->data;
    }
    int getrear(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return rear->data;
    }
};