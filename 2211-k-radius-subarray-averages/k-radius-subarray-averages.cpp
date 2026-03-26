class Solution {
public:
    vector<int> getAverages(vector<int>& a, int k) {
        if ( k == 0 ) return a ;
        int n = a.size() ;
        vector<long long> pre(n , 0) ;

        pre[0] = a[0] ;
        for ( int i = 1 ; i < n ; i++ ) {
            pre[i] = pre[i - 1] + a[i] ;
        }

        vector<int> ans ;
        for ( int i = 0 ; i < n ; i++ ) {
            int x = i - k ;
            int y = i + k ;
            if ( x >= 0 && y < n ) {
                long long t = pre[y] ;
                long long r = x == 0 ? 0 : pre[x - 1] ;
                long long avg = ( t - r ) / (2 * k + 1) ;
                ans.push_back((int)avg) ; 
            }else {
                ans.push_back(-1) ;
            }
        }

        return ans ;
    }
};