class Solution {
public:
    long long totalCount = 0;
    vector<long long> fact;
    set<vector<int>> uniqueFreq;

    bool check(const vector<int>& num, int k) {
        long long palindrome = 0;
        for (int d : num)
            palindrome = palindrome * 10 + d;
        return (palindrome % k == 0);
    }

    long long permutation(const vector<int>& freqs, int n) {
        long long res = fact[n];
        for (int freq : freqs)
            res /= fact[freq];
        return res;
    }

    long long permutationStart0(vector<int> freqs, int n) {
        if (freqs[0] == 0)
            return 0;

        freqs[0]--;
        return permutation(freqs, n - 1);
    }

    long long countValidPermutations(vector<int> freqs, int n) {
        return permutation(freqs, n) - permutationStart0(freqs, n);
    }

    void generatePalindromes(vector<int>& num, int l, int r, int n, int k) {
        if (l > r) {
            if (!check(num, k))
                return;

            vector<int> freqs(10, 0);
            for (int d : num)
                freqs[d]++;

            if (uniqueFreq.find(freqs) == uniqueFreq.end()) {
                totalCount += countValidPermutations(freqs, n);
                uniqueFreq.insert(freqs);
            }
        } else {
            for (int d = (l == 0) ? 1 : 0; d <= 9; d++) {
                num[l] = num[r] = d;
                generatePalindromes(num, l + 1, r - 1, n, k);
            }
        }
    }

    long long countGoodIntegers(int n, int k) {
        fact.resize(11);
        fact[0] = 1;
        for (int i = 1; i <= 10; i++)
            fact[i] = fact[i - 1] * i;

        vector<int> num(n, 0);
        generatePalindromes(num, 0, n - 1, n, k);
        return totalCount;
    }
};
