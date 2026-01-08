  #include<bits/stdc++.h>
using namespace std;    

  int main(){
    int low=0;
    int high=n-1;
    while(low<=high){
       int mid=low+(high-low)/2;
       if(arr[mid]==mid) lo=mid+1;
       else{
        ans=mid;
        high=mid-1
       }
    }
    cout<<ans<<endl;
  }