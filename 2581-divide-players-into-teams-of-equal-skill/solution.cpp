class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        long long mul=0;
        int n=skill.size();
        int l=0,r=n-1;
        if(n%2!=0){
            return -1;
        }
        int sum=skill[0]+skill[n-1];
        while(l<r){
            int s=skill[l]+skill[r];
            mul+=skill[l]*skill[r];
            if(s==sum){
                l++;
                r--;

            }
            else
            {
                return -1;
            }
        }
        return mul;
    }
};
