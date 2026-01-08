#include <bits/stdc++.h>
using namespace std;
 
void push(vector<int>&arr,int x){
    arr.push_back(x);
}
int pop(vector<int>&arr){
    if(arr.size()==0){
        cout<<"Array is empty"<<endl;
        return -1;
    }
    int val= arr.back();
    arr.pop_back();
    return val;
}
int top(vector<int>&arr){
    if(arr.size()==0){
        cout<<"Array is empty"<<endl;
        return -1;
    }
    return arr.back();
}
int size(vector<int>&arr){
    return arr.size();
}
int main(){
    vector<int> arr;
    push(arr,10);
    push(arr,20);
    push(arr,30);
    cout<<"Top element: "<<top(arr)<<endl;
    cout<<"Size of array: "<<size(arr)<<endl;
    cout<<"Popped element: "<<pop(arr)<<endl;
    cout<<"Top element after pop: "<<top(arr)<<endl;
    cout<<"Size of array after pop: "<<size(arr)<<endl;
}
