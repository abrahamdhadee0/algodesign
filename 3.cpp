class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n-1;i++){
            string rev=arr[i];
            reverse(rev.begin(),rev.end());
            for(int j=i+1;j<n;j++){
                if(rev==arr[j]) count++;
            }
        }
        return count;
    }
};
//pehle humne har eacjh a[i] string ko reverse kiya
// fir usko baad me baaki strings se compare kiya
// agar koi match milta hai to count ko increment kar diya

class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& arr) {
        int n=arr.size();
        int count=0;
        unordered_set<string> s;
        for(int i=0;i<n;i++){
            s.insert(arr[i]);
            
        }
        for(int i=0;i<n;i++){
            string rev=arr[i];
            reverse(rev.begin(),rev.end());
            if(arr[i]==rev) continue;
            if(s.find(rev)!=s.end()){
                count++;
                s.erase(arr[i]);
            }
        }
        return count;
    }
};
/// is approach me humne pehle saare strings ko set me daal diya
/// fir har string ko reverse karke check kiya ki kya wo set me exist karti hai\
/// agar exist karti hai to count ko increment kar diya aur us string ko set se erase kar diya taaki duplicate counting na ho
/// finally count return kar diya
/// is approach ki time complexity o(n*m) hai jaha n strings ki sankhya hai aur m average length of string hai