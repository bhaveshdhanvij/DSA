class Solution {
public:
    int garbageCollection(vector<string>& a, vector<int>& t) {
        int n = a.size() ;
        vector<int> p(n , 0) ;
        for ( int i = 1 ; i < n ; i++ ) {
            p[i] = p[i - 1] + t[i - 1] ;
        }

        int ans = 0 ;
        int lastm = 0 , lastp = 0 , lastg = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {
            ans += a[i].size() ;
            
            for ( char c : a[i] ) {
                if ( c == 'M' ) lastm = i ;
                else if ( c == 'P' ) lastp = i ;
                else lastg = i ;
            }
        }

        ans += p[lastm] ;
        ans += p[lastp] ;
        ans += p[lastg] ;

        return ans ;
    }
};