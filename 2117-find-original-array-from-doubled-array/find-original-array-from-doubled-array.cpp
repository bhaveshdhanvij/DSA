class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n = a.size() ;

        if ( n % 2 ) return {} ;
        vector<int> ans ;

        unordered_map<int,int> mp ;
        for ( int x : a ) mp[x]++ ;

        sort ( a.begin() , a.end() ) ;

        for ( int i = 0 ; i < n ; i++ ) {
            if ( !mp.count(a[i]) ) continue ;

            int curr = a[i] ;
            int d = 2 * a[i] ;
            
            if ( !mp.count(d) ) return {} ;
            ans.push_back(curr) ;

            --mp[curr] ;
            --mp[d] ;
            
            if ( mp[curr] == 0 ) mp.erase(curr) ;
            if ( mp[d] == 0 ) mp.erase(d) ;
        }

        return ans ;
    }
};