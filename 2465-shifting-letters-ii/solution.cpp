class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> A(n, 0);
        
        // Apply the shifts
        for (const auto& shift : shifts) {
            int l = shift[0];
            int r = shift[1];
            int t = shift[2];
            
            if (t == 1) {
                A[l] += 1;
                if (r + 1 < n) {
                    A[r + 1] -= 1;
                }
            } else {
                A[l] -= 1;
                if (r + 1 < n) {
                    A[r + 1] += 1;
                }
            }
        }
        
        // Compute the prefix sum
        for (int i = 1; i < n; ++i) {
            A[i] += A[i - 1];
        }
        
        // Apply the shifts to the string
        for (int i = 0; i < n; ++i) {
            int shift = (A[i] % 26 + 26) % 26; // Ensure shift is non-negative
            s[i] = 'a' + (s[i] - 'a' + shift) % 26;
        }
        
        return s;
    }
};

