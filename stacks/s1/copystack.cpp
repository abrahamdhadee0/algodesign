#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    stack<int> temp;
     while(!s.empty()){
        int x= s.top();
        s.pop();
        temp.push(x);
     }
     stack<int>s2;
        while(!temp.empty()){
            int y= temp.top();
            temp.pop();
            s2.push(y);
        }
    while(!s2.empty()){
        cout<<s2.top()<<endl;
        s2.pop();
    }
}