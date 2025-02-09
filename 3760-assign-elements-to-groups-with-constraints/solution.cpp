class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int maxValue = 100000; // Given constraint
        vector<int> assigned(groups.size(), -1);
        
        // Store the smallest index for each unique element
        vector<int> elementIndex(maxValue + 1, -1);
        for (int j = 0; j < elements.size(); j++) {
            if (elementIndex[elements[j]] == -1)
                elementIndex[elements[j]] = j; // Store the first occurrence (smallest index)
        }

        // Process each group efficiently
        for (int i = 0; i < groups.size(); i++) {
            int bestIdx = -1;
            
            // Find divisors of groups[i] (efficiently)
            for (int d = 1; d * d <= groups[i]; d++) {
                if (groups[i] % d == 0) {
                    // Check both divisors (d and groups[i] / d)
                    if (elementIndex[d] != -1 && (bestIdx == -1 || elementIndex[d] < bestIdx))
                        bestIdx = elementIndex[d];
                    if (elementIndex[groups[i] / d] != -1 && (bestIdx == -1 || elementIndex[groups[i] / d] < bestIdx))
                        bestIdx = elementIndex[groups[i] / d];
                }
            }

            assigned[i] = bestIdx;
        }

        return assigned;
    }
};

