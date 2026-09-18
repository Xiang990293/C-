#include<vector>
#include<unordered_map>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;

inline void writeInt(int x) {
    if (x < 0) {
        putchar_unlocked('-');
        x = -x;
    }
    if (x == 0) {
        putchar_unlocked('0');
        return;
    }
    char buf[20];
    int idx = 0;
    while (x > 0) {
        buf[idx++] = (x % 10) + '0';
        x /= 10;
    }
    while (idx--) {
        putchar_unlocked(buf[idx]);
    }
}

bool has_sol = false;

bool helper(vector<int> &nums, int pos, int sum, vector<bool> &uses, int target) {
	if (sum > target) return false;
	if (sum == target) {
		has_sol = true;
		for (int i = 0; i < pos; i++) {
			if (!uses[i]) continue;
			writeInt(nums[i]);
        	putchar_unlocked(' ');
		}
		putchar_unlocked('\n');
		return true;
	}
	if (pos == nums.size()) {
		return true;
	}

	uses[pos] = true;
	if (helper(nums, pos+1, sum+nums[pos], uses, target))
		uses[pos] = false;
		helper(nums, pos+1, sum, uses, target);

	return true;
}

int main(){
	int n, tar;
	scanf("%d %d", &n, &tar);
	vector<int> nums(n, 0);
	vector<bool> uses(n, 0);

	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}

	sort(nums.begin(), nums.end(), [](int a, int b) {
		return a < b;
	});

	helper(nums, 0, 0, uses, tar);

	if (!has_sol) printf("-1");
	
	return 0;
}

// similar to leetcode 560
// BUT DIFFERENT!!!