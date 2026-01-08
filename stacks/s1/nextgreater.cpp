#include <bits/stdc++.h>
using namespace std;
vector<int> nextgreater(vector<int> & v1){
    int n=v1.size();
    vector<int> v2(n,-1);
    stack<int> st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && v1[st.top()]<=v1[i]){
            st.pop();
        }
        if(!st.empty()){
            v2[i]=v1[st.top()];
        }
        st.push(i);
    }
    return v2;

}
int main(){

}