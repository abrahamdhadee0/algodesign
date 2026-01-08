#include <iostream>
#include <vector>
using namespace std;
void subaarray(vector<int> v,int arr[],int n,int idx){
    if(idx==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    subaarray(v,arr,n,idx+1);
    if(v.size()==0){
    v.push_back(arr[idx]);
    subaarray(v,arr,n,idx+1);
    }
    else if(arr[idx-1]==v.back()){
        v.push_back(arr[idx]);
        subaarray(v,arr,n,idx+1);
    }
   
}
int main(){
    int arr[]={1,2,3,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int> v;
    subaarray(v,arr,n,0);
    return 0;

}
// this will work only in unique eleements only .
//