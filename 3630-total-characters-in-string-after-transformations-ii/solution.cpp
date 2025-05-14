class Solution 
{
    const int MOD = 1e9 + 7;

public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) 
    {
        int n = 26;

        // Step 1: Build transformation matrix
        vector<vector<long long>> T(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) 
        {
            int spread = nums[i];
            for (int j = 1; j <= spread; ++j) 
            {
                int next = (i + j) % 26;
                T[i][next] = (T[i][next] + 1) % MOD;
            }
        }

        cout << "Transformation Matrix T (1 step):\n";
        printMatrix(T);

        // Step 2: Initial frequency vector
        vector<long long> freq(n, 0);
        for (char c : s)
        {
            freq[c - 'a']++;
        }

        cout << "Initial frequency vector:\n";
        printVector(freq);

        // Step 3: Matrix exponentiation
        auto T_pow = matrixPower(T, t);

        cout << "Transformation Matrix T^" << t << ":\n";
        printMatrix(T_pow);

        // Step 4: Multiply freq vector with T^t
        vector<long long> result(n, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                result[j] = (result[j] + freq[i] * T_pow[i][j]) % MOD;
            }
        }

        cout << "Final frequency vector after " << t << " transformations:\n";
        printVector(result);

        // Step 5: Sum result
        long long total = 0;
        for (long long val : result)
        {
            total = (total + val) % MOD;
        }
        
        cout << "Total characters after transformations: " << total << "\n";
        return (int)total;
    }

private:
    vector<vector<long long>> matrixPower(vector<vector<long long>>& base, int exp) 
    {
        int n = base.size();
        vector<vector<long long>> result(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            result[i][i] = 1;
        }

        while (exp > 0) 
        {
            if (exp & 1)
            {
                result = multiply(result, base);
            } 
            
            base = multiply(base, base);
            exp >>= 1;
        }

        return result;
    }

    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B)
    {
        int n = A.size();
        vector<vector<long long>> res(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i)
        {
            for (int k = 0; k < n; ++k)
            {
                if (A[i][k] != 0)
                {
                    for (int j = 0; j < n; ++j)
                    {
                        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
                    }
                }
            }
        }
                
        return res;
    }

    void printMatrix(const vector<vector<long long>>& mat)
    {
        for (int i = 0; i < mat.size(); ++i)
        {
            for (int j = 0; j < mat[i].size(); ++j)
            {
                cout << mat[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void printVector(const vector<long long>& vec)
    {
        for (int i = 0; i < vec.size(); ++i)
        {
            cout << char('a' + i) << ":" << vec[i] << ' ';
        }
        cout << '\n';
    }
};
