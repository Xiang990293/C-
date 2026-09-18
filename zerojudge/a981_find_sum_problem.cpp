#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

void helper(vector<int> &nums, int pos, int sum, string result, int target) {
	if (sum > target) return;
	if (sum == target) {
		cout << result << endl;
		return;
	}
	if (pos == nums.size()) {
		return;
	}

	helper(nums, pos+1, sum+nums[pos], result + to_string(nums[pos]) + " ", target);
	helper(nums, pos+1, sum, result, target);

	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, tar;
	cin >> n >> tar;
	vector<int> nums(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
	});

	helper(nums, 0, 0, "", tar);
	
	return 0;
}

// similar to leetcode 560
// BUT DIFFERENT!!!