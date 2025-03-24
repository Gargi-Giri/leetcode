class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int freeDays = 0, last = 0;
        for (const auto& m : meetings) {
            if (m[0] > last + 1) freeDays += m[0] - last - 1;
            last = max(last, m[1]);
        }
        return freeDays + max(0, days - last);
    }
};
