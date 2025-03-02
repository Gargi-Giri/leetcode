#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> occurrence_count;
        
        for (int i = 0; i <= nums.size() - k; i++) {
            unordered_set<int> unique_in_subarray;
            for (int j = i; j < i + k; j++) {
                unique_in_subarray.insert(nums[j]);
            }
            for (int num : unique_in_subarray) {
                occurrence_count[num]++;
            }
        }

        int result = -1;
        for (auto &[num, count] : occurrence_count) {
            if (count == 1) {
                result = max(result, num);
            }
        }
        
        return result;
    }
};

