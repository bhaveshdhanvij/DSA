class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& vec) {
        int n = vec.size() / 2 ;

        auto flag = [](vector<int>& a , vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]) ;
        };

        sort ( vec.begin() , vec.end() , flag ) ;
        
        int ans = 0 ;

        for ( int i = 0 ; i < n ; i++ ) ans += vec[i][0] ;

        for ( int i = n ; i < 2 * n ; i++ ) ans += vec[i][1] ;

        return ans ;
    }
};