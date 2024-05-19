class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        long long sum = 0;
        vector<vector<int>> count(10, vector<int>(10, 0));

        for (int num : nums) {
            int idx = 0;
            while (num > 0) {
                int digit = num % 10;
                for (int i = 0; i < 10; ++i) {
                    if (i != digit) {
                        sum += count[idx][i];
                    }
                }
                count[idx][digit]++;
                num /= 10;
                idx++;
            }
        }

        return sum * 2;
    }
};