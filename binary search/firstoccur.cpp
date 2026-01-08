#include <iostream>
#include <vector>   
using namespace std;
int main(){
    int arr[9]={1,2,3,4,4,4,5,6,7};
    int target=4;
    int low=0,high=8;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==target){
            if(arr[mid-1]!=target) {
                cout<<"First occurrence at index: "<<mid<<endl;
                break;
            }
            else{
            ans=mid;
            high=mid-1; // to find first occurrence, move left
            }
        }
        else if(arr[mid]<target){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
}