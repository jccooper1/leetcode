class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result={{}};
        for(int i=0;i<nums.size();i++){
            int n=result.size();
            for(int j=0;j<n;j++){
                vector<int> temp=result[j];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
        }

    }
};