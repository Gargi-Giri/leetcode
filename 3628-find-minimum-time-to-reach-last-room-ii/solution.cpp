class Solution {
    public:
        int minTimeToReach(vector<vector<int>>& moveTime) {
                int n = moveTime.size(), m = moveTime[0].size();
                        vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                                vector<vector<int>> minTime(n, vector<int>(m,INT_MAX));
                                        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
                                                pq.push({0, {0,0}});
                                                        minTime[0][0] = 0;
                                                                while(!pq.empty()){
                                                                            auto[currTime, pos] = pq.top();
                                                                                        int row = pos.first;
                                                                                                    int col = pos.second;
                                                                                                                pq.pop();
                                                                                                                            if(row == n-1 && col == m-1) return currTime;
                                                                                                                                        for(auto d: dir){
                                                                                                                                                        int Nrow = row + d[0];
                                                                                                                                                                        int Ncol = col + d[1];
                                                                                                                                                                                        if(Nrow>=0 && Nrow<n && Ncol>=0 && Ncol<m){
                                                                                                                                                                                                            int moveCost = (Nrow + Ncol) % 2 == 0 ? 2 : 1;
                                                                                                                                                                                                                                int waitTime = max(moveTime[Nrow][Ncol] - currTime, 0);
                                                                                                                                                                                                                                                    int nextTime = currTime + waitTime + moveCost;
                                                                                                                                                                                                                                                                        if(nextTime < minTime[Nrow][Ncol]){
                                                                                                                                                                                                                                                                                                pq.push({nextTime, {Nrow, Ncol}});
                                                                                                                                                                                                                                                                                                                        minTime[Nrow][Ncol] = nextTime;
                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                        return -1;
                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                            };

