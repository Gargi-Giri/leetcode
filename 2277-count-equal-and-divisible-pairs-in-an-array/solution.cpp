class Solution 
{
public:
    int countPairs(vector<int>& nums, int k) 
        {
                int pairs = 0;
                    
                            // Step 1: Iterate over all possible i < j pairs
                                    for(int i = 0; i < nums.size(); i++) 
                                            {
                                                        for(int j = i + 1; j < nums.size(); j++) 
                                                                    {
                                                                                    // Step 2: Check if values are equal
                                                                                                    if(nums[i] == nums[j]) 
                                                                                                                    {
                                                                                                                                        // Step 3: Check if index product divisible by k
                                                                                                                                                            if((i * j) % k == 0) 
                                                                                                                                                                                {
                                                                                                                                                                                                        pairs++;  // Step 4: Count valid pair
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                        
                                                                                                                                                                                                                                                                                return pairs; // Step 5: Return result
                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                    };
