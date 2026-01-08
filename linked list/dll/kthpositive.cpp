class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        vector<int> v1;
        int n=arr.size();
        int i=0;
        int j=1;
        while(v1.size()<k){
            if(i<n && arr[i]==j){
                i++;
            }
            else{
                v1.push_back(j);
            }
            j++;
        }
        return v1[k-1];
    }
};