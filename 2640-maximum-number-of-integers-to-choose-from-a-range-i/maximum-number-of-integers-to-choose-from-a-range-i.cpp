class Solution {
public:
    int maxCount(vector<int>& b, int n, int maxSum) {
        unordered_set<int> s ;

        for ( int x : b ) {
            if ( x <= n ) s.insert(x) ;
        }

        int curr = 0 ;
        int ans = 0 ;
        for ( int i = 1 ; i <= n ; i++ ) {
            if ( s.count(i) ) continue ;
            curr += i ;
            if ( curr > maxSum ) break ;
            ans++ ;
        }

        return ans ;

    }
};