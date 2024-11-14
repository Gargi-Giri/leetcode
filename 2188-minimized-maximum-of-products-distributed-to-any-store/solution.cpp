class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = INT_MIN, res = 0;
        
        // Find the maximum quantity in the quantities vector to set the upper bound
        for(int x: quantities) 
            if(high < x) 
                high = x;
        
        // Perform binary search to find the minimized maximum value of products per store
        while(low <= high) {
            int mid = low + (high - low) / 2;  // Midpoint to test as a possible max value
            int sum = 0;  // Sum represents the total stores needed if max products per store is `mid`
            
            // Calculate total number of stores required if max products per store is `mid`
            for(int x: quantities) 
                sum += (ceil((float)x / float(mid)));  // Calculate number of stores needed for each product
            
            // Check if this midpoint allows for distribution within the given store limit `n`
            if(sum <= n) {  
                res = mid;   // Update the result with current valid mid
                high = mid - 1;  // Try for a smaller maximum by reducing the upper bound
            } else {
                low = mid + 1;  // Increase the lower bound if more stores are needed than available
            }
        }
        
        return res;
    }
};
