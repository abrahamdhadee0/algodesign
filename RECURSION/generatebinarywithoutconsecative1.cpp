// User function Template for C++

class Solution {
public:
    void helper(int num, string s, vector<string>& v1) {
        if (s.length() == num) {/// thi ensures that the length of the string is equal to the given number.so to push at end
            v1.push_back(s);
            return;
        }

        // Always allowed to put '0'
        helper(num, s + '0', v1);

        // Only put '1' if previous char is '0'
        if (s.empty() || s.back() == '0') {
            helper(num, s + '1', v1);
        }
    }

    vector<string> generateBinaryStrings(int num) {
        vector<string> v1;
        string s;
        helper(num, s, v1);
        return v1;
    }
};
