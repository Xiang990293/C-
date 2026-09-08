class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum = {0};

        int sum = 0;
        int counter = 0;
        std::unordered_map<int, int> prefix_counts;
        prefix_counts[0] = 1;
        for (int &i : nums) {
            sum += i;

            if (prefix_counts.find(sum - k) != prefix_counts.end()) counter+=prefix_counts[sum-k];

            prefix_sum.push_back(sum);
            prefix_counts[sum]++;
        }

        return counter;
    }
};