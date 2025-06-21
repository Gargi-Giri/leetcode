class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char ch : word) {
            freq[ch]++;
        }

        vector<int> freqs;
        for (auto& [ch, count] : freq) {
            freqs.push_back(count);
        }

        sort(freqs.begin(), freqs.end());
        int n = freqs.size();
        int res = INT_MAX;

        for (int i = 0; i < n; ++i) {
            int target = freqs[i]; 
            int deletions = 0;

            for (int j = 0; j < n; ++j) {
                if (freqs[j] < target) {
                    deletions += freqs[j]; 
                } else if (freqs[j] > target + k) {
                    deletions += freqs[j] - (target + k); 
                }
            }

            res = min(res, deletions);
        }

        return res;
    }
};

