class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int,int>> directions={{0,1},{1,0},{0,-1},{-1,0}};
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
        obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }
    
        int x=0,y=0;
        int directionIndex=0;
        int maxDistance=0;
        for(int command:commands){
            if(command==-2){
                directionIndex=(directionIndex+3)%4;
            }
            else if(command==-1){
                directionIndex=(directionIndex+1)%4;
            }
            for(int i=0;i<command;++i){
                int newX=x+directions[directionIndex].first;
                int newY=y+directions[directionIndex].second;
                if (obstacleSet.find(to_string(newX) + "," + to_string(newY)) != obstacleSet.end()) {
                    break; // Stop moving if we hit an obstacle
                }
                
                x = newX;
                y = newY;
                
                // Calculate the squared distance and update max distance
                maxDistance = max(maxDistance, x * x + y * y);
            }
        }
            return maxDistance;
    }
};
