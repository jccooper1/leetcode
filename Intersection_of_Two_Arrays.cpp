#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> countMap;
        for (int i = 0; i < nums1.size(); i++) {
            countMap[nums1[i]]++;
        }
        
        vector<int> result;
        for (int i = 0; i < nums2.size(); i++) {
            if (countMap[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                countMap[nums2[i]]--;
            }
        }
        
        return result;
    }
};


int main() {
    Solution solution;

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> result = solution.intersect(nums1, nums2);

    // Expected output: 2 2
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    nums2 = {4,9,5};
    nums1 = {9,4,9,8,4};
    result = solution.intersect(nums1, nums2);

    // Expected output: 4 9 or 9 4
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}