#include<bits/stdc++.h>
using namespace std;
class node{
    int val;
    node* next;
    node(int val){
        this->val=val;
        this->next=NULL;
    }
}

class DoublyLinkedList {
    public:
 int val;
 node* next;
 node* prev;
 DoublyLinkedList(int val){
    this->val=val;
    this->next=NULL;
    this->prev=NULL;
 }
    void insert_at_head(DoublyLinkedList* &head,int val){
        DoublyLinkedList* n=new DoublyLinkedList(val);
        n->next=head;
        if(head!=NULL){
            head->prev=n;
        }
        head=n;
    }
    void insert_at_tail(DoublyLinkedList* &tail,int val){
        DoublyLinkedList* n=new DoublyLinkedList(val);
        tail->next=n;
        n->prev=tail;
        tail=n;
    }
    void insert_at_position(DoublyLinkedList* &head,DoublyLinkedList* &tail,int pos,int val){
        if(pos==1){
            insert_at_head(head,val);
            return;
        }
        DoublyLinkedList* temp=head;
        int cnt=1;
        while(cnt<pos-1){
            temp=temp->next;
            cnt++;
        }
        if(temp->next==NULL){
            insert_at_tail(tail,val);
            return;
        }
        DoublyLinkedList* n=new DoublyLinkedList(val);
        n->next=temp->next;
        temp->next->prev=n;
        temp->next=n;
        n->prev=temp;
    }
    void display(DoublyLinkedList* head){
        DoublyLinkedList* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        } 
    }
void delteathead(DoublyLinkedList* &head){
    DoublyLinkedList* temp=head;
    head=head->next;
    head->prev=NULL;
    delete temp;
}
void deleteattail(DoublyLinkedList* &tail){
    DoublyLinkedList* temp=tail;
    tail=tail->prev;
    tail->next=NULL;
    delete temp;
}
void deleteatposition(DoublyLinkedList* &head,DoublyLinkedList* &tail,int pos){
    if(pos==1){
        delteathead(head);
        return;
    }
    DoublyLinkedList* temp=head;
    int cnt=1;
    while(cnt<pos){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        deleteattail(tail);
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
}
};

int main(){

}