class Solution {
public:
   const long long mod = 1e9 + 7;
long long pow(long long x ,long long y){
    if(y==0) return 1;
    long long ans=pow(x,y/2);
    ans*=ans;
    ans%=mod;
    if(y%2)ans*=x;
    ans%=mod;
    return ans;
}
    int countGoodNumbers(long long n) {
            long long even_positions = (n + 1) / 2;  // positions 0, 2, 4, ...
        long long odd_positions = n / 2;         // positions 1, 3, 5, ...

        long long even_part = pow(5, even_positions);
        long long odd_part = pow(4, odd_positions);
        return (even_part * odd_part) % mod;
    }
};
// U JUST HAVE TO USE THE FORMULA 5^((n+1)/2)*4^(n/2) AND TAKE MODULO 10^9+7
// 5 CHOICES FOR EVEN POSITIONS AND 4 CHOICES FOR ODD POSITIONS
// USE FAST EXPONENTIATION TO CALCULATE POWER IN LOG(N) TIME    
// TC: O(LOGN) SC: O(1)
// https://leetcode.com/problems/count-good-numbers/description/
// https://www.youtube.com/watch?v=4Yc1b0kY7iA
// https://takeuforward.org/data-structure/count-good-numbers-dp-on-bits-strings/
// https://www.geeksforgeeks.org/exponentiation-by-squaring/
// https://www.codingninjas.com/codestudio/library/fast-exponentiation
// https://www.codingninjas.com/codestudio/library/modular-exponentiation
// https://www.geeksforgeeks.org/modular-exponentiation-power-in-modular-ar
// https://www.youtube.com/watch?v=Yk1pxkz0b8s
// https://www.youtube.com/watch?v=Zb4eR9c1Yz