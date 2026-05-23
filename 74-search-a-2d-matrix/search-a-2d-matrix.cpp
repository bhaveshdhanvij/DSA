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
        // TC : O(N * log(N * M)) , SC : O(1) 

        // int n = a.size() ;
        // for ( int i = 0 ; i < n ; i++ ) {
        //     if ( target >= a[i].front() && target <= a[i].back() ) {
        //         return search(a[i] , target) ;
        //     }
        // }
        // return false ;

        // Optimal Approach : imagine the 2d array as 1d array and use manipulation technique of indexing in terms of row and column no. of matrix 
        // TC : O(log(N * M)) , SC : O(1) 

        int n = a.size() , m = a[0].size() ;
        int l = 0 , h = m * n - 1 ;
        while ( l <= h ) {
            int mid = (l + h) / 2 ;
            
            int row = mid / m ;
            int col = mid % m ;

            if ( a[row][col] == target ) {
                return true ;
            }else if ( a[row][col] < target ) {
                l = mid + 1 ;
            }else {
                h = mid - 1 ;
            }
        }
        return false ;
    }
};