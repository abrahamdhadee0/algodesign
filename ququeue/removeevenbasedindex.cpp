#include <bits/stdc++.h>
using namespace std;
void removeEvenIndex(queue<int>& q){
    int n = q.size();
    stack<int> s;
    for(int i=0;i<n;i++){
        int val = q.front();
        q.pop();
        if(i%2==1){
            s.push(val);
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}
int main(){
     queue<int> q;
    for(int i=1;i<=6;i++){
        q.push(i);
    }
    stack<int> s;
    stack<int> temp;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
        temp.push(q.front());
        q.pop();
    }
    while(s.size()>0){
        cout<<s.top()<<" ";
        s.pop();
    }
    
}