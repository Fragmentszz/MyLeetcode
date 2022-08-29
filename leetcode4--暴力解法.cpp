class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() == 0)   nums2 = nums1;
        auto ptr1 = nums1.begin(), ptr2 = nums2.begin();
        int size1 = nums2.size();
        while (ptr1 < nums1.end())
        {
            while ( size1 > 0 &&  *ptr2 < *ptr1 )
            {
                ptr2++;
                size1--;
            }
            if (!size1)
            {
                for (; ptr1 != nums1.end(); ptr1++)  nums2.push_back(*ptr1); 
                break;
            }
            else
                ptr2 = nums2.insert(ptr2, *ptr1);
            ptr1++;
            size1++;
        }
        int size = nums2.size();
        if (size % 2)
        {
            return  (double)*(size / 2 + nums2.begin());
        }
        else
            return   (*(size / 2 + nums2.begin()) + *(size / 2 + nums2.begin() - 1)) / 2.0;
    }
};
