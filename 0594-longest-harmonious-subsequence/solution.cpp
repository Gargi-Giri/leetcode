class Solution 
{
public:
    int findLHS(vector<int>& nums) 
        {
                // Step 1: Sort the array
                        sort(nums.begin(), nums.end());

                                int left = 0;
                                        int maxLen = 0;

                                                // Step 3: Iterate using right pointer
                                                        for (int right = 0; right < nums.size(); ++right) 
                                                                {
                                                                            // Step 4: Shrink window if difference > 1
                                                                                        while (nums[right] - nums[left] > 1) 
                                                                                                    {
                                                                                                                    left++;
                                                                                                                                }

                                                                                                                                            // Step 5: Check if difference == 1
                                                                                                                                                        if (nums[right] - nums[left] == 1) 
                                                                                                                                                                    {
                                                                                                                                                                                    maxLen = max(maxLen, right - left + 1);
                                                                                                                                                                                                }
                                                                                                                                                                                                        }

                                                                                                                                                                                                                // Step 6: Return result
                                                                                                                                                                                                                        return maxLen;
                                                                                                                                                                                                                            }
                                                                                                                                                                                                                            };
