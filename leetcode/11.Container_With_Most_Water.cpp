class Solution {
public:
    int min(int a, int b) {
        if (a < b) return a;
        return b;
    }

    int max(int a, int b) {
        if (a < b) return b;
        return a;
    }

    int maxArea(vector<int>& height) {
        int *l = &*height.begin(), *r = &*height.end() - 1;

        int m = min(*l, *r) * int(r-l);
        while(l != r) {
            if (*l < *r) l++;
            else r--;

            m = max(min(*l, *r) * int(r-l), m);
        }

        return m;
    }
};
