class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {
        int n = a.size() ;
        unordered_map<int,vector<int>> mp ;

        for ( int i = 0 ; i < n ; i++ ) {
            int gp = a[i] ;
            mp[gp].push_back(i) ;
        }

        vector<vector<int>> ans ;
        for ( auto p : mp ) {
            auto b = p.second ;
            int n = p.first ;
            vector<int> t ;
            for ( int x : b ) {
                t.push_back(x) ;
                if ( t.size() == n ) {
                    ans.push_back(t) ;
                    t.clear() ;
                }
            }
        }

        return ans ;
    }
};