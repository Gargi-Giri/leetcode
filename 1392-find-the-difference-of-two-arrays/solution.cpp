class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> answer1(nums1.begin(),nums1.end());
        unordered_set<int> answer2(nums2.begin(),nums2.end());
        vector<int> result1;
        vector<int> result2;
        for(int num : answer1){
            if(answer2.find(num)==answer2.end()){
                result1.push_back(num);
            }
        }
        for(int num : answer2){
            if(answer1.find(num)==answer1.end()){
                result2.push_back(num);
            }
        }
        return {result1,result2};
    }
};
