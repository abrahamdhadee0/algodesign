#include <bits/stdc++.h>
using namespace std;
int main(){
         stack<int> temp;
         stack<int> s;
            s.push(10);
            s.push(20);
            s.push(30);
            s.push(40);
            while(!s.empty()){
                int x= s.top();
                cout<<x<<endl;
                s.pop();
                temp.push(x);
            }
            while(!temp.empty()){
                int y= temp.top();
                temp.pop();
                s.push(y);
            }
  while(!s.empty()){
      cout<<s.top()<<endl;
      s.pop();
  }

}