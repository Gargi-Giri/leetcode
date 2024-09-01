class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxC=candies[0];
        int i;
        for(i=1;i<candies.size();i++){
            if(candies[i]>maxC){
                maxC=candies[i];
            }
        }
        vector<bool> ans;
        for(i=0;i<candies.size();i++){
            if(candies[i]+extraCandies<maxC){
                ans.push_back(0);
            }
            else{
                ans.push_back(1);
            }
        }
        return ans;
    }
};
