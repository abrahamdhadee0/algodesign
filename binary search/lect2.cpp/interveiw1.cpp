// search in rotated sorted array uniuqe
//pivot element is the smallest element in the array
//
class solution{
    public:
    int search(vector<int>&nums,int target){
        int n=nums.size();
        int lo=0;
        int high=n-1;
        int pivot=-1;
        //findinding pivot
        while(lo<=high){
            int mid=lo+(high-lo)/2;
            if(nums[mid]<nums[mid+1]&& nums[mid]<nums[mid-1]){
                pivot=mid;
                break;
            }
            if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]){
                pivot=mid+1;
                break;
            }
            if(nums[mid]>nums[high]) lo=mid+1;
          else high=mid-1;
        }
        if(target!=nums[0]&& target<=nums[pivot-1]){
            low=0;
            high=pivot-1;
            while(low<=high){
                int mid=lo+(high-low)/2;
                if(nums[mid]==target) return mid;
                else if(nums[mid]>target) hi=mid-1;
                else low=mid+1;
            }
        }
        return -1;
    }
}