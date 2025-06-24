class Solution {
    public:
        vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
                int n=nums.size();
                        vector<int>ans;

                                for(int j=0;j<n;j++){
                                            if(nums[j]==key){
                                                            int start=max(j-k,0);
                                                                            int end=min(j+k,n-1);

                                                                                            if(!ans.empty() && ans.back()>=start){
                                                                                                                start=ans.back()+1;
                                                                                                                                }

                                                                                                                                                for(int i=start;i<=end;i++){
                                                                                                                                                                    ans.push_back(i);
                                                                                                                                                                                    }
                                                                                                                                                                                                }
                                                                                                                                                                                                        }
                                                                                                                                                                                                                return ans;
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                    };

