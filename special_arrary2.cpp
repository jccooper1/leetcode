class Solution {
public:
    std::vector<bool> isArraySpecial(const std::vector<int>& nums, const std::vector<std::vector<int>>& queries) {
        int n = nums.size();
        std::vector<int> transitionCount(n, 0);

        // Initialize the first element based on the first pair
        if (n > 1) {
            transitionCount[0] = (nums[0] % 2 != nums[1] % 2) ? 1 : 0;
        }

        // Precompute the number of parity transitions
        for (int i = 1; i < n - 1; i++) {
            transitionCount[i] = transitionCount[i - 1] + ((nums[i] % 2 != nums[i + 1] % 2) ? 1 : 0);
        }

        std::vector<bool> ans;
        ans.reserve(queries.size());

        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == end) {
                ans.push_back(true); // Trivially true if the range is a single element
            } else {
                // Check the number of transitions in the range [start, end]
                int expectedTransitions = end - start;
                int actualTransitions = transitionCount[end - 1] - (start > 0 ? transitionCount[start - 1] : 0);
                ans.push_back(expectedTransitions == actualTransitions);
            }
        }

        return ans;
    }
};