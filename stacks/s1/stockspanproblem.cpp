#include <bits/stdc++.h>
using namespace std;
int main(){
 int pgi[n];
 stack<int> st;
 st.push(0);
 for(int i=1;i<n;i++){
     while(!st.empty() && v1[st.top()]<=v1[i]){
         st.pop();
     }
     if(st.size()==0){
         pgi[i]=-1;
     }
     else{
         pgi[i]=v1[st.top()];

     }
     pgi[i]=i-pgi[i];
     st.push(i);
 }
 for(int i=0;i<n;i++){
     cout<<pgi[i]<<" ";
 }
}