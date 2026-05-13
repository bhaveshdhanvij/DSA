class Solution {
public:
    long long minArraySum(vector<int>& a) {
        unordered_set<int> s ( a.begin() , a.end() ) ;
        long long ans = 0 ;
        for ( int x : a ) {
            int b = x ;
            for ( int d = 1 ; d * d <= x ; d++ ) {
                if ( x % d == 0 ) {
                    if ( s.count(d) ) {
                        b = min ( b , d ) ;
                    }

                    int t = x / d ;
                    if ( s.count(t) ) {
                        b = min ( b , t ) ;
                    }
                }
            }
            ans += b ;
        }
        return ans ;
    }
};