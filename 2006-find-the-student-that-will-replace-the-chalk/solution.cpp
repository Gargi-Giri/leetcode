class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long total=0;
        for(int c=0;c<n;c++){
            total+=chalk[c];
        }
        k=k%total;
        for(int i=0;i<n;i++){
            if(k<chalk[i]){               
                return i;
            }
            k=k-chalk[i];
        }
        return -1;
    }    
};
