#include <bits/stdc++.h>
using namespace std;
int main(){
    stack<int> s;
    stack<int> z;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    for(int i=s.size();i>0;i--){
        cout<<s.top()<<endl;
      int x= s.pop();
        z.push(x);
    }
    for(int i=z.size();i>0;i--){
        cout<<z.top()<<endl;
        z.pop();
    }
}