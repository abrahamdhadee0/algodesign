class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        int sign=1;
        long result=0;
       while (i < s.length() && s[i] == ' ') {
            i++;
        }

        
          if (i < s.length() && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++; 
          }
  while (i < s.length() && isdigit(s[i])) {
            int digit = s[i] - '0';
            
            // Check for overflow before updating result
            if (result > (INT_MAX - digit) / 10) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
            
            result = result * 10 + digit;
            i++;
        }
        
        return sign * result;
    }

};