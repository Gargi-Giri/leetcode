class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int minOps = k, whiteCount = 0;

        // Count white blocks in the first window of size k
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') whiteCount++;
        }
        minOps = whiteCount;

        // Slide the window across the string
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') whiteCount++;
            if (blocks[i - k] == 'W') whiteCount--;

            minOps = min(minOps, whiteCount);
        }

        return minOps;
    }
};

