class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);  // Convert the number to a string to manipulate digits
    vector<int> last(10, -1);        // Store the last occurrence of each digit (0-9)
    
    // Fill the last occurrence of each digit
    for (int i = 0; i < numStr.size(); ++i) {
        last[numStr[i] - '0'] = i;
    }
    
    // Traverse the number and find the first place to swap
    for (int i = 0; i < numStr.size(); ++i) {
        // Check if there is a larger digit later in the number
        for (int d = 9; d > numStr[i] - '0'; --d) {
            if (last[d] > i) {  // If a larger digit is found later
                // Swap the digits
                swap(numStr[i], numStr[last[d]]);
                // Return the result as an integer
                return stoi(numStr);
            }
        }
    }
    
    // If no swap is needed, return the original number
    return num;
    }
};
