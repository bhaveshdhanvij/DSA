class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& a) {
        int n = a.size() ;
        vector<int> ans(n) ;

        vector<pair<int,int>> p ;
        for ( int i = 0 ; i < n ; i++ ) {
            p.push_back({a[i] , i}) ;
        }

        sort ( p.begin() , p.end() ) ;
        int r = 1 ;

        for ( int i = 0 ; i < n ; i++ ) {
            int idx = p[i].second ;
            int x = p[i].first ;
            
            if ( i > 0 && p[i].first == p[i - 1].first ) {
                ans[idx] = ans[p[i - 1].second] ;
            }else {
                ans[idx] = r ;
                r++ ;
            } 
        }

        return ans ;
    }
};