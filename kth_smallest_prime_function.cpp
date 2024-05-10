class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<int> ans;
        map<double, pair<int, int>> mp;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                mp[(double)arr[i] / arr[j]] = {arr[i], arr[j]};
            }
        }
        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if (count == k - 1) {
                ans.push_back(it->second.first);
                ans.push_back(it->second.second);
                break;
            }
            count++;
        }
        return ans;
    }
};