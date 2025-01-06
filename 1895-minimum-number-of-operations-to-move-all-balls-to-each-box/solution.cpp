class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int> A(n,0);
        vector<int> P;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                P.push_back(i);
                A[0]+=i;
            }
        }
        int position=P.size(),L=0,R=position;
        for(int i=1,j=0;i<n;i++){
            if(j<position && i>P[j]){
                L++;
                R--;
                j++;
            }
            A[i]=A[i-1]+L-R;
        }
        return A;
    }
};
