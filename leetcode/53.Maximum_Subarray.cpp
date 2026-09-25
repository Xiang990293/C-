class Solution {
public:
    int max2(int a, int b) {
        if (a > b) return a;
        return b;
    }

    int max3(int a, int b, int c) {
        int d = max2(a, b);
        if (d > c) return d;
        return c;
    }

    int daq(vector<int>& nums, int* begin, int* end) {
        int len = end - begin;
        if (len == 1) return *begin;
        if (len == 0) return INT_MIN;

        int resl = daq(nums, begin, begin + len / 2);
        int resr = daq(nums, begin + len / 2, end);
        
        int max_mid2left = INT_MIN;
        int sum = 0;
        for (int* i = begin + len / 2 - 1; i >= begin; i--) {
            sum += *i;
            if (sum > max_mid2left) max_mid2left = sum;
        }

        int max_mid2right = INT_MIN;
        sum = 0;
        for (int* i = begin + len / 2; i < end; i++) {
            sum += *i;
            if (sum > max_mid2right) max_mid2right = sum;
        }

        return max3(resl, resr, max_mid2left+max_mid2right);
    }

    int maxSubArray(vector<int>& nums) {
        return daq(nums, &*nums.begin(), &*nums.end());
    }
};
