
class Solution {
private:
    // Depth First Search helper function
    void dfs(int node, vector<vector<int>>& rooms, vector<int>& vis) {
        vis[node] = 1;  // Mark the current room as visited
        for (auto it : rooms[node]) {  // Go through each key in the current room
            if (!vis[it]) {  // If the room corresponding to the key has not been visited
                dfs(it, rooms, vis);  // Recursively visit the room
            }
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();  // Number of rooms
        vector<int> vis(n, 0);  // Initialize the visited array to track visited rooms

        // Start DFS from room 0
        dfs(0, rooms, vis);

        // Check if all rooms have been visited
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) return false;  // If any room is not visited, return false
        }

        return true;  // All rooms were visited
    }
};

