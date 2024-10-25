class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Step 1: Sort the folder list lexicographically
        sort(folder.begin(), folder.end());
        
        // Step 2: Create a result vector to store the final list of folders
        vector<string> res;
        
        // Step 3: Iterate through the sorted folder list
        for (const string& f : folder) {
            // Step 4: Check if the current folder is not a subfolder of the last added folder
            if (res.empty() || f.find(res.back() + '/') != 0) {
                // If it's not a subfolder, add it to the result
                res.push_back(f);
            }
        }
        
        // Step 5: Return the result
        return res;
    }
};

