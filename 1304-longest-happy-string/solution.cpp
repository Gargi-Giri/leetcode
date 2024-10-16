class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
            // Create a vector of pairs with (count, character)
    vector<pair<int, char>> chars = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    string result;
    
    while (true) {
        // Sort the vector in descending order by count
        sort(chars.rbegin(), chars.rend());
        bool added = false;
        
        for (int i = 0; i < 3; ++i) {
            // If the count of the current character is 0, skip it
            if (chars[i].first == 0) {
                continue;
            }
            
            // Check if the last two characters in the result are the same as the current one
            int len = result.length();
            if (len >= 2 && result[len - 1] == chars[i].second && result[len - 2] == chars[i].second) {
                continue; // Skip to avoid three consecutive identical characters
            }
            
            // Append the current character to the result
            result += chars[i].second;
            chars[i].first--; // Decrease the count
            added = true;
            break; // Move on to the next iteration
        }
        
        // If we couldn't add any character, break out of the loop
        if (!added) {
            break;
        }
    }
    
    return result;

    }
};
