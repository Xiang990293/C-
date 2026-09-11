class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int tar = m+n;

        while (m != 0 and n != 0) {
            if (nums1[m-1] > nums2[n-1]) nums1[--tar] = nums1[--m];
            else nums1[--tar] = nums2[--n];
        }

        if (n == 0) return;
        if (m == 0)
            for (int i = n; i > 0;)
                nums1[--tar] = nums2[--i];
        
        return;
    }
};
