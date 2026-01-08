#include <bit/stdc++.h>
using namespace std;
class queue{
    public:
    int* arr;
    int frontindex;
    int nextindex;
    int size;
    int capacity;
    queue(int s){
        arr=new int[s];
        capacity=s;
        frontindex=0;
        nextindex=0;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return size==0;
    }
    void enqueue(int data){
        if(size==capacity){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[nextindex]=data;
        nextindex=(nextindex+1)%capacity;
        size++;
    }
    void dequeue(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        frontindex=(frontindex+1)%capacity;
        size--;
    }
    int front(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[frontindex];
    }
    int back(){
        if(isempty()){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int backindex;
        if(nextindex==0){
            backindex=capacity-1;
        }
        else{
            backindex=nextindex-1;
        }
        return arr[backindex];
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[(frontindex+i)%capacity]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    queue q(5);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.print();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    q.dequeue();
    q.dequeue();
    q.print();
    q.enqueue(6);
    q.print();
    cout<<q.getsize()<<endl;
    return 0;
}
    