class Solution {
public:
 bool possible(int h,vector<int>& piles,int mid){
    long long hours = 0;
    for (int bananas : piles) {
        hours += (bananas + mid - 1) / mid;  // ceil division
        if (hours > h) return false;         // early exit
    }
    return hours <= h;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());

        while(low<=high){
            int mid=low+(high-low)/2;
            if(possible(h,piles,mid))high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};