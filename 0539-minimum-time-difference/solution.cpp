class Solution {
public:
    // Function to convert "HH:MM" into total minutes since midnight
    int timeToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        // Convert each time point to minutes and store in the vector
        for (const string& time : timePoints) {
            minutes.push_back(timeToMinutes(time));
        }
        
        // Sort the minutes vector
        sort(minutes.begin(), minutes.end());
        
        int minDiff = INT_MAX;
        
        // Compare adjacent time points
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Don't forget to compare the last and first time point in a circular way
        minDiff = min(minDiff, (1440 - minutes.back() + minutes[0]));
        
        return minDiff;
    }
};

