class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {
        int n = a.size() ;
        vector<int> ans(n) ;
        int c = 0 ;
        unordered_map<int,int> mp ;
        for ( int i = 0 ; i < n ; i++ ) {
            mp[a[i]]++ ;
            if ( mp[a[i]] == 2 ) c++ ;

            mp[b[i]]++ ;
            if ( mp[b[i]] == 2 ) c++ ;

            ans[i] = c ;
        }
        return ans ;
    }
};