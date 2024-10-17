class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;  // Queue to store {row, col} of rotten oranges
        int freshOranges = 0;  // Counter for fresh oranges
        
        // Initialize queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});  // Add all initial rotten oranges to the queue
                } else if (grid[i][j] == 1) {
                    freshOranges++;  // Count the fresh oranges
                }
            }
        }
        
        // If there are no fresh oranges, return 0 immediately
        if (freshOranges == 0) {
            return 0;
        }

        int drow[4] = {-1, 0, 1, 0};
        int dcol[4] = {0, 1, 0, -1};
        
        int timeElapsed = -1;  // Start with -1 since the first level is 0

        // Perform BFS from all rotten oranges simultaneously
        while (!q.empty()) {
            int qSize = q.size();
            timeElapsed++;  // Increment time with each BFS level

            for (int i = 0; i < qSize; i++) {
                auto [r, c] = q.front();
                q.pop();
                
                // Visit all 4 neighbors
                for (int d = 0; d < 4; d++) {
                    int nrow = r + drow[d];
                    int ncol = c + dcol[d];
                    
                    // Check if the neighboring cell is within bounds and is a fresh orange
                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1) {
                        // Rot this orange and push it to the queue
                        grid[nrow][ncol] = 2;
                        q.push({nrow, ncol});
                        freshOranges--;  // Reduce the count of fresh oranges
                    }
                }
            }
        }

        // If there are still fresh oranges left, return -1
        return freshOranges == 0 ? timeElapsed : -1;
    }
};

// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         queue<pair<pair<int,int>,int>>q;
//         // vis[n][m];
//         vector<vector<int>> vis(n, vector<int>(m, 0));
//         //vector<vector<int>> vis;
//         if (grid.empty() || grid[0].empty()) {
//             return 0;  // If no grid or no oranges, no time needed
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//             }
//         }
//         int drow[4]={-1,0,1,0};
//         int dcol[4]={0,1,0,-1};
//         int tm=0;
//         while(!q.empty()){
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//             int t=q.front().second;
//             tm=max(tm,t);
//             q.pop();
//             for(int i=0;i<4;i++){
//                 int nrow=r+drow[i];
//                 int ncol=c+dcol[i];
//                 if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&vis[nrow][ncol]!=2&&grid[nrow][ncol]==1){
//                     q.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol]=1;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(vis[i][j]!=2&&grid[i][j]==1){
//                     return -1;
//                 }
//             }
//         }
//         return tm;
//     }
// };
