#include <bits/stdc++.h>
using namespace std;
int main(){
 queue<int> q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    cout<<q.front()<<endl; // 1
    cout<<q.back()<<endl;  // 5
    int i=0;
    while(i<q.size()){
        cout<<q.front()<<" ";
       int j=q.front();
        q.pop();
        q.push(j);
        i++;
    }
    cout<<q.size();
    q.front(); // undefined behavior
    return 0;

}