class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        // basic simulation 
        long long sum = 0 ;
        for ( int x : a ) sum += x ;
        k = k % sum ;

        int n = a.size() ;
        for ( int i = 0 ; i < n ; i++ ) {
            if ( k < a[i] ) return i ;
            k -= a[i] ;
        }

        return 1 ;
    }
};