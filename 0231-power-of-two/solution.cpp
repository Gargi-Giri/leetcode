class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false; // Negative or zero can't be power of two
        if (n == 1) return true;  // 2^0 = 1
        if (n % 2 != 0) return false; // Not divisible by 2
        return isPowerOfTwo(n / 2); // Keep dividing by 2
    }
};

