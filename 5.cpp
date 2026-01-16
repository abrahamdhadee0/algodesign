class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(m.find(rem)!=m.end()){
                ans.push_back(m[rem]);
            ans.push_back(i);    
        }
        else m[nums[i]]=i;
    }
    return ans;
    }
};
/// is approach me humne ek unordered map ka use kiya hai
/// jisme humne array ke elements ko key aur unke indices ko value ke roop me store kiya hai
/// fir humne array ke har element ke liye check kiya ki kya target - current
/// element map me exist karta hai
/// agar exist karta hai to humne uske index aur current index ko answer me push kar diya
/// agar exist nahi karta to humne current element ko map me daal diya
/// finally humne answer return kar diya
