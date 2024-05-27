class Solution {
public:
    int specialArray(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end()); // Sort once at the beginning

        for(int x = 0; x <= nums.size(); x++) {
            int count = 0;
            for(int num : nums) {
                if(num >= x) count++;
            }
            if(count == x) return x;
        }
        return -1;
    }
};