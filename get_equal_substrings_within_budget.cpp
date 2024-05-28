class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> dp(s.length());
        for(int i = 0; i < s.length(); i++){
            dp[i] = abs(s[i] - t[i]);
        }
        int start = 0, end = 0, sum = 0, maxLength = 0;
        while(end < s.length()){
            sum += dp[end];
            while(sum > maxCost){
                sum -= dp[start];
                start++;
            }
            maxLength = max(maxLength, end - start + 1);
            end++;
        }
        return maxLength;
    }
};