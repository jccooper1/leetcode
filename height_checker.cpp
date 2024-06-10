class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>sorted_array;
        sorted_array=heights;
        sort(sorted_array.begin(),sorted_array.end());
        int ans=0;
        for(int i=0;i<heights.size();i++){
            if(heights[i]!=sorted_array[i]) ans++;
        }
        return ans;
    }
};