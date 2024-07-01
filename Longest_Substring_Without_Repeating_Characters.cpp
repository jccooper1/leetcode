class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int max_val=0;
        int left=0;
        for(int right=0;right<s.length();right++){
            if(mp.find(s[right])!=mp.end() and mp[s[right]]>=left) 
                left=mp[s[right]]+1;
            mp[s[right]]=right;
            max_val=max(max_val,right-left+1);
        }
        return max_val;
    }
};