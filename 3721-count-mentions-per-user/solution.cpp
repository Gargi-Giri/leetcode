#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        vector<int> mentions(numberOfUsers, 0);
        unordered_map<int, int> offlineUntil;  // Stores when each user comes back online

        // Step 1: Sort events by timestamp, ensuring OFFLINE events come before MESSAGE if timestamps match
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]), timeB = stoi(b[1]);
            if (timeA == timeB) return a[0] == "OFFLINE"; // Process OFFLINE first
            return timeA < timeB;
        });

        // Step 2: Process events in sorted order
        for (const auto& event : events) {
            string eventType = event[0];
            int timestamp = stoi(event[1]);
            string value = event[2];

            // Restore users who should come back online strictly before this timestamp
            vector<int> toRemove;
            for (auto& [user, restoreTime] : offlineUntil) {
                if (restoreTime <= timestamp) {
                    toRemove.push_back(user);
                }
            }
            for (int user : toRemove) {
                offlineUntil.erase(user);
            }

            if (eventType == "OFFLINE") {
                int userId = stoi(value);
                offlineUntil[userId] = timestamp + 60;  // Mark user offline until `timestamp + 60`
            } 
            else if (eventType == "MESSAGE") {
                if (value == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } 
                else if (value == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUntil.find(i) == offlineUntil.end()) { // Only count currently online users
                            mentions[i]++;
                        }
                    }
                } 
                else { // Specific ID mentions
                    istringstream iss(value);
                    string token;
                    while (iss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};


