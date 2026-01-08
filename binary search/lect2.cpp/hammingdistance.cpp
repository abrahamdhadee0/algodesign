class Solution {
public:
    int hammingDistance(int x, int y) {
        unsigned int val = static_cast<unsigned int>(x ^ y); // use unsigned
        int count = 0;
        while (val != 0) {
            count += (val & 1);
            val >>= 1;
        }
        return count;
    }
};
