class Solution {
private:
    vector<int> calcTrib(int n){
        vector<int> T(max(n+1,3));
        T[0]=0;
        T[1]=1;
        T[2]=1;
        if(n>=0){
            for(int i=3;i<=n;i++){
                T[i]=T[i-1]+T[i-2]+T[i-3];
            }
        }
        return T;
    }
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1||n==2) return 1;
        vector<int> out=calcTrib(n);
        return out[n];
    }
};
