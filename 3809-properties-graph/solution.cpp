#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        vector<vector<int>> adj(n);

        // Convert properties[i] into a bitset for faster intersection checks
        vector<bitset<101>> bitsets(n); // Since 1 <= properties[i][j] <= 100

        for (int i = 0; i < n; ++i) {
            for (int num : properties[i]) {
                bitsets[i].set(num);  // Mark the presence of 'num' in row i
            }
        }

        // Build adjacency list efficiently
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((bitsets[i] & bitsets[j]).count() >= k) {  // Fast intersection
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        // Count connected components using DFS
        vector<bool> visited(n, false);
        int components = 0;

        function<void(int)> dfs = [&](int node) {
            visited[node] = true;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) dfs(neighbor);
            }
        };

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                components++;
                dfs(i);
            }
        }

        return components;
    }
};

