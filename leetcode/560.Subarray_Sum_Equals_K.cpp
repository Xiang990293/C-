class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int> prefix_sum = {0};

        int sum = 0;
        int counter = 0;
        for (int &i : nums) {
            sum += i;

            for (int &j : prefix_sum) {
                if (j == sum - k) counter++;
            }

            prefix_sum.push_back(sum);
        }

        return counter;
    }
};
