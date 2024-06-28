class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> freq(n, 0);
        
        // Count frequency of each city
        for (const auto& road : roads) {
            freq[road[0]]++;
            freq[road[1]]++;
        }
        
        // Sort frequencies
        sort(freq.begin(), freq.end());
        
        long long ans = 0;
        // Calculate importance
        for (int i = 0; i < n; i++) {
            ans += freq[i] * (i + 1LL);
        }
        return ans;
    }
};
