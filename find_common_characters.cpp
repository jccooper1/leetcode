class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> mp(26, INT_MAX);
        vector<string> ans;
        for(auto &word : words){
            vector<int> freq(26, 0);
            for(char c : word){
                freq[c - 'a']++;
            }
            for(int i = 0; i < 26; i++){
                mp[i] = min(mp[i], freq[i]);
            }
        }
        for(int i = 0; i < 26; i++){
            while(mp[i]-- > 0) {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};