class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<int> pq(nums.begin(), nums.end());
        int total = accumulate(nums.begin(), nums.end(), 0);
        int currentSum = total;
        int operations = 0;
        while (currentSum > total / 2) {
            int top = pq.top();
            pq.pop();
            currentSum -= top / 2;
            pq.push(top / 2);
            operations++;
        }
        return operations;
    }
};