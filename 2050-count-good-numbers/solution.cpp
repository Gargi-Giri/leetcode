class Solution {
     const int mod= 1e9+7;
    private:
    long long pow(long long  x, long long n){
       long long ans = 1;
        if(n == 0) return 1;
        while(n){
         if(n%2) {
            ans = (x * ans) % mod;
            n = n-1;
        }else{
            x = (x * x )% mod;
            n = n /2;
        }
        }
return ans;
        
    }
public:
    int countGoodNumbers(long long n) {
         long long even_p = (n + 1) / 2;
        long long odd_p = n / 2;
        
        long long first = pow(5, even_p);
        long long second = pow(4, odd_p);
        
        return (first * second) % mod;
    }
};
