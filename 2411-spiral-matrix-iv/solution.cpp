
// Assuming ListNode is already defined elsewhere
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> matrix(m, vector<int>(n, -1));
        vector<int> values;
        
        // Step 1: Extract values from the linked list
        ListNode* current = head;
        while (current) {
            values.push_back(current->val);
            current = current->next;
        }
        
        // Step 2: Spiral fill the matrix
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int index = 0;
        
        while (top <= bottom && left <= right) {
            // Fill the top row
            for (int i = left; i <= right && index < values.size(); ++i) {
                matrix[top][i] = values[index++];
            }
            ++top;
            
            // Fill the right column
            for (int i = top; i <= bottom && index < values.size(); ++i) {
                matrix[i][right] = values[index++];
            }
            --right;
            
            // Fill the bottom row
            for (int i = right; i >= left && index < values.size(); --i) {
                matrix[bottom][i] = values[index++];
            }
            --bottom;
            
            // Fill the left column
            for (int i = bottom; i >= top && index < values.size(); --i) {
                matrix[i][left] = values[index++];
            }
            ++left;
        }
        
        return matrix;
    }
};

