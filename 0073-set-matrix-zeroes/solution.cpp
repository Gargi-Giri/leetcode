class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<pair<int,int>>adj;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (matrix[i][j]==0){
                    adj.push_back({i,j});
                    
                }
            }
        }
        for(pair<int,int>&pr:adj){
            
            for(int z=0;z<n;z++) matrix[z][pr.second]=0;
            for(int z=0;z<m;z++) matrix[pr.first][z]=0;
        }
    }
};
