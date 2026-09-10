class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[1] < b[1];
        });

        int counter = 0;
        int current_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < current_end) {
                counter++;
            }
            else {
                current_end = intervals[i][1];
            }
        }

        return counter;
    }
};
