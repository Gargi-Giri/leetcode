class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        // Priority queue to store the smallest available chair number
        priority_queue<int, vector<int>, greater<int>> availableChairs;
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i); // We only need `n` chairs (since n friends)
        }

        // A vector to track the times when friends leave and which chair they occupied
        vector<pair<int, int>> events;

        // Add arrival and departure events to the events vector
        for (int i = 0; i < n; ++i) {
            events.push_back({times[i][0], i}); // Arrival event
            events.push_back({times[i][1], ~i}); // Departure event, ~i means departure
        }

        // Sort the events by time (and by type: arrival before departure if same time)
        sort(events.begin(), events.end());

        // To store which chair is occupied by which friend
        vector<int> occupiedChair(n, -1);

        // Process each event
        for (auto& event : events) {
            int time = event.first;
            int friendIndex = event.second;

            if (friendIndex >= 0) {  // Arrival event
                int chair = availableChairs.top();  // Get the smallest available chair
                availableChairs.pop();  // Remove the chair from available list
                occupiedChair[friendIndex] = chair;  // Assign chair to the friend

                if (friendIndex == targetFriend) {  // If it's the target friend, return the chair
                    return chair;
                }
            } else {  // Departure event
                friendIndex = ~friendIndex;  // Recover the friend index
                availableChairs.push(occupiedChair[friendIndex]);  // Add back the chair to available chairs
            }
        }
        
        return -1;  // This should never be reached
    }
};

