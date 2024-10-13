class Solution {
public:
    // Function to compute the answers to the queries
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // Graph representation: Adjacency list
        unordered_map<string, vector<pair<string, double>>> graph;
        
        // Step 1: Build the graph from the equations
        for (int i = 0; i < equations.size(); ++i) {
            string A = equations[i][0], B = equations[i][1];
            double value = values[i];
            graph[A].push_back({B, value});      // A -> B with value A / B
            graph[B].push_back({A, 1.0 / value}); // B -> A with value B / A
        }
        
        // Step 2: Process each query
        vector<double> result;
        for (const auto& query : queries) {
            string C = query[0], D = query[1];
            if (graph.find(C) == graph.end() || graph.find(D) == graph.end()) {
                result.push_back(-1.0);  // Either C or D doesn't exist
            } else if (C == D) {
                result.push_back(1.0);  // C / C = 1
            } else {
                unordered_map<string, bool> visited;
                double answer = -1.0;
                bool found = dfs(graph, C, D, 1.0, visited, answer);
                result.push_back(found ? answer : -1.0);
            }
        }
        
        return result;
    }

private:
    // DFS function to traverse the graph
    bool dfs(unordered_map<string, vector<pair<string, double>>>& graph, string curr, string target, double product, unordered_map<string, bool>& visited, double& answer) {
        if (visited[curr]) return false;
        if (curr == target) {
            answer = product;
            return true;
        }
        
        visited[curr] = true;
        for (const auto& neighbor : graph[curr]) {
            if (!visited[neighbor.first]) {
                if (dfs(graph, neighbor.first, target, product * neighbor.second, visited, answer)) {
                    return true;
                }
            }
        }
        return false;
    }
};

