class MyCalendarTwo {
private:
    vector<pair<int, int>> bookings; // to store all bookings
    vector<pair<int, int>> overlaps; // to store overlapping bookings

public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        // Check for any overlaps
        for (const auto& o : overlaps) {
            if (start < o.second && end > o.first) {
                return false; // Overlaps with a previous double booking
            }
        }

        // Check for simple overlaps
        for (const auto& b : bookings) {
            if (start < b.second && end > b.first) {
                // If there is an overlap, record it for future checks
                overlaps.push_back({max(start, b.first), min(end, b.second)});
            }
        }

        // Add the new booking
        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
