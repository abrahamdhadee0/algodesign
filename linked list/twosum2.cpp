class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> v1;
   int i = 0, j = numbers.size() - 1;
while (i < j) {
    int sum = numbers[i] + numbers[j];
    if (sum == target) { 
        v1={i+1,j+1};
        break;
     }
    else if (sum < target) i++;
    else j--;
}
return v1;
    }
};