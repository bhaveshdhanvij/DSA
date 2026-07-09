class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& a, int maxx, vector<vector<int>>& queries) {
        vector<int> mp(n) ;
        int k = 0 ;

        mp[0] = k ;
        
        for ( int i = 1 ; i < a.size() ; i++ ) {
            if ( a[i] - a[i - 1] > maxx ) {
                k++ ;
            }
            mp[i] = k ; 
        }

        vector<bool> ans ;
        for ( auto x : queries ) {
            ans.push_back(mp[x[0]] == mp[x[1]]) ;
        }

        return ans ;
    }
};