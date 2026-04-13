class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n = a.size() , m = a[0].size() ;
        // Approach 1 : traverse the entire matrix and check if the target is present or not 
        // Approach 2 : for each row check if target lies in that range , if yes binary search on that row since it's sorted 
        // Optimal Approach : Imagine the 2-d array into 1-d array and use manipulation technique of indexing in terms of row and column no. of the matrix 
        // TC : O(log(N * M)) , SC : O(1) 

        int l = 0 , h = n * m - 1 ;
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