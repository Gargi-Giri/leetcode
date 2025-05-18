using ll = uint64_t;
using Mat = vector<vector<ll>>;
static const int MOD = 1e9 + 7;

inline Mat mul(const Mat& A, const Mat& B, int n) {
    Mat C(n, vector<ll>(n));
    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            ll x = A[i][k];
            if (!x) continue;
            for (int j = 0; j < n; j++) {
                (C[i][j] += x * B[k][j]) %= MOD;
            }
        }
    }
    return C;
}

Mat mat_pow(Mat A, ll e, int n) {
    Mat R(n, vector<ll>(n));
    for (int i = 0; i < n; i++)
        R[i][i] = 1;
    while (e) {
        if (e & 1) R = mul(R, A, n);
        A = mul(A, A, n);
        e >>= 1;
    }
    return R;
}

ll ll_pow(ll base, ll e) {
    ll res = 1;
    while (e) {
        if (e & 1) (res *= base) %= MOD;
        (base *= base) %= MOD;
        e >>= 1;
    }
    return res;
}

class Solution {
public:
    vector<vector<int>> x;
    void helper(vector<int>& cur, int m, int pt) {
        if (pt == m) {
            x.emplace_back(cur);
            return;
        }
        pt++;
        for (int i = 0; i < 3; i++) {
            if (!cur.empty() && i == cur.back())
                continue;
            cur.emplace_back(i);
            helper(cur, m, pt);
            cur.pop_back();
        }
    }

    bool verify(vector<int>& a, vector<int>& b, int m) {
        for (int i = 0; i < m; i++) {
            if (a[i] == b[i]) return false;
        }
        return true;
    }

    Mat make_mat(int mat_sz, int m) {
        Mat X(mat_sz, vector<ll>(mat_sz));
        for (int i = 0; i < mat_sz; i++) {
            for (int j = 0; j < mat_sz; j++) {
                if (verify(x[i], x[j], m))
                    X[i][j] = 1;
            }
        }
        return X;
    }

    int colorTheGrid(int m, int n) {
        if (m == 1) return 3LL * ll_pow(2, n - 1) % MOD;
        if (m == 2) return 6LL * ll_pow(3, n - 1) % MOD;
        vector<int> cur;
        helper(cur, m, 0);
        int mat_sz = x.size();
        if (n == 1) return mat_sz;
        Mat X = mat_pow(make_mat(mat_sz, m), n - 1, mat_sz);
        ll res = 0;
        for (int i = 0; i < mat_sz; i++) {
            res += reduce(X[i].begin(), X[i].end(), 0LL);
        }
        return res % MOD;
    }
};
