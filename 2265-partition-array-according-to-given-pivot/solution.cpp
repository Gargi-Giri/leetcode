class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> out1;
        vector<int> out2;
        vector<int> outS;
        vector<int> output;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<pivot){
                out1.push_back(nums[i]);
            }
            else if(nums[i]>pivot){
                out2.push_back(nums[i]);
            }
            else{
                outS.push_back(nums[i]);
            }
        }
        int n1=out1.size();
        int n2=out2.size();
        int n3=outS.size();
        for(int i=0;i<n1;i++){
            output.push_back(out1[i]);
        }
        for(int i=0;i<n3;i++){
            output.push_back(outS[i]);
        }
        //output.push_back(pivot);
        for(int i=0;i<n2;i++){
            output.push_back(out2[i]);
        }

        return output;
    }
};
