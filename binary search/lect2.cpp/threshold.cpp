class Solution {
public:
    bool possible(vector<int>& nums,int mid, int threshhold){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum>threshhold)return false;
            sum+=(ceil(nums[i]/double(mid)));
        }
        return sum<=threshhold;
    }
    int smallestDivisor(vector<int>& nums, int threshhold) {
        int low=1,high=*max_element(nums.begin(),nums.end());

        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(nums,mid,threshhold)){
                high=mid-1;
                ans=mid;
            }
            else low=mid+1;
        }
        return ans;
    }
};