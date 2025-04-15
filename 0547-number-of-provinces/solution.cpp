class Solution {
private:
    void dfs(int node, vector<vector<int>>& adjLs, vector<bool>& vis) {
        vis[node] = true;
        for (int neighbor : adjLs[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adjLs, vis);
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);  

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<bool> vis(V, false);  // ✅ No C-style array
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                count++;
                dfs(i, adjLs, vis);
            }
        }
        return count;
    }
};

