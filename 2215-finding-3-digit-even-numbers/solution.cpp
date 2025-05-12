class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> result;
        int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }
        for (int num = 100; num <= 999; num += 2) {
        int hundreds = num / 100;
        int tens = (num / 10) % 10;
        int ones = num % 10;

        // Count digits used in this number
        int tempFreq[10] = {0};
        tempFreq[hundreds]++;
        tempFreq[tens]++;
        tempFreq[ones]++;

        bool isValid = true;
        for (int i = 0; i < 10; i++) {
            if (tempFreq[i] > freq[i]) {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            result.push_back(num);
        }
        }
        return result;
    }
};
