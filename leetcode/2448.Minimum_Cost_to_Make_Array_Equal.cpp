class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = *min_element(nums.begin(), nums.end());
        long long right = *max_element(nums.begin(), nums.end());

        long long lcost = getCost(nums, cost, left + (right - left)/3);
        long long rcost = getCost(nums, cost, right - (right - left)/3);

        while (abs(left - right) > 2) {
            if (lcost < rcost) {
                right -= (right - left)/3;
            } else {
                left += (right - left)/3;
            }
            rcost = getCost(nums, cost, right - (right - left)/3);
            lcost = getCost(nums, cost, left + (right - left)/3);
        }

        long long min = LLONG_MAX;
        for (long long i : {left, left+1, right}) {
            long long result = getCost(nums, cost, i);
            if (min > result) min = result;
        }

        return min;
    }

    long long getCost(vector<int> &nums, vector<int> &cost, long long target) {
        long long sum = 0;
        for (size_t i = 0; i < nums.size(); ++i) {
            sum += cost[i] * abs(nums[i] - target);
        }

        return sum;
    }
};
