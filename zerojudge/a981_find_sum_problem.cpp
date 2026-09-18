#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

inline void writeStr(const string& s) {
    for (char c : s) {
        putchar_unlocked(c);
    }
}

bool has_sol = false;

void helper(vector<int> &nums, int pos, int sum, string result, int target) {
	if (sum > target) return;
	if (sum == target) {
		has_sol = true;
		writeStr(result + "\n");
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
	int n, tar;
	scanf("%d %d", &n, &tar);
	vector<int> nums(n, 0);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
	});

	helper(nums, 0, 0, "", tar);

	if (!has_sol) printf("-1");
	
	return 0;
}

// similar to leetcode 560
// BUT DIFFERENT!!!