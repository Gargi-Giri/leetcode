class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), current_count =1, result = 0;
        /*
        1. loop upto n + k - 2(because it is circular array)
        2. check condition is if not equal current_count ++,
           else adjust. are equal, so reset the current_count.
        3. if the current_count value reach to k. means if found a group.

        */
        for(int i=0;i<n+k-2;++i){

            if(colors[i%n]!=colors[(i+1)%n]){
                current_count++;
            }else{
                current_count =1;
            }
            result += (current_count>=k);
        }
    return result;
    }
};
