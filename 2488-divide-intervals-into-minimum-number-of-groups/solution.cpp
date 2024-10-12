class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<pair<int, int>> events;
        
        // Create events for the start and end of each interval
        for (auto& interval : intervals) {
            events.push_back({interval[0], 1});      // Starting point of an interval
            events.push_back({interval[1] + 1, -1}); // End point of an interval (+1 to avoid overlap)
        }
        
        // Sort the events by time
        sort(events.begin(), events.end());
        
        int maxGroups = 0, currentGroups = 0;
        
        // Process all events
        for (auto& event : events) {
            currentGroups += event.second; // Add 1 for a start, subtract 1 for an end
            maxGroups = max(maxGroups, currentGroups);
        }
        
        return maxGroups;
    }
};

