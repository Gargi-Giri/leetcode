#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        for (int a : answers) {
            count[a]++;
        }
        
        int result = 0;
        for (auto& [x, c] : count) {
            int groupSize = x + 1;
            int groupsNeeded = ceil((double)c / groupSize);
            result += groupsNeeded * groupSize;
        }
        return result;
    }
};

