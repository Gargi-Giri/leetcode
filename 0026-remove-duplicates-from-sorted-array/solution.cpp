class Solution {
    // int swap(int a,int b){
    //     int temp;
    //     temp=a;
    //     a=b;
    //     b=temp;
    // }
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        //int count=0;
        int j=0;
        for(int i=0;i<n;i++){
            if(i!=j&&nums[i]!=nums[j]){
                j++;
                nums[j]=nums[i];
            
            }
        }
        return j+1;
    }
};
