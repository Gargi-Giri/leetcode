class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int count = 0;
        int freq[100] = {0};
        int maxCount = 1;
        for (int num : nums) {
            freq[num - 1] = freq[num - 1] + 1;
            if(freq[num - 1] > maxCount){
                maxCount = freq[num - 1];
            } 
        } 
        for(int i =0;i<100;i++){
            if(freq[i] == maxCount){
                count+=maxCount;
            }
        }
        return count;
    }
};
