class NumArray {
public:
    vector<int> nums_ref;
    vector<int> range_sum;
    NumArray(vector<int>& nums) {
        nums_ref = nums;
        
        int counter = 0;
        int sum = 0;
        for (const int &i: nums_ref) {
            sum += i;
            range_sum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return this->range_sum[right];
        return this->range_sum[right] - this->range_sum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
