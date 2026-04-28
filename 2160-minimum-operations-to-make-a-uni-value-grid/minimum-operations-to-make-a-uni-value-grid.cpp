class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> a ;

        for ( int i = 0 ; i < grid.size() ; i++ ) {
            for ( int j = 0 ; j < grid[i].size() ; j++ ) {
                a.push_back(grid[i][j]) ;
            }
        }

        int r = a[0] % x ;

        for ( int it : a ) {
            if ( it % x != r ) return -1 ;
        }

        sort ( a.begin() , a.end()) ;
        int m = a[a.size() / 2] ;
        
        int ans = 0 ;
        for ( int num : a ) {
            ans += abs(num - m) / x ;
        }

        return ans ;
    }
};