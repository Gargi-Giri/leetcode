#include <vector>
#include <set>

class Solution {
public:
    int totalNumbers(std::vector<int>& digits) {
        std::set<int> uniqueNumbers;
        int size = digits.size();
        
        for (int i = 0; i < size; i++) {
            if (digits[i] == 0) continue;
            for (int j = 0; j < size; j++) {
                if (j == i) continue;
                for (int k = 0; k < size; k++) {
                    if (k == i || k == j) continue;
                    if (digits[k] % 2 == 0) {
                        uniqueNumbers.insert(digits[i] * 100 + digits[j] * 10 + digits[k]);
                    }
                }
            }
        }
        
        return uniqueNumbers.size();
    }
};

