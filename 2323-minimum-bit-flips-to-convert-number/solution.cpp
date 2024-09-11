class Solution {
public:
    int minBitFlips(int start, int end) {
        vector<int> binary1;
        vector<int> binary2;
        if(start==0){
            binary1.push_back(0);
        }   
        if(end==0){
            binary2.push_back(0);
        }
        while(start>0){
            binary1.push_back(start%2);
            start/=2;
        }
        while(end>0){
            binary2.push_back(end%2);
            end/=2;
        }
        reverse(binary1.begin(),binary1.end());
        reverse(binary2.begin(),binary2.end());
        if(binary1==binary2){
            return 0;
        }
        int count=0;
        int n1=binary1.size();
        int n2=binary2.size();
        if(n1<n2){
            binary1.insert(binary1.begin(),n2-n1,0);
        }
        else if(n2<n1){
            binary2.insert(binary2.begin(),n1-n2,0);
        }
        for(int i=0;i<binary1.size();i++){
            if(binary1[i]!=binary2[i]){
                count++;
            }
        }
        return count;        
    }
};
