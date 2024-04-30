class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<int> count(1024, 0);
        count[0] = 1;
        int mask = 0;
        long long ans = 0;
        for (char c : word) {
            mask ^= 1 << (c - 'a');
            for (int i = 0; i < 10; ++i) {
                ans += count[mask ^ (1 << i)];//this tests all the substring 
            }
            ans += count[mask];
            ++count[mask];
        }
        return ans;
    }
};