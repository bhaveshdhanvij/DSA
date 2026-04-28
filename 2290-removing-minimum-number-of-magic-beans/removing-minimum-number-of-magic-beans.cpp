class Solution {
public:
    long long minimumRemoval(vector<int>& a) {
        sort ( a.begin() , a.end() ) ;
        long long ans = LLONG_MAX ;

        long long t = 0 ;
        for ( int x : a ) t += x ;

        for ( int i = 0 ; i < a.size() ; i++ ) {
            long long curr = t - ((long long)a[i] * (a.size() - i)) ;
            ans = min ( ans , curr ) ;
        }

        return ans ;
    }
};