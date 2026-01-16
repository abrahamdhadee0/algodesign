class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]]++;
        }
        unordered_set<int> s1;
        for(auto x:m){
            int freq=x.second;
            if(s1.find(freq)!=s1.end()) return false;
            else s1.insert(freq);
        }
        return true;
    }
};
/// pehle humne har element ki frequency ko map me store kiya
/// fir humne har frequency ko set me daala
/// agar koi frequency pehle se set me exist karti hai to hum false return kar dete hain
/// agar sabhi frequencies unique hain to hum true return kar dete hain
