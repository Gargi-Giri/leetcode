
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m=ob.size(),n=ob[0].size();
        cout<<n<<" "<<m;
        if(ob[m-1][n-1]==1 || ob[0][0]==1) return 0;
        if(m==1 && n==1 && ob[0][0]==0) return 1;
        for(int i=1;i<m;i++){
           if(ob[i][0]==0) ob[i][0]=-1;
           else break;
        }
        for(int i=1;i<n;i++){
           if(ob[0][i]==0) ob[0][i]=-1;
           else break;
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(ob[i][j]==1) continue;
                if(ob[i][j-1]!=1) ob[i][j]=ob[i][j-1]; 
                if(ob[i-1][j]!=1) ob[i][j]+=ob[i-1][j]; 
            }
        }
        return (-ob[m-1][n-1]);
    }
};
// int mod=(int)(1e9+2);
// class Solution {
// private:
//     int f(int i,int j,vector<vector<int>> &mat,vector<vector<int>> dp){
//         if(i>=0&&j>=0&&mat[i][j]==1) return 0;
//         if(i==0&&j==0) return 1;
//         if(i<0||j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=f(i-1,j,mat,dp);
//         int left=f(i,j-1,mat,dp);
//         return dp[i][j]=(up+left)%mod;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int n=obstacleGrid.size();
//         int m=obstacleGrid[0].size();
//         vector<int> prev(m,0);
//         //int dp[n][m];
//         for(int i=0;i<n;i++){
//             vector<int> curr(m,0);
//             for(int j=0;j<m;j++){
//                 if(obstacleGrid[i][j]==1) curr[j]=0;
//                 else if(i==0&&j==0) curr[j]=1;
//                 else{
//                     int up=0,left=0;
//                     if(i>0) up=prev[j];
//                     if(j>0) left=curr[j-1];
//                     curr[j]=(up+left)%mod;
//                 }
//             }
//             prev=curr;
//         }
//         return prev[m-1];
//     }
// };

// int mod=(int)(1e9+2);
// class Solution {
// private:
//     int f(int i,int j,vector<vector<int>> &mat,vector<vector<int>> dp){
//         if(i>=0&&j>=0&&mat[i][j]==1) return 0;
//         if(i==0&&j==0) return 1;
//         if(i<0||j<0) return 0;
//         if(dp[i][j]!=-1) return dp[i][j];
//         int up=f(i-1,j,mat,dp);
//         int left=f(i,j-1,mat,dp);
//         return dp[i][j]=(up+left)%mod;
//     }
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//         int m=obstacleGrid.size();
//         int n=obstacleGrid[0].size();
//         vector<vector<int>> dp(n,vector<int>(m,-1));
//         return f(n-1,m-1,obstacleGrid,dp);
//     }
// };
