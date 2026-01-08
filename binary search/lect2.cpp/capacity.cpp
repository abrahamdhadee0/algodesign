class Solution {
public:
    bool possible(int days,vector<int>& weights, int mid){
        int dreq=1;
        int capacity=mid;
        int i=0;
        while(i<weights.size()){
           if(weights[i]<=capacity){
              capacity-=weights[i];
              i++;
           }
           else{
             dreq++;
             capacity=mid;
           }
        }
        return dreq<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
         
         while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(days,weights,mid))high=mid-1;
            else low=mid+1;
         }
         return low;
    }
};