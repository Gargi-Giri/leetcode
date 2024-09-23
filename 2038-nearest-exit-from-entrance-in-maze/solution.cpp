class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows=maze.size();
        int cols=maze[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(rows,vector<bool>(cols,false));
        vector<pair<int,int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
        q.push({entrance[0],entrance[1]});
        visited[entrance[0]][entrance[1]]=true;
        int steps=0;
        while(!q.empty()){
            int Size=q.size();
            for(int i=0;i<Size;++i){
                auto[row,col]=q.front();
                q.pop();
                if((row!=entrance[0]||col!=entrance[1])&&(row==0||row==rows-1||col==0||col==cols-1)){
                    return steps;
                }
                for(const auto&[dr,dc]:directions){
                    int newRow=row+dr;
                    int newCol=col+dc;
                    if(newRow>=0 && newRow<rows && newCol>=0 && newCol<cols && maze[newRow][newCol]=='.' && !visited[newRow][newCol]){
                        visited[newRow][newCol]=true;
                        q.push({newRow,newCol});
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};
