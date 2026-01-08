#include <bits/stdc++.h>
using namespace std;
 void pushatbottom(stack<int>&s,int x){
    stack<int> temp;
    if(s.empty()){
        s.push(x);
        return;
    }
    else{
        while(!s.empty()){
            int y= s.top();
            s.pop();
            temp.push(y);
        }
        s.push(x);
        while(!temp.empty()){
            int z= temp.top();
            temp.pop();
            s.push(z);   
        }
    }
}
void pushatindex(stack<int>&s,int x,int index){
    stack<int> temp;
    int count=0;
    while(!s.empty() && count<index){
        int y= s.top();
        s.pop();
        temp.push(y);
        count++;
    }
    s.push(x);
    while(!temp.empty()){
        int z= temp.top();
        temp.pop();
        s.push(z);
    }
void revrec(stack<int>&s){
    if(s.empty()){
        return;
    }
    int x= s.top();
    s.pop();
    revrec(s);
    s.push(x);
}
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    pushatbottom(s,5);
    pushatindex(s,15,2);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    revrec(s);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}