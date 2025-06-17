class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) result = result * base % MOD;
            base = base * base % MOD;
            exp >>= 1;
        }
        return result;
    }

    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[maxN] = modPow(fact[maxN], MOD - 2); // Fermat inverse
        for (int i = maxN - 1; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long binomial(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int countGoodArrays(int n, int m, int k) {
        precomputeFactorials(n);
        long long combinations = binomial(n - 1, k);
        long long power = modPow(m - 1, n - 1 - k);
        long long result = combinations * power % MOD;
        result = result * m % MOD;
        return (int)result;
    }
};

