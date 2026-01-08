class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while(low < high) {
            int mid = low + (high - low) / 2;
            
            if(nums[mid] > nums[mid + 1]) {
                // Peak is to the left including mid
                high = mid;
            } else {
                // Peak is to the right excluding mid
                low = mid + 1;
            }
        }
        
        // At the end, low == high and pointing to the peak element index
        return low;
    }
};
