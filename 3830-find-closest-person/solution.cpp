class Solution {
public:
    int findClosest(int x, int y, int z) {
        int u=0,v=0;
        u=abs(z-x);
        v=abs(z-y);
        if(u<v){
            return 1;
        }
        else if(u>v){
            return 2;
        }
        else{
            return 0;
        }
    }
};
