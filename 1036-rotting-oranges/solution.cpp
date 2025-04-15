class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int freshOranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    freshOranges++;
                }
            }
        }
        if(freshOranges==0) return 0;
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1};
        int timeElapsed=-1;
        while(!q.empty()){
            int qSize=q.size();
            timeElapsed++;
            for(int i=0;i<qSize;i++){
                auto[r,c]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int nrow=r+drow[d];
                    int ncol=c+dcol[d];
                    if(nrow>=0&&nrow<n&&ncol>=0&&ncol>=0&&ncol<m&&grid[nrow][ncol]==1){
                        grid[nrow][ncol]=2;
                        q.push({nrow,ncol});
                        freshOranges--;
                    }
                }
            }
        }
        return freshOranges==0?timeElapsed:-1;
    }
};
