class Solution {
public:
    bool isBase10Palindrome(long long num){
        string s=to_string(num);
        return s==string(s.rbegin(),s.rend());
    }
    long long baseKToDecimal(const vector<int>& digits, int k){
        long long num=0;
        for(int d: digits){
            num=num*k+d;
        }
        return num;
    }
    void generateBaseKPalindromes(int k, int n, vector<long long>& result){
        for(int length=1;result.size()<n;++length){
            int halfLen=(length+1)/2;
            int start=(length==1)?1:pow(k,halfLen-1);
            int end=pow(k,halfLen);
            for(int half=start;half<end&&result.size()<n;++half){
                vector<int>halfDigit;
                int temp=half;
                while(temp>0){
                    halfDigit.push_back(temp%k);
                    temp/=k;
                }
                reverse(halfDigit.begin(),halfDigit.end());
            
            vector<int>fullDigit=halfDigit;
            int i=(length%2==0)?halfDigit.size()-1:halfDigit.size()-2;
            while(i>=0){
                fullDigit.push_back(halfDigit[i--]);
            }
            long long decimalVal=baseKToDecimal(fullDigit,k);
            if(isBase10Palindrome(decimalVal)){
                result.push_back(decimalVal);
            }
            }
        }
    }
    long long kMirror(int k, int n) {
        vector<long long> result;
        generateBaseKPalindromes(k,n,result);
        long long sum=0;
        for(long long x: result) sum+=x;
        return sum;
    }
};
