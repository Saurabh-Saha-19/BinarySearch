class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int N = (n1+n2+1)/2;

        int low = 0;
        int high = n1;

        while(low <= high) {
            int mid1 = (low+high)/2;
            int mid2 = N-mid1;

            int l1 = mid1-1 >= 0 ? nums1[mid1-1]:INT_MIN;
            int l2 = mid2-1 >= 0 ? nums2[mid2-1]:INT_MIN;

            int r1 = (mid1 >= n1) ? INT_MAX: nums1[mid1];
            int r2 = (mid2 >= n2) ? INT_MAX: nums2[mid2];

            if(l1 <= r2 and l2 <= r1) {
                if((n1+n1) % 2 == 0) {
                    return ((double)(max(l1,l2)+ min(r1,r2)))/2.0;
                }
                else  {
                    return (double)(max(l1, l2));
                }
                    
            } 
            else if(l2 > r1) {
                low = mid1+1;
            }
            else {
                high = mid1-1;
            }
        }
        return 0.0;

    }
};