#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
	vector<int> prefix_sum = {0};

	int sum = 0;
	int counter = 0;
	unordered_map<int, int> prefix_counts;
	prefix_counts[0] = 1;
	for (int &i : nums) {
		sum += i;

		if (prefix_counts.find(sum - k) != prefix_counts.end()) counter+=prefix_counts[sum-k];

		prefix_sum.push_back(sum);
		prefix_counts[sum]++;
	}

	return counter;
}

int main(){
	int num_of_num;
	int goal;
	int nums[30];
	
	
	
	return 0;
}

// similar to leetcode 560
// BUT DIFFERENT!!!

// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         vector<int> prefix_sum = {0};

//         int sum = 0;
//         int counter = 0;
//         std::unordered_map<int, int> prefix_counts;
//         prefix_counts[0] = 1;
//         for (int &i : nums) {
//             sum += i;

//             if (prefix_counts.find(sum - k) != prefix_counts.end()) counter+=prefix_counts[sum-k];

//             prefix_sum.push_back(sum);
//             prefix_counts[sum]++;
//         }

//         return counter;
//     }
// };