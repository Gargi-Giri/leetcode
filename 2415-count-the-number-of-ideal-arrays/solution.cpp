#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<long long> fact, invFact;

    long long modPow(long long x, long long y) {
        long long res = 1;
        x %= MOD;
        while (y) {
            if (y & 1) res = (res * x) % MOD;
            x = (x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int maxN) {
        fact.resize(maxN + 1);
        invFact.resize(maxN + 1);
        fact[0] = 1;
        for (int i = 1; i <= maxN; ++i)
            fact[i] = (fact[i-1] * i) % MOD;
        for (int i = 0; i <= maxN; ++i)
            invFact[i] = modPow(fact[i], MOD-2);
    }

    long long comb(int a, int b) {
        if (a < b) return 0;
        return fact[a] * invFact[b] % MOD * invFact[a-b] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        int maxN = n + 14; // 14 is the max prime power possible (since log2(10^4) ≈ 14)
        precomputeFactorials(maxN);

        vector<int> spf(maxValue + 1); // smallest prime factor
        for (int i = 2; i <= maxValue; ++i)
            spf[i] = i;
        for (int i = 2; i * i <= maxValue; ++i)
            if (spf[i] == i)
                for (int j = i * i; j <= maxValue; j += i)
                    if (spf[j] == j)
                        spf[j] = i;

        long long ans = 0;
        for (int v = 1; v <= maxValue; ++v) {
            int x = v;
            long long ways = 1;
            while (x > 1) {
                int p = spf[x], count = 0;
                while (spf[x] == p) {
                    x /= p;
                    count++;
                }
                ways = (ways * comb(count + n - 1, count)) % MOD;
            }
            ans = (ans + ways) % MOD;
        }
        return ans;
    }
};

