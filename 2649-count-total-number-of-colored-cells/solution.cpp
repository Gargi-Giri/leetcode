class Solution {
public:
    long coloredCells(int n) {
        long total = 1;
        for (int i = 1; i < n; i++) {
            total += 4 * i;
        }
        return total;
    }
};
