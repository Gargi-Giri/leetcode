class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n=fruits.size(),res=0;
        for(int i=0;i<n;i++){
            res+=fruits[i][i];
        }
        for(int pass=0;pass<2;pass++){
            if(pass==1){
                for(int i=0;i<n;i++){
                    for(int j=i+1;j<n;j++){
                        swap(fruits[i][j],fruits[j][i]);
                    }
                }
            }
            vector<int> prev(n,-1),curr(n,-1);
            prev[n-1]=fruits[0][n-1];
            for(int row=1;row<n-1;row++){
                fill(curr.begin(),curr.end(),-1);
                for(int i=0;i<n;i++){
                    if(prev[i]<0) continue;
                    if(i>0)
                        curr[i-1]=max(curr[i-1],prev[i]+fruits[row][i-1]);
                    if(i<n-1)   
                        curr[i+1]=max(curr[i+1],prev[i]+fruits[row][i+1]);
                    curr[i]=max(curr[i],prev[i]+fruits[row][i]);
                }
                swap(prev,curr);
            }
            res+=prev[n-1];
        }
        return res;
    }
};

