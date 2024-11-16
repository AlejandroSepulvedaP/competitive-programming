//Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       vector<int> mV;
       int i1 = 0, i2 = 0;

       while(i1 < nums1.size() && i2 < nums2.size()){
            if(nums1[i1] > nums2[i2]) mV.push_back(nums2[i2++]);
            else mV.push_back(nums1[i1++]);
       }

       while(i1 < nums1.size()) mV.push_back(nums1[i1++]); 
       while(i2 < nums2.size()) mV.push_back(nums2[i2++]);

       int size = mV.size();

       if(size%2 == 0) return (mV[size/2] + mV[size/2-1])/2.0;
       else return mV[size / 2];
    }
};
