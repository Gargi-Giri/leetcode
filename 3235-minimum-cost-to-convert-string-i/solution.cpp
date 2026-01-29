class Solution {
public:
    long long minimumCost(string source, string target,
                          vector<char>& original,
                          vector<char>& changed,
                          vector<int>& cost) {

        const long long INF = 1e18;
        int n = 26;

        // Step 1: distance matrix
        vector<vector<long long>> dist(n, vector<long long>(n, INF));

        // Cost to convert same character is 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Step 2: populate direct transformation costs
        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            dist[u][v] = min(dist[u][v], (long long)cost[i]);
        }

        // Step 3: Floyd–Warshall
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        // Step 4: calculate total cost
        long long totalCost = 0;
        for (int i = 0; i < source.size(); i++) {
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (dist[s][t] == INF) {
                return -1;
            }
            totalCost += dist[s][t];
        }

        return totalCost;
    }
};

