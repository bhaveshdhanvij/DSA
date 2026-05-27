class Solution {
public:
    // Microsoft
    // Oracle
    // Amazon
    // Meta
    // Apple
    // TCS
    bool searchMatrix(vector<vector<int>>& a, int target) {
        // Naive Approach : Search one by one by traversal 
        // TC : O(N * M) , SC : O(1) 

        // Approach 2 : Check range of each row and binary search on it 
        // TC : O(NLog(M)) , SC : O(1) 

        // Optimal Approach : Top Right Technique 
        // TC : O(N + M) , SC : O(1) 

        int n = a.size() , m = a[0].size() ;
        
        int r = 0 , c = m - 1 ;
        while ( r < n && c >= 0 ) {
            if ( a[r][c] == target ) {
                return true ;
            }else if ( a[r][c] < target ) {
                r++ ;
            }else {
                c-- ;
            }
        }
        return false ;
    }
};