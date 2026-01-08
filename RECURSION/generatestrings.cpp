#include <bits/stdc++.h>
using namespace std;        

class Solution {
public:
    void generate(string s, int n, vector<string>& v1) {
        if (s.length() == n) {
            v1.push_back(s);
            return;
        }

        // Always allowed to put '1'
        generate(s + '1', n, v1);

        // Only put '0' if previous char is not '0'
        if (s.empty() || s.back() == '1') {
            generate(s + '0', n, v1);
        }
    }

    vector<string> validStrings(int n) {
        vector<string> v1;
        string s;
        generate(s, n, v1);
        return v1;
    }
};
