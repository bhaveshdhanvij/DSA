class Solution {
public:
    int helper(string s) {
        unordered_map<char,int> mp ;
        char m = 'z' ;
        for ( char c : s ) {
            mp[c]++ ;
            if ( c < m ) {
                m = c ;
            }
        }

        return mp[m] ;
    }
    vector<int> numSmallerByFrequency(vector<string>& q, vector<string>& w) {
        int n = q.size() , m = w.size() ;
        vector<int> a(n) , b(m) ;

        for ( int i = 0 ; i < n ; i++ ) a[i] = helper(q[i]) ;
        for ( int i = 0 ; i < m ; i++ ) b[i] =  helper(w[i]) ;

        vector<int> ans(n) ;
        for ( int i = 0 ; i < n ; i++ ) {
            int c = 0 ;
            for ( int j = 0 ; j < m ; j++ ) {
                if ( a[i] < b[j] ) c++ ;
            }

            ans[i] = c ;
        }

        return ans ;
    }
};