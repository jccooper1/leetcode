class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> prefix_sum(nums.size() + 1, 0);
        unordered_map<int, int> count;
        count[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            prefix_sum[i + 1] = prefix_sum[i] + nums[i];
            int mod = (prefix_sum[i + 1] % k + k) % k;
            ans += count[mod];
            count[mod]++;
        }
        return ans;
    }
};