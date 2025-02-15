class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double left = 1e9, right = 0;

        // Find the min and max y values to set the binary search range
        for (auto& sq : squares) {
            left = min(left, (double)sq[1]);       // Lowest y
            right = max(right, (double)sq[1] + sq[2]); // Highest y + side length
        }

        auto computeArea = [&](double y) {
            double area_above = 0, area_below = 0;
            for (auto& sq : squares) {
                double y1 = sq[1], y2 = sq[1] + sq[2]; // Bottom and top of square
                double l = sq[2];

                if (y <= y1) { // Entire square is above the line
                    area_above += l * l;
                } else if (y >= y2) { // Entire square is below the line
                    area_below += l * l;
                } else { // The line cuts the square
                    double above = y2 - y; // Height of upper part
                    double below = y - y1; // Height of lower part
                    area_above += above * l;
                    area_below += below * l;
                }
            }
            return area_above - area_below;
        };

        // Binary search to find the minimum y such that areas are equal
        while (right - left > 1e-5) {
            double mid = (left + right) / 2.0;
            if (computeArea(mid) > 0) { // More area above, move down
                left = mid;
            } else { // More area below or equal, move up
                right = mid;
            }
        }

        return left; // The smallest valid y
    }
};

