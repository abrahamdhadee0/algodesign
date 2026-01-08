class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0;
        int high = n - 1;
        int pivot = -1;

        // Finding pivot
        while (lo <= high) {
            int mid = lo + (high - lo) / 2;

            // Check boundaries before accessing mid+1 and mid-1
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;

            if (nums[mid] < nums[next] && nums[mid] < nums[prev]) {
                pivot = mid;
                break;
            }
            if (nums[mid] > nums[next] && nums[mid] > nums[prev]) {
                pivot = next;
                break;
            }
            if (nums[mid] > nums[high]) {
                lo = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // If pivot is not found, array is not rotated
        if (pivot == -1) {
            pivot = 0;
        }

        // Decide which part to search
        if (target == nums[pivot]) {
            return pivot;
        }
        if (pivot == 0) {  // Not rotated, search the entire array
            lo = 0;
            high = n - 1;
        } else if (target >= nums[0]) {
            lo = 0;
            high = pivot - 1;
        } else {
            lo = pivot;
            high = n - 1;
        }

        // Standard binary search
        while (lo <= high) {
            int mid = lo + (high - lo) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                high = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }
};
