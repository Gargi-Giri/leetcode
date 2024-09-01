class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int num) {
        int i=0;
        int c=0;
        int size=flowerbed.size();
        if(size==1){
            if(flowerbed[0]==0){
            c++;
            }
        }
        else if (size>=2){
            if(flowerbed[0]==0&&flowerbed[1]==0){
                flowerbed[0]=1;
                c++;
            }
        }
        if(size>=2){
            if(flowerbed[size-1]==0&&flowerbed[size-2]==0){
                flowerbed[size-1]=1;
                c++;
            }
        }
        for(i=1;i<size-1;i++){
            if(flowerbed[i]==0&&flowerbed[i+1]==0&&flowerbed[i-1]==0){
                flowerbed[i]=1;
                c++;
            }
        }
        return c>=num;
    }
};
