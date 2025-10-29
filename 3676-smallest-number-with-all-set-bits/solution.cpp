class Solution {
public:
    int binaryConvert(int n){
        int binary = 0;
        int place = 1;

        while (n > 0) {
            int rem = n % 2;
            binary += rem * place;
            n /= 2;
            place *= 10;
        }

    return binary;
    }
    bool allOnes(int n) {
        while (n > 0) {
            if (n % 2 == 0) return false;
            n /= 2;
        }
        return true;
    }

    int smallestNumber(int n) {
        int x = n;
        while (!allOnes(x)) {
            x++;
        }
        return x;
    }
    
};
