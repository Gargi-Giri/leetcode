class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        const int MAX = 1e6 + 1;
        vector<bool> isPrime(MAX, true);
        isPrime[0] = isPrime[1] = false;

        // Sieve of Eratosthenes
        for (int i = 2; i * i < MAX; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Collect primes in the range [left, right]
        vector<int> primes;
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) primes.push_back(i);
        }

        // If less than 2 primes exist, return [-1, -1]
        if (primes.size() < 2) return {-1, -1};

        // Find the closest prime pair
        int minDiff = INT_MAX, num1 = -1, num2 = -1;
        for (int i = 1; i < primes.size(); ++i) {
            int diff = primes[i] - primes[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                num1 = primes[i - 1];
                num2 = primes[i];
            }
        }

        return {num1, num2};
    }
};

