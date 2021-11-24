/*
Runtime: 20 ms, faster than 95.57% of C++ online submissions for Median of Two Sorted Arrays.
Memory Usage: 89.4 MB, less than 59.43% of C++ online submissions for Median of Two Sorted Arrays.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        double ans = 0.0;
        
        if ( 0 == nums1.size() && 0 == nums2.size() ) return ans;
        
        const bool parity = ( 0 == (nums1.size() + nums2.size()) % 2 ) ? false:true;
        const int target_index = ( nums1.size() + nums2.size() ) / 2;
        
        if ( 0 == nums1.size() )
        {
            if ( parity )
            {
                return (double)nums2[target_index];
            }
            else
            {
                return ( (double)nums2[target_index] + (double)nums2[target_index-1] ) / 2.0;
            }
        }
        
        if ( 0 == nums2.size() )
        {
            if ( parity )
            {
                return (double)nums1[target_index];
            }
            else
            {
                return ( (double)nums1[target_index] + (double)nums1[target_index-1] ) / 2.0;
            }
        }
        
        int i = 0;
        int j = 0;
        int index = 0;

        if ( parity )
        {
            while ( index <= target_index )
            {
                if ( i < nums1.size() && j < nums2.size() )
                {
                    if ( nums1[i] <= nums2[j] )
                    {
                        ans = (double)nums1[i];
                        i++;
                    }
                    else
                    {
                        ans = (double)nums2[j];
                        j++;
                    }
                }
                else if ( i < nums1.size() && j >= nums2.size() )
                {
                    ans = (double)nums1[i];
                    i++;
                }
                else if ( i >= nums1.size() && j < nums2.size() )
                {
                    ans = (double)nums2[j];
                    j++;
                }
                else break;
                index++;
            }            
        }
        else
        {
            while ( index < target_index )
            {
                if ( i < nums1.size() && j < nums2.size() )
                {
                    if ( nums1[i] <= nums2[j] )
                    {
                        ans = (double)nums1[i];
                        i++;
                    }
                    else
                    {
                        ans = (double)nums2[j];
                        j++;
                    }
                }
                else if ( i < nums1.size() && j >= nums2.size() )
                {
                    ans = (double)nums1[i];
                    i++;
                }
                else if ( i >= nums1.size() && j < nums2.size() )
                {
                    ans = (double)nums2[j];
                    j++;
                }
                else break;
                index++;
            }
            
            if ( i < nums1.size() && j < nums2.size() )
            {
                if ( nums1[i] <= nums2[j] )
                {
                    ans += (double)nums1[i];
                }
                else
                {
                    ans += (double)nums2[j];
                }
            }
            else if ( i < nums1.size() && j >= nums2.size() )
            {
                ans += (double)nums1[i];
            }
            else if ( i >= nums1.size() && j < nums2.size() )
            {
                ans += (double)nums2[j];
            }            
            
            ans = ans / 2.0;            
        }
        
        return ans;
        
    }
};
