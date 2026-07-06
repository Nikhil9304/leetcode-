1class Solution {
2public:
3    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
4
5        // Always perform Binary Search on the smaller array
6        if (nums1.size() > nums2.size())
7            return findMedianSortedArrays(nums2, nums1);
8
9        int n = nums1.size();
10        int m = nums2.size();
11
12        int low = 0;
13        int high = n;
14
15        while (low <= high) {
16
17            // Partition index in nums1
18            int cut1 = low + (high - low) / 2;
19
20            // Remaining elements required in left half come from nums2
21            int cut2 = (n + m + 1) / 2 - cut1;
22
23            // Last element on left side of nums1
24            // If no element exists, use -infinity
25            int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
26
27            // Last element on left side of nums2
28            int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
29
30            // First element on right side of nums1
31            // If no element exists, use +infinity
32            int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
33
34            // First element on right side of nums2
35            int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];
36
37            // Correct partition found
38            if (left1 <= right2 && left2 <= right1) {
39
40                // Even number of elements
41                if ((n + m) % 2 == 0) {
42                    return (max(left1, left2) + min(right1, right2)) / 2.0;
43                }
44
45                // Odd number of elements
46                return max(left1, left2);
47            }
48
49            // Too many elements taken from nums1
50            else if (left1 > right2) {
51                high = cut1 - 1;
52            }
53
54            // Too few elements taken from nums1
55            else {
56                low = cut1 + 1;
57            }
58        }
59
60        return 0.0; // Never reached for valid input
61    }
62};