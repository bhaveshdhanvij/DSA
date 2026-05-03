class Solution {
public:
    vector<int> countOppositeParity(vector<int>& a) {
        int n = a.size() ;
        vector<pair<int,int>> p(n) ;

        p[n - 1] = {0 , 0} ;

        int even = 0 , odd = 0 ;

        for ( int i = n - 2 ; i >= 0 ; i-- ) {
            if ( a[i + 1] % 2 == 0 ) even++ ;
            else odd++ ;

            p[i] = {even , odd} ;
        }

        vector<int> ans(n) ;
        ans[n - 1] = 0 ;

        for ( int i = 0 ; i < n - 1 ; i++ ) {
            if ( a[i] % 2 == 0 ) {
                ans[i] = p[i].second ;
            }else {
                ans[i] = p[i].first ;
            }
        }

        return ans ;
    }
};