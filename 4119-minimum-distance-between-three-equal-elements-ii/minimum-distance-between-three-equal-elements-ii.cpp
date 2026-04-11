class Solution {
public:
    int minimumDistance(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,vector<int>> mp ;

        for ( int i = 0 ; i < n ; i++ ) {
            mp[a[i]].push_back(i) ;
        }

        int ans = INT_MAX ;
        for ( auto p : mp ) {
            auto v = p.second ;
            if ( v.size() < 3 ) continue ;

            for ( int i = 2 ; i < v.size() ; i++ ) {
                int curr = 2 * ( v[i] - v[i - 2] ) ;
                ans = min ( ans , curr ) ;
            }
        }

        return ans == INT_MAX ? -1 : ans ;
    }
};