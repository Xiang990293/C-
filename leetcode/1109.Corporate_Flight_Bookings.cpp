class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n+2, 0);

        for (vector<int> &i : bookings) {
            int first = i[0];
            int last = i[1];
            int difference = i[2];

            diff[first] += difference;
            if (last < n) diff[last+1] -= difference;
        }

        int sum = 0;
        vector<int> pref_sum;
        for (int i = 1; i <= n; i++) {
            sum += diff[i];
            pref_sum.push_back(sum);
        }

        return pref_sum;
    }
};