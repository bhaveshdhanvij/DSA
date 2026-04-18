class Solution {
public:
    int minimumDeletions(string s, int k) {
        unordered_map<int,int> mp ;
        for ( char c : s ) mp[c]++ ;

        vector<int> a ;
        for ( auto p : mp ) {
            a.push_back(p.second) ;
        }

        int ans = INT_MAX ;
        
        for ( int i = 0 ; i < a.size() ; i++ ) {
            int curr = 0 , x = a[i] ;
            for ( int j = 0 ; j < a.size() ; j++ ) {
                if ( i == j ) continue ;
                int y = a[j] ;
                if ( y < x ) curr += y ;
                else if ( y > x + k ) curr += y - x - k ;
            }
            ans = min ( ans , curr ) ;
        }

        return ans ;
    }
};