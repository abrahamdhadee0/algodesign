#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<string>& s1, string s, int n,int close ,int open) {
        // If the number of closing parentheses used equals n,
        // it means we have formed a valid sequence of n pairs.
        // So, we add the current string to the result and return.
        if (close==n) {
            s1.push_back(s);
            return;
        }
        if(open<n) helper(s1,s+'(',n,close,open+1);
        if(close<open) helper(s1,s+')',n,close+1,open);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> s1;
        string s;
        helper(s1, s, n,0,0);
        return s1;
    }
};
