class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int ans = INT_MAX ;
        int n = a.size() ;
        vector<int> p(n) , s(n) ;
        p[0] = a[0] ;
        s[n - 1] = a[n - 1] ;
        for ( int i = 1 ; i < n ; i++ ) {
            p[i] = max(p[i - 1] , a[i]) ;
        }
        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            s[i] = min(s[i + 1] , a[i]) ;
        }
        for ( int i = 0 ; i < n ; i++ ) {
            int curr = p[i] - s[i] ;
            if ( curr <= k ) return i;
        }
        return -1 ;
    }
};