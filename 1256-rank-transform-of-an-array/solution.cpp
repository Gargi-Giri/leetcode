using int2=pair<int, int>;
using int2=pair<int, int>;
const int N=1e5+2;
static constexpr int M=1<<9, mask=M-1, bshift=9;
int freq[M];

void radix_sort(int2* nums, int n, int xmin, int xmax) {
    int2* buffer=(int2*)alloca(n*sizeof(int2));  // buffer
    unsigned xrange = xmax - xmin + 1;
    int Mround = max(1, int(31 - countl_zero(xrange) + bshift) / bshift);
    for(int i=0; i<n; i++)// -=xmin  makes nums[i].first>=0
        nums[i].first-=xmin;

    int2* in=nums;
    int2* out=buffer;

    for (int round=0; round < Mround; round++) {
        const int shift=round * bshift;
        memset(freq, 0, sizeof(freq));

        for (int i=0; i<n; i++)
            freq[(in[i].first >> shift) & mask]++;

        partial_sum(freq, freq+M, freq);

        for (int i = n - 1; i >= 0; i--) {
            int x = (in[i].first >> shift) & mask;
            out[--freq[x]] = in[i];
        }

        // Swap pointers for the next round
        swap(in, out);
    }
    //data is currently in buffer. We must copy it back to nums.
    if (in != nums) {
        memcpy(nums, in, n * sizeof(int2));
    }
    for(int i=0; i<n; i++)// recover by +=xmin
        nums[i].first+=xmin;
}

static int2 arrIdx[N];

class Solution {
public:
    static vector<int> arrayRankTransform(vector<int>& arr) {
        const int n=arr.size();
        if (n==0) return {};
        int xmin=INT_MAX, xmax=INT_MIN;
        for(int i=0; int x: arr){
            arrIdx[i]={x, i};
            xmin=min(x, xmin);
            xmax=max(x, xmax);
            i++;
        }
        radix_sort(arrIdx, n, xmin, xmax);
        vector<int> ans(n);
        int prev=INT_MIN, curr=0;
        for(int j=0; j<n; j++){
            auto& [x, i]=arrIdx[j];
            if (x>prev) curr++;
            ans[i]=curr;
            prev=x;
        }
        return ans;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
