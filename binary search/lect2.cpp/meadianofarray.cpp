class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> result(a.size() + b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), result.begin()); 
        int n = result.size();

        if(n == 1) return result[0];
        if(n == 2) return (result[0] + result[1]) / 2.0;

        if(n % 2 == 0) {
            return (result[n/2 - 1] + result[n/2]) / 2.0;
        } else {
            return result[n/2];
        }
    }
};
