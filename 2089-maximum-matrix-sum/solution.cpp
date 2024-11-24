class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int minAbs=INT_MAX;
        bool negOdd=0;
        for(auto& row: matrix){
            for(int x: row){
                minAbs=min(minAbs, abs(x));
                if (x<0){
                    sum-=x;
                    negOdd=!negOdd;
                }
                else sum+=x;
            }
        }
        return sum-2*(negOdd)*minAbs;
    }
};
