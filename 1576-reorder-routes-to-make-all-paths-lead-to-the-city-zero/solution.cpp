class Solution {
private:
    // Perform DFS to count reorientations
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& vis, int& changes) {
        vis[node] = 1;  // Mark current node as visited
        for (auto& neighbourPair : adj[node]) {  // Traverse all neighbors of the current node
            int neighbour = neighbourPair.first;  // Neighbor node
            int originalDirection = neighbourPair.second;  // Direction of the edge
            if (!vis[neighbour]) {  // If the neighbor hasn't been visited
                if (originalDirection == 1) {
                    changes++;  // Count a change if the edge needs to be reoriented
                }
                dfs(neighbour, adj, vis, changes);  // Recur for the neighbor
            }
        }
    }

public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // Adjacency list to store neighbors and edge directions
        vector<vector<pair<int, int>>> adj(n);
        
        // Construct the adjacency list with directions
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back({v, 1});  // u -> v (original direction)
            adj[v].push_back({u, 0});  // v -> u (reverse direction)
        }

        int changes = 0;  // To track the number of changes needed
        vector<int> vis(n, 0);  // Visited array to mark nodes as visited
        
        // Start DFS from node 0
        dfs(0, adj, vis, changes);
        return changes;  // Return the total number of changes needed
    }
};
// class Solution {
// private:
//     void dfs(int node,vector<vector<int>> adjLs,vector<int>& vis,int &changes){
//         vis[node]=1;
//         // for(auto it:adjLs[node]){
//         //     if(!vis[it]){
//         //         dfs(it,adjLs,vis);
//         //     }
//         // }
//         for(auto& neighbour:adjLs[node]){
//           //  int neighbour=neighbourPair.first;
//           //  int originalDirection=neighbourPair.second;
//             if(!vis[neighbour]){
//                 //if(originalDirection==1){
//                     changes++;
//                 //}
//                 dfs(neighbour,adjLs,vis,changes);
//             }
//         }
//     }
// public:
//     int minReorder(int n, vector<vector<int>>& connections) {
//         vector<vector<int>> adj(n);
//         for(auto &it: connections){
//             int u=it[0];
//             int v=it[1];
//             adj[u].push_back(v);//u pointing 0 to 1
//             adj[v].push_back(u);// reverse the direction of u pointing from 1 to 0 to 0 to 1
//         }
//         int changes=0;
//         vector<int> visited(n,0);
//         dfs(0, adj, visited, changes);
//         return changes;
        
//        // return changes;
//     }
// };
