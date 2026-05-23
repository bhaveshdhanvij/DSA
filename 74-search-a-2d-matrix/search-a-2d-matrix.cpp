class Solution {
public:
    // Cisco
    // Uber
    // Visa
    // Amazon
    // Goldman Sachs
    // Meta
    // Apple
    bool search ( vector<int> nums , int t ) {
        int n = nums.size() ;
        int l = 0 , r = n - 1 ;
        while ( l <= r ) {
            int mid = l + (r - l) / 2 ;
            if ( nums[mid] == t ) {
                return true ;
            }else if ( nums[mid] < t ) {
                l = mid + 1 ;
            }else {
                r = mid - 1 ;
            }
        }
        return false ;
    }
    bool searchMatrix(vector<vector<int>>& a, int target) {
        // Approach 1 : traverse the entire matrix and check whether it is present or not 
        // Approach 2 : traverse via each row and check if target exists in it , if yes binary search on it 

        int n = a.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( target >= a[i].front() && target <= a[i].back() ) {
                return search(a[i] , target) ;
            }
        }
        return false ;
    }
};