class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int total = n + m;
        int mid = total / 2;

        bool isEven = (total % 2 == 0);
        int i = 0, j = 0, count = 0;
        int curr = 0, prev = 0;

        while (count <= mid) {
            prev = curr;

            if (i < n && (j >= m || nums1[i] <= nums2[j])) {
                curr = nums1[i];
                i++;
            } else {
                curr = nums2[j];
                j++;
            }

            count++;
        }

        if (isEven) {
            return (prev + curr) / 2.0;
        } else {
            return curr;
        }
    }
};
