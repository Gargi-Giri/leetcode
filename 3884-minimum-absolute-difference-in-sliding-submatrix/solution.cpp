static int kksub[900], INF=2e5+1;
static constexpr int N=512, MASK=511, bshift=9, bias=-1e5;
static int freq[N];

void radix_sort(int* nums, int n) {// 2 rounds
    int* buf=(int*)alloca(n * sizeof(int));
    int* in=nums;
    int* out=buf;

    //1st round
    memset(freq, 0, sizeof(freq));

    for (int i=0; i<n; i++) 
        freq[in[i] & MASK]++;

    partial_sum(freq, freq+N, freq);

    for (int i=n-1; i>=0; i--) {
        const int v=in[i];
        out[--freq[v & MASK]]=v;
    }

    // 2nd round
    memset(freq, 0, sizeof(freq));

    for (int i=0; i<n; i++)
        freq[(out[i]>>bshift) & MASK]++;

    partial_sum(freq, freq+N, freq);

    for (int i=n-1; i>= 0; i--) {
        const int v=out[i];
        in[--freq[(v>>bshift) & MASK]]=v;
    }
}
class Solution {
public:
    static vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        const int m=grid.size(), n=grid[0].size(), kk=k*k;
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1));
        const int m0=m-k, n0=n-k;
        for (int i=0; i<=m0; i++) {
            for (int j=0; j<=n0; j++) {
                int idx=0, ik=i+k, jk=j+k;
                for (int x=i; x<ik; x++) {
                    for (int y=j; y<jk; y++) 
                        kksub[idx++]=grid[x][y]-bias;
                }
                radix_sort(kksub, kk);
                int minD=INF;
                for(int a=1; a<kk; a++){
                    int diff=kksub[a]-kksub[a-1];
                    if (diff>0) minD=min(minD, diff);
                }
                ans[i][j]=(minD==INF)?0:minD;
            }
        }
        return ans;
    }
}; 
static const auto init = []() noexcept {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();
